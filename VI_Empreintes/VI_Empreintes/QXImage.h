#pragma once
#include "qimage.h"


class QXImage : public QImage
{
public:
	QXImage(void);
	QXImage(QImage *Image);
	~QXImage(void);

	// - - Methode Publique - -

	//Image en Noir et Blanc
	QXImage toGrayScale ( bool keepAlpha =  true );

	//Seuillage de l'image
	void Threshold ( int Min, int Max );
};

