#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_sturdyspork.h"

class sturdyspork : public QMainWindow
{
	Q_OBJECT

public:
	sturdyspork(QWidget *parent = Q_NULLPTR);

private:
	Ui::sturdysporkClass ui;
};
