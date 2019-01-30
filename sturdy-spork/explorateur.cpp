#include "explorateur.h"


explorateur::explorateur(double x_debut_v, double y_debut_v, double x_fin_v, double y_fin_v, int largeur_v, int hauteur_v, int nombre_iter_max_v, bool utiliser_opencl_v) :
	x_debut(x_debut_v), y_debut(y_debut_v), x_fin(x_fin_v), y_fin(y_fin_v), hauteur(hauteur_v), largeur(largeur_v), nombre_iter_max(nombre_iter_max_v), utiliser_opencl(utiliser_opencl_v)
{
	int N = hauteur * largeur;
	image_courante = new int[N];
	std::cout << hauteur_v << ", " << largeur_v << std::endl;



	cl::Platform::get(&platformes);
	_ASSERT(platformes.size() > 0);
	platforme_courante = platformes.front();
	platforme_courante.getDevices(CL_DEVICE_TYPE_GPU, &devices);
	_ASSERT(devices.size() > 0);
	device_utilise = devices.front();

	std::ifstream kernelFile("mandelbrot.cl");
	std::string src(std::istreambuf_iterator<char>(kernelFile), (std::istreambuf_iterator<char>()));

	sources = cl::Program::Sources(1, std::make_pair(src.c_str(), src.length() + 1));

	contexte = cl::Context(device_utilise);

	programme = cl::Program(contexte, sources);

	auto err = programme.build("-cl-std=CL1.2");

	std::string log = programme.getBuildInfo<CL_PROGRAM_BUILD_LOG>(device_utilise, &err);

	std::cout << "Build code : " << err << "\nLog : " << log << std::endl;
	kernel = cl::Kernel(programme, "mandelbrot", &err);

}

explorateur::~explorateur()
{
	delete image_courante;
}

void explorateur::calcul_image()
{
	int N = largeur * hauteur;

	delete[] image_courante;
	image_courante = new int[N];

	double* x_data = new double[largeur];
	double* y_data = new double[hauteur];
	for (int i = 0; i < largeur; i++)
	{
		x_data[i] = (x_fin - x_debut)*double(i) / double(largeur) + x_debut;
	}
	for (int i = 0; i < hauteur; i++)
	{
		y_data[i] = (y_fin - y_debut)*double(i) / double(hauteur) + y_debut;
	}
	if (utiliser_opencl)
	{
		std::cout << "YES" << std::endl;
		int* height_data = new int[1];
		height_data[0] = hauteur;

		int* max_iter_data = new int[1];
		max_iter_data[0] = nombre_iter_max;

		int* count_data = new int[N];

		for (int i = 0; i < largeur*hauteur; i++)
			count_data[i] = 0;

		cl::Buffer x_data_buf(contexte, CL_MEM_READ_ONLY, sizeof(double)*largeur);
		cl::Buffer y_data_buf(contexte, CL_MEM_READ_ONLY, sizeof(double)*hauteur);
		cl::Buffer height_buf(contexte, CL_MEM_READ_ONLY, sizeof(int));
		cl::Buffer max_iter_buf(contexte, CL_MEM_READ_ONLY, sizeof(int));
		cl::Buffer count_buf(contexte, CL_MEM_READ_WRITE, sizeof(int)*hauteur*largeur);

		kernel.setArg(0, x_data_buf);
		kernel.setArg(1, y_data_buf);
		kernel.setArg(2, height_buf);
		kernel.setArg(3, max_iter_buf);
		kernel.setArg(4, count_buf);

		cl::NDRange global_range(N);


		std::cout << count_data[0] << std::endl;

		cl::CommandQueue queue(contexte, device_utilise);
		queue.enqueueWriteBuffer(x_data_buf, CL_TRUE, 0, sizeof(double)*largeur, x_data);
		queue.enqueueWriteBuffer(y_data_buf, CL_TRUE, 0, sizeof(double)*hauteur, y_data);
		queue.enqueueWriteBuffer(height_buf, CL_TRUE, 0, sizeof(int), height_data);
		queue.enqueueWriteBuffer(max_iter_buf, CL_TRUE, 0, sizeof(int), max_iter_data);
		//queue.enqueueWriteBuffer(count_buf, CL_TRUE, 0, sizeof(int)*largeur*hauteur, count_data);
		queue.enqueueNDRangeKernel(kernel, NULL, global_range);
		queue.enqueueReadBuffer(count_buf, CL_TRUE, 0, sizeof(int)*hauteur*largeur, image_courante);

		//for (int i = 0; i < largeur*hauteur; i++)
		//	if (image_courante[i] > 0)
		//		std::cout << image_courante[i] << std::endl;


		delete[] x_data, y_data, height_data, max_iter_data;
	}
	else
	{
		for (int i = 0; i < largeur; i++)
		{
			for (int j = 0; j < hauteur; j++)
			{
				double cx = x_data[i];
				double cy = y_data[j];
				double x = cx;
				double y = cy;
				int iter = 0;
				while (x * x + y * y < 4.0f && iter < nombre_iter_max)
				{
					double new_x = x * x - y * y + cx;
					y = 2 * x * y + cy;
					x = new_x;
					iter++;
				}
				int n = i * hauteur + j;
				if (iter == nombre_iter_max)
					iter = 0;
				image_courante[n] = iter;
				if ((n / hauteur) != i || (n - (n / hauteur) * hauteur) != j)
					std::cout << "OH WAIT" << std::endl;
			}
		}
	}

	
}

std::string explorateur::device_info()
{
	return device_utilise.getInfo<CL_DEVICE_VERSION>();
}



int* explorateur::prendre_image()
{
	return image_courante;
}