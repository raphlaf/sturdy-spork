#include "sturdyspork.h"

sturdyspork::sturdyspork(int resolution_x, int resolution_y, int nombre_iter_max, QWidget *parent)
	: resolution_x(resolution_x), resolution_y(resolution_y), QMainWindow(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.graphicsView->setScene(scene);
	pmap = new QPixmap(QSize(resolution_x, resolution_y));
	pmap->fill(Qt::black);
	scene->addPixmap(*pmap);
	exp = new explorateur(-2.0, -2.0, 2.0, 2.0, resolution_x, resolution_y, nombre_iter_max, true);

	
	connect(ui.pushButton, SIGNAL(released()), this, SLOT(handleButton()));
}

sturdyspork::~sturdyspork()
{
	delete scene, pmap, exp;
}


void sturdyspork::handleButton()
{
	auto start = std::chrono::high_resolution_clock::now();
	exp->calcul_image();
	int width = exp->get_width();
	int height = exp->get_height();
	int* image = exp->prendre_image();
	int max_iter = exp->get_max_iter();

	QImage im = QImage(QSize(width, height), QImage::Format::Format_ARGB32);
	im.fill(Qt::white);
	
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int c = double(image[i*height + j])/double(max_iter)*255.0;
			if (c > 255)
				std::cout << c << std::endl;
			im.setPixelColor(i, j, QColor(c, c, c));
		}
	}
	pmap->convertFromImage(im);
	scene->addPixmap(*pmap);
	auto finish = std::chrono::high_resolution_clock::now();
	auto t = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
	std::cout << "Le calcul a ete fait en " << t << "ns. Il peut donc être fait " << 1000000000.0 / double(t) << " fois par secondes.\n";
}