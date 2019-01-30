#pragma once

#include <chrono>
#include <QtWidgets/QMainWindow>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "ui_sturdyspork.h"
#include "explorateur.h"


class sturdyspork : public QMainWindow
{
	Q_OBJECT

public:
	sturdyspork(int resolution_x = 500, int resolution_y = 500, int nombre_iter_max = 1000,  QWidget *parent = Q_NULLPTR);
	~sturdyspork();

private slots:
	void handleButton();

private:
	Ui::sturdysporkClass ui;
	QGraphicsScene* scene;
	QImage im;
	QPixmap* pmap;
	explorateur* exp;
	int resolution_x, resolution_y;
};
