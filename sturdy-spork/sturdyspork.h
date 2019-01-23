#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "ui_sturdyspork.h"

class sturdyspork : public QMainWindow
{
	Q_OBJECT

public:
	sturdyspork(QWidget *parent = Q_NULLPTR);
	~sturdyspork();

private:
	Ui::sturdysporkClass ui;
	QGraphicsScene* scene;
	QPixmap* pmap;
};
