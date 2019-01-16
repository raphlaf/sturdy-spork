#include "sturdyspork.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	sturdyspork w;
	w.show();
	return a.exec();
}
