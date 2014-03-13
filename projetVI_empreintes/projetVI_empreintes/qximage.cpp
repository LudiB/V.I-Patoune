#include "qximage.h"
#include <qpainter.h>

QXImage::QXImage(QWidget *parent,Qt::WFlags flags )
	: QWidget(parent, flags)
	, Image(NULL)
	, pixmap(NULL)
{
	imageLabel = new QLabel;
}

QXImage::~QXImage()
{

}

void QXImage::OuvrirImage()
{
	QString MonRep = "../images";
	QString Filename = QFileDialog::getOpenFileName(this, tr("Open File"), MonRep, "Image (*.bmp *.jpg *.png)");
	AfficheImage(Filename);
	update();
}

void QXImage::FermetureImage()
{
	Image=NULL;
	update();
}

void QXImage::AfficheImage(QString img)
{
	Image = new QImage(img);
}

void QXImage::paintEvent(QPaintEvent* Evt)
{
	QPainter P(this);

	if (Image!= NULL)
	{
		P.drawImage(QPoint(0,0), *Image);
	}
}