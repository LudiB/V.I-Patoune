#include "vi_empreintes.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VI_Empreintes w;
	w.show();
	return a.exec();
}
