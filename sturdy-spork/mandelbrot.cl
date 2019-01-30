__kernel void mandelbrot(__global double* x_data, __global double* y_data, __global int* height, __global int* max_iter, __global int* count)
{
	int id = get_global_id(0);
	int i = id / height[0];
	int j = id - i*height[0];
	double cx = x_data[i];
	double cy = y_data[j];
	double x = cx;
	double y = cy;
	int iter = 0;
	while (x * x + y * y < 4.0f && iter < max_iter[0])
	{
		double new_x = x * x - y * y + cx;
		y = 2 * x * y + cy;
		x = new_x;
		iter++;
	}
	if (iter == max_iter[0])
		iter = 0;
	count[id] = iter;
}