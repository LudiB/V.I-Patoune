/********************************************************************************
** Form generated from reading UI file 'projetvi_empreintes.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJETVI_EMPREINTES_H
#define UI_PROJETVI_EMPREINTES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <qximage.h>

QT_BEGIN_NAMESPACE

class Ui_projetVI_empreintesClass
{
public:
    QAction *actionOuvrir;
    QAction *actionFermer;
    QAction *actionThreshold;
    QWidget *centralWidget;
	QXImage *qximage;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *Threshold;
    QSlider *thresholdSlider;
    QWidget *imageWidget;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *projetVI_empreintesClass)
    {
        if (projetVI_empreintesClass->objectName().isEmpty())
            projetVI_empreintesClass->setObjectName(QString::fromUtf8("projetVI_empreintesClass"));
        projetVI_empreintesClass->resize(600, 400);
        actionOuvrir = new QAction(projetVI_empreintesClass);
        actionOuvrir->setObjectName(QString::fromUtf8("actionOuvrir"));
        actionFermer = new QAction(projetVI_empreintesClass);
        actionFermer->setObjectName(QString::fromUtf8("actionFermer"));
        actionThreshold = new QAction(projetVI_empreintesClass);
        actionThreshold->setObjectName(QString::fromUtf8("actionThreshold"));
        centralWidget = new QWidget(projetVI_empreintesClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
		qximage = new QXImage(centralWidget);
        qximage->setObjectName(QString::fromUtf8("qximage"));
        qximage->setGeometry(QRect(9, 9, 400, 400));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, -1, 591, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        Threshold = new QLabel(widget);
        Threshold->setObjectName(QString::fromUtf8("Threshold"));
        Threshold->setGeometry(QRect(260, 240, 51, 20));
        thresholdSlider = new QSlider(widget);
        thresholdSlider->setObjectName(QString::fromUtf8("thresholdSlider"));
        thresholdSlider->setGeometry(QRect(99, 280, 361, 20));
        thresholdSlider->setOrientation(Qt::Horizontal);
        imageWidget = new QWidget(widget);
        imageWidget->setObjectName(QString::fromUtf8("imageWidget"));
        imageWidget->setGeometry(QRect(10, 10, 571, 211));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        projetVI_empreintesClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(projetVI_empreintesClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        projetVI_empreintesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(projetVI_empreintesClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        projetVI_empreintesClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(projetVI_empreintesClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        projetVI_empreintesClass->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionFermer);
        menuOptions->addAction(actionThreshold);

        retranslateUi(projetVI_empreintesClass);

        QMetaObject::connectSlotsByName(projetVI_empreintesClass);
    } // setupUi

    void retranslateUi(QMainWindow *projetVI_empreintesClass)
    {
        projetVI_empreintesClass->setWindowTitle(QApplication::translate("projetVI_empreintesClass", "projetVI_empreintes", 0, QApplication::UnicodeUTF8));
        actionOuvrir->setText(QApplication::translate("projetVI_empreintesClass", "Ouvrir...", 0, QApplication::UnicodeUTF8));
        actionFermer->setText(QApplication::translate("projetVI_empreintesClass", "Fermer", 0, QApplication::UnicodeUTF8));
        actionThreshold->setText(QApplication::translate("projetVI_empreintesClass", "Seuillage", 0, QApplication::UnicodeUTF8));
        Threshold->setText(QApplication::translate("projetVI_empreintesClass", "Seuillage", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("projetVI_empreintesClass", "Fichier", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("projetVI_empreintesClass", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class projetVI_empreintesClass: public Ui_projetVI_empreintesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJETVI_EMPREINTES_H
