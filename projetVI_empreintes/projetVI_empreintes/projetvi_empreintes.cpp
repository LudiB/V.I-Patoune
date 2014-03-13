#include "projetvi_empreintes.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qpainter.h>
#include "qximage.h"

projetVI_empreintes::projetVI_empreintes(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	ui.Threshold->hide();
	ui.thresholdSlider->hide();

	QObject::connect(ui.actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvertureImage()));
	QObject::connect(ui.actionFermer, SIGNAL(triggered()), this, SLOT(fermetureImage()));
	QObject::connect(ui.actionThreshold, SIGNAL(triggered()), this, SLOT(affichageSeuillage()));
}

projetVI_empreintes::~projetVI_empreintes()
{

}

void projetVI_empreintes::paintEvent(QPaintEvent* Evt)
{
	QPainter P(this);
	int h = this->height();
	int w = this->width();
	ui.qximage->setGeometry(0,0,w,h);
}

//////////////////////////////////SLOTS/////////////////////////////////////
void projetVI_empreintes:: ouvertureImage() 
{
	ui.qximage->OuvrirImage();
}

void projetVI_empreintes:: fermetureImage() 
{
	ui.qximage->FermetureImage();
}

void projetVI_empreintes:: affichageSeuillage()
{
	if(ui.Threshold->isVisible())
	{
		ui.Threshold->hide();
		ui.thresholdSlider->hide();
	}
	else
	{
		ui.Threshold->show();
		ui.thresholdSlider->show();
	}
}
