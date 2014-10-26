#include "sampleplot.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SamplePlot w;
	w.show();
	return a.exec();
}
