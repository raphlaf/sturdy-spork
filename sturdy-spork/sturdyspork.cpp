#include "sturdyspork.h"

sturdyspork::sturdyspork(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	scene = new QGraphicsScene(this);
	ui.graphicsView->setScene(scene);
	pmap = new QPixmap(QSize(500, 500));
	pmap->fill(Qt::black);
	scene->addPixmap(*pmap);
	
	
}

sturdyspork::~sturdyspork()
{
	delete scene, pmap;
}