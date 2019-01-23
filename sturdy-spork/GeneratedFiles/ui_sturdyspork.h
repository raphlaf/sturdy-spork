/********************************************************************************
** Form generated from reading UI file 'sturdyspork.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STURDYSPORK_H
#define UI_STURDYSPORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sturdysporkClass
{
public:
    QAction *actionImage;
    QAction *actionDonn_es;
    QAction *actionDonn_es_2;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *imageLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *controlLayout;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuSauvegarder;
    QMenu *menuCharger;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *sturdysporkClass)
    {
        if (sturdysporkClass->objectName().isEmpty())
            sturdysporkClass->setObjectName(QString::fromUtf8("sturdysporkClass"));
        sturdysporkClass->resize(1600, 900);
        actionImage = new QAction(sturdysporkClass);
        actionImage->setObjectName(QString::fromUtf8("actionImage"));
        actionDonn_es = new QAction(sturdysporkClass);
        actionDonn_es->setObjectName(QString::fromUtf8("actionDonn_es"));
        actionDonn_es_2 = new QAction(sturdysporkClass);
        actionDonn_es_2->setObjectName(QString::fromUtf8("actionDonn_es_2"));
        centralWidget = new QWidget(sturdysporkClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imageLayout = new QVBoxLayout();
        imageLayout->setSpacing(6);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        imageLayout->addWidget(graphicsView);


        horizontalLayout->addLayout(imageLayout);

        controlLayout = new QVBoxLayout();
        controlLayout->setSpacing(6);
        controlLayout->setObjectName(QString::fromUtf8("controlLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        controlLayout->addWidget(pushButton);


        horizontalLayout->addLayout(controlLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        sturdysporkClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(sturdysporkClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuSauvegarder = new QMenu(menuFichier);
        menuSauvegarder->setObjectName(QString::fromUtf8("menuSauvegarder"));
        menuCharger = new QMenu(menuFichier);
        menuCharger->setObjectName(QString::fromUtf8("menuCharger"));
        sturdysporkClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(sturdysporkClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        sturdysporkClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(sturdysporkClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        sturdysporkClass->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(menuSauvegarder->menuAction());
        menuFichier->addAction(menuCharger->menuAction());
        menuSauvegarder->addAction(actionImage);
        menuSauvegarder->addAction(actionDonn_es);
        menuCharger->addAction(actionDonn_es_2);

        retranslateUi(sturdysporkClass);

        QMetaObject::connectSlotsByName(sturdysporkClass);
    } // setupUi

    void retranslateUi(QMainWindow *sturdysporkClass)
    {
        sturdysporkClass->setWindowTitle(QApplication::translate("sturdysporkClass", "Sturdy Spork", nullptr));
        actionImage->setText(QApplication::translate("sturdysporkClass", "Image", nullptr));
        actionDonn_es->setText(QApplication::translate("sturdysporkClass", "Donn\303\251es", nullptr));
        actionDonn_es_2->setText(QApplication::translate("sturdysporkClass", "Donn\303\251es", nullptr));
        pushButton->setText(QApplication::translate("sturdysporkClass", "PushButton", nullptr));
        menuFichier->setTitle(QApplication::translate("sturdysporkClass", "Fichier", nullptr));
        menuSauvegarder->setTitle(QApplication::translate("sturdysporkClass", "Sauvegarder...", nullptr));
        menuCharger->setTitle(QApplication::translate("sturdysporkClass", "Charger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sturdysporkClass: public Ui_sturdysporkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STURDYSPORK_H
