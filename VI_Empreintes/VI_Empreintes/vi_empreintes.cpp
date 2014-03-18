#include "vi_empreintes.h"

VI_Empreintes::VI_Empreintes(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
	, DossierSourcesNoirEtBlanc ("..\\Resources\\DataBaseTrack\\")
	, DossierSourcesImages ("..\\Resources\\DataBaseTrack\\Annimaux\\Rezize-170x200\\")
	, Extention (".png")
{
	ui.setupUi(this);

	//Définition du titre de la fenetre
	setWindowTitle("Reconnaissance d'empreintes");

	//Initialisation du répertoire
	MyRep = "..\\Resources";

	//Initalisation de données
	CreateDataBase();

	//Fonction d'initialisation des connexions
	Make_Connect();

	similarityTab = new int[13];

	Init();
}

VI_Empreintes::~VI_Empreintes()
{

}

void VI_Empreintes::Make_Connect()
{
	//Bouton du Menu "Ouvrir"
	connect(ui.actionOuvrir, SIGNAL(triggered()), this, SLOT(Open()));

	//Bouton du Menu "Rechercher"
	connect(ui.actionResearch, SIGNAL(triggered()), this, SLOT(DBResearch()));

	//Bouton de "Traitement"
	connect(ui.BtnTrait, SIGNAL(clicked()), this, SLOT(StartThres()));

	//Sliders
	connect(ui.MinSlid, SIGNAL(valueChanged(int)), this, SLOT(Thresh()));
	connect(ui.MaxSlid, SIGNAL(valueChanged(int)), this, SLOT(Thresh()));

	//Bouton de recherche dans la BD
	connect(ui.pushBaseDonner, SIGNAL(clicked()), this, SLOT(DBResearch()));
}

void VI_Empreintes::Init()
{

	Image = NULL;
	TrfImg = NULL;
	AnImg = NULL;

	pixmap = new QPixmap();
	trpixmap = new QPixmap();
	anipixmap = new QPixmap();

	//Visibilité interface
	Hide();

	if(ui.BtnTrait->isChecked() == true)
	{
		ui.BtnTrait -> setChecked(false);
	}
	
}

void VI_Empreintes::Hide()
{
	//Labels
	ui.OrigLabel -> hide();
	ui.TrsLabel -> hide();
	ui.AniLabel -> hide();
	ui.QLabelNomAnimal -> hide();

	//Inferface seuillage
	ui.SeuilTitle -> hide();
	ui.MinLab -> hide();
	ui.MinSlid -> hide();
	ui.MaxLab -> hide();
	ui.MaxSlid -> hide();

	//Bouton
	ui.BtnTrait -> hide();
	ui.pushBaseDonner -> hide();

	//Réinitialisation des Sliders
	ui.MinSlid -> setValue(0);
	ui.MaxSlid -> setValue(255);

	//Images
	ui.TransLabel -> hide();
	ui.AnimaLabel -> hide();
}

void VI_Empreintes::CreateDataBase()
{
	QString Blaireau = "Blaireau";
	QString Chamois = "Chamois";
	QString Chat = "Chat";
	QString Chien = "Chien";
	QString Fouine = "Fouine";
	QString Genette = "Genette";
	QString Hermine = "Hermine";
	QString Humain = "Humain";
	QString Loup = "Loup";
	QString Loutre = "Loutre";
	QString Lynx = "Lynx";
	QString Renard = "Renard";
	QString Sanglier = "Sanglier";

	nomList << Blaireau << Chamois << Chat << Chien << Fouine << Genette;
	nomList << Hermine << Humain << Loup << Loutre << Lynx << Renard << Sanglier;
}

void VI_Empreintes::DBResearch()
{
	//Note : La chat déconne 

	ui.AniLabel -> show();
	//Constitution du tableau
	for( int i = 0; i < nomList.length(); i++ )
	{
		QImage *Src = new QImage(DossierSourcesNoirEtBlanc + nomList[i] + Extention);

		int Similarity = 0;

		QRgb srcInts = 0;
		QRgb trsInts = 0;
		int srcVal, trsVal;

		for( int w = 0; w < TrfImg -> width(); w++)
		{
			for( int h = 0; h < TrfImg -> height(); h++)
			{
				srcInts = Src -> pixel( w, h );
				srcVal = qGray(srcInts);

				trsInts = TrfImg -> pixel( w, h );
				trsVal = qGray(trsInts);

				if( srcVal == 0 && trsVal == 0)
				{
					Similarity ++;
				}
			}
		}

		similarityTab[i] = Similarity;

	}

	//Détermination du max concordance
	int index = 0;
	int max = 0;

	for( int j = 0; j < 13; j++)
	{
		if( similarityTab[j] > max )
		{
			max = similarityTab[j];
			index = j;
		}
	}

	ShowResult(index);

}

void VI_Empreintes::ShowResult( int ind)
{
	ui.AnimaLabel -> show();
	ui.QLabelNomAnimal -> show();
	ui.QLabelNomAnimal -> setText(nomList[ind]);

	AnImg = new QImage(DossierSourcesImages + nomList[ind] + Extention);
	repaint();
}

void VI_Empreintes::Open()
{
	QString ImgRep =  QFileDialog::getOpenFileName(this, tr("Choisir une empreinte"), MyRep + "\\Empreintes", tr("Tout fichier (*.*);;JPG (*.jpg);;PNG (*.png);;BMP (*.bmp)"));

	if (ImgRep == "")
		return;

	//Libération de l'image si deja définie
	if(Image != NULL)
	{
		delete[] Image;
		delete[] TrfImg;

		Init();
	}

	//Affectation de l'image
	Image = new QImage(ImgRep);

	//Image en N&B
	QXImage *temp = new QXImage(Image);
	temp -> toGrayScale();

	CurIm = temp;

	repaint();

	//Affichage interface
	ui.OrigLabel -> show();
	ui.BtnTrait -> show();
}

void VI_Empreintes::StartThres()
{
	if(ui.BtnTrait -> isChecked() == true)
	{
		//Inferface seuillage
		ui.SeuilTitle -> show();
		ui.MinLab -> show();
		ui.MinSlid -> show();
		ui.MaxLab -> show();
		ui.MaxSlid -> show();
	}
	else
	{
		//Inferface seuillage
		ui.SeuilTitle -> hide();
		ui.MinLab -> hide();
		ui.MinSlid -> hide();
		ui.MaxLab -> hide();
		ui.MaxSlid -> hide();
	}
	

	if(ui.TransLabel -> isVisible() == false)
	{

		ui.TrsLabel -> show();
		ui.TransLabel -> show();
		ui.pushBaseDonner -> show();

	}
	//Initialisation des sliders de thesh
	Thresh();
}

void VI_Empreintes::Thresh()
{
	int min = ui.MinSlid -> value();
	int max = ui.MaxSlid -> value();

	ui.MinLab -> setText( "Minimim : " + QString::number(min));
	ui.MaxLab -> setText( "Maximum : " + QString::number(max));

	TrfImg = CurIm;

	QXImage *temp = new QXImage(TrfImg);
	temp->Threshold( min, max );

	TrfImg = temp;

	repaint();

}

void VI_Empreintes::paintEvent(QPaintEvent * evt)
{
	if (Image != NULL)
	{
		*pixmap = QPixmap::fromImage(*Image);
		ui.OriginaLabel -> setGeometry(0, 20, Image->width(), Image->height());
		ui.OriginaLabel -> setPixmap( *pixmap );
	}

	if (TrfImg != NULL )
	{
		*trpixmap = QPixmap::fromImage(*TrfImg);
		ui.TransLabel -> setGeometry(321, 20, Image->width(), Image->height());
		ui.TransLabel -> setPixmap( *trpixmap );
	}

	if(AnImg != NULL)
	{
		*anipixmap = QPixmap::fromImage(*AnImg);
		ui.AnimaLabel -> setGeometry(642, 20, Image->width(), Image->height());
		ui.AnimaLabel -> setPixmap(*anipixmap);
	}
	
}
