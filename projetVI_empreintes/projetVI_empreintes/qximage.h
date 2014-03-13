#ifndef QXIMAGE_H
#define QXIMAGE_H

#include <QWidget>
#include <QFileDialog>
#include <qlabel.h>

class QXImage : public QWidget
{
	Q_OBJECT

public:
	QXImage(QWidget *parent = 0, Qt::WFlags flags =0);
	~QXImage();

	void OuvrirImage();
	void AfficheImage(QString img);
	void FermetureImage();

	void paintEvent(QPaintEvent* Evt);

private:
	QImage* Image;
	QPixmap* pixmap;
	QLabel *imageLabel;
	QString nomImage;

};

#endif // QXIMAGE_H
