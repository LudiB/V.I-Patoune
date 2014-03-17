#include "QXImage.h"


QXImage::QXImage(void)
{
}

QXImage::QXImage(QImage* Image)
	:QImage(*Image)
{
	
}

QXImage::~QXImage(void)
{
}

QXImage QXImage::toGrayScale ( bool keepAlpha)
{
	QXImage *Image = this;
	QRgb col;
    int gray;
    int width = Image->width();
    int height = Image->height();

    QImage alpha = Image->alphaChannel(); // On sauvegarde le canal alpha pour la transparence

    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            col = Image->pixel(i, j);
            gray = qGray(col);
            Image->setPixel(i, j, qRgb(gray, gray, gray));
        }
    }
    Image->setAlphaChannel(alpha);

	return Image;
}

void QXImage::Threshold ( int Min, int Max )
{
	QXImage *Im = this;
	Im->toGrayScale();

	QRgb col;
    int gray;
	int Smin = Min;
	int Smax = Max;
    int width = Im->width();
    int height = Im->height();

	QImage alpha = Im->alphaChannel();

	for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            col = Im->pixel(i, j);
            gray = qGray(col);
			if(gray > Smin && gray < Smax)
			{
				gray = 0;}
			else
			{
				gray = 255;}

            Im->setPixel(i, j, qRgb(gray, gray, gray));
        }
	}
	Im->setAlphaChannel(alpha);
}