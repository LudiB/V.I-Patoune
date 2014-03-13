#include "projetvi_empreintes.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	projetVI_empreintes w;
	w.show();
	return a.exec();
}
