#ifndef SAMPLEPLOT_H
#define SAMPLEPLOT_H

#include <QtWidgets/QMainWindow>
#include "ui_sampleplot.h"

class SamplePlot : public QMainWindow
{
	Q_OBJECT

	public:
		SamplePlot(QWidget* parent = nullptr);
		~SamplePlot();

	private:
		Ui::SamplePlotClass ui;
};

#endif // SAMPLEPLOT_H
