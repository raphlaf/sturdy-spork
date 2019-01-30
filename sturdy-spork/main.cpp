#include "sturdyspork.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	sturdyspork w(1920, 1080, 100);
	w.show();
	return a.exec();
}
