#include "vi_empreintes.h"

VI_Empreintes::VI_Empreintes(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
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

	//Inferface seuillage
	ui.SeuilTitle -> hide();
	ui.MinLab -> hide();
	ui.MinSlid -> hide();
	ui.MaxLab -> hide();
	ui.MaxSlid -> hide();

	//Bouton
	ui.BtnTrait -> hide();

	//Réinitialisation des Sliders
	ui.MinSlid -> setValue(0);
	ui.MaxSlid -> setValue(255);

	//Images
	ui.TransLabel -> hide();
	ui.AnimaLabel -> hide();
}

void VI_Empreintes::CreateDataBase()
{
	QString DataRep_1 = "..\\Resources\\DataBaseTrack\\Blaireau.png";
	QString DataRep_2 = "..\\Resources\\DataBaseTrack\\Chamois.png";
	QString DataRep_3 = "..\\Resources\\DataBaseTrack\\Chat.png";
	QString DataRep_4 = "..\\Resources\\DataBaseTrack\\Chien.png";
	QString DataRep_5 = "..\\Resources\\DataBaseTrack\\Fouine.png";
	QString DataRep_6 = "..\\Resources\\DataBaseTrack\\Genette.png";
	QString DataRep_7 = "..\\Resources\\DataBaseTrack\\Hermine.png";
	QString DataRep_8 = "..\\Resources\\DataBaseTrack\\Humain.png";
	QString DataRep_9 = "..\\Resources\\DataBaseTrack\\Loup.png";
	QString DataRep_10 = "..\\Resources\\DataBaseTrack\\Loutre.png";
	QString DataRep_11 = "..\\Resources\\DataBaseTrack\\Lynx.png";
	QString DataRep_12 = "..\\Resources\\DataBaseTrack\\Renard.png";
	QString DataRep_13 = "..\\Resources\\DataBaseTrack\\Sanglier.png";

	trackList << DataRep_1 << DataRep_2 << DataRep_3 << DataRep_4 << DataRep_5 << DataRep_6;
	trackList << DataRep_7 << DataRep_8 << DataRep_9 << DataRep_10 << DataRep_11 << DataRep_12 << DataRep_13;
}

void VI_Empreintes::DBResearch()
{
	//Note : La chat déconne 

	ui.AniLabel -> show();
	//Constitution du tableau
	for( int i = 0; i < trackList.length(); i++ )
	{
		QImage *Src = new QImage(trackList[i]);

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

	AnImg = new QImage(trackList[ind]);
	repaint();
}

void VI_Empreintes::Open()
{
	QString ImgRep =  QFileDialog::getOpenFileName(this, tr("Choisir une empreinte"), MyRep + "\\Empreintes", tr("Tout fichier (*.*);;JPG (*.jpg);;PNG (*.png);;BMP (*.bmp)"));

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

		ui.OriginaLabel -> setPixmap( *pixmap );
	}

	if (TrfImg != NULL )
	{
		*trpixmap = QPixmap::fromImage(*TrfImg);

		ui.TransLabel -> setPixmap( *trpixmap );
	}

	if(AnImg != NULL)
	{
		*anipixmap = QPixmap::fromImage(*AnImg);

		ui.AnimaLabel -> setPixmap(*anipixmap);
	}
	
}
