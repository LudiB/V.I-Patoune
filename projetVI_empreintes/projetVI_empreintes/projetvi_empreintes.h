#ifndef PROJETVI_EMPREINTES_H
#define PROJETVI_EMPREINTES_H

#include <QtGui/QMainWindow>
#include "ui_projetvi_empreintes.h"

class projetVI_empreintes : public QMainWindow
{
	Q_OBJECT

public:
	projetVI_empreintes(QWidget *parent = 0, Qt::WFlags flags = 0);
	~projetVI_empreintes();

	void afficherImage(QString img);
	void paintEvent(QPaintEvent* Evt);

private slots:
	void ouvertureImage();
	void fermetureImage();
	void affichageSeuillage();

private:
	Ui::projetVI_empreintesClass ui;
	QImage* Image;
};

#endif // PROJETVI_EMPREINTES_H
