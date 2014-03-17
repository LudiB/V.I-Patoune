#ifndef VI_EMPREINTES_H
#define VI_EMPREINTES_H

#include <QtGui/QMainWindow>
#include "ui_vi_empreintes.h"

#include "QXImage.h"

#include <QStringList>
#include <QFileDialog>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QFile>



class VI_Empreintes : public QMainWindow
{
	Q_OBJECT

public:
	VI_Empreintes(QWidget *parent = 0, Qt::WFlags flags = 0);
	~VI_Empreintes();

private:
	Ui::VI_EmpreintesClass ui;

	/*-- Membres --*/

	QString MyRep;

	QImage* Image;
	QImage* TrfImg;
	QImage* AnImg;

	QXImage* CurIm;

	QPixmap* pixmap;
	QPixmap* trpixmap;
	QPixmap* anipixmap;

	QStringList trackList;

	int *similarityTab;

	/*-- Methodes --*/

	void Make_Connect();
	void Init();
	void Hide();

	void CreateDataBase();
	void ShowResult(int ind);
	

	void paintEvent(QPaintEvent * evt);

	/*-- Slots --*/
	private slots:
		void Open();
		void StartThres();
		void Thresh();
		void DBResearch();
};

#endif // VI_EMPREINTES_H
