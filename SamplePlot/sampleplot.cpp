#include "sampleplot.h"

#include <math.h>
#include <functional>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>
#include <string>


float MIN_X = std::numeric_limits<float>::max();
float MAX_X = std::numeric_limits<float>::min();
float MIN_Y = std::numeric_limits<float>::max();
float MAX_Y = std::numeric_limits<float>::min();



float quadraticFunction(float x)
{
	return x*x;
}

float linearFunction(float x)
{
	return x;
}

float logarithmicFunction(float x)
{
	return log2(x);
}

QVector<double> getValues(std::vector<double> samples, const std::function<float (float)>& f)
{
	QVector<double> values;

	for(auto n : samples)
		values.push_back(f(n));

	return values;
}

void plot(QCustomPlot* customPlot, std::vector<double> samples, const std::string& name, const std::function<float (float)>& f, 
		  QColor color, int width, Qt::PenStyle penstyle)
{
	static int graphIndex = 0;

	auto y = getValues(samples, f);
	customPlot->addGraph();

	// do a log-log plot
	std::transform(y.begin(), y.end(), y.begin(), [](double e)
	{
		return log2(e);
	});

	std::vector<double> logSamples(samples.size());
	std::transform(samples.begin(), samples.end(), logSamples.begin(), [](double e)
	{
		return log2(e);
	});

	auto currentGraph = customPlot->graph(graphIndex);
	currentGraph->setData( QVector<double>::fromStdVector(logSamples), y);
	currentGraph->setPen(QPen(QColor(0, 0, 250, 50)));
	currentGraph->setName(name.c_str());

	QPen blueDotPen;
	blueDotPen.setColor(color);
	blueDotPen.setStyle(penstyle);
	blueDotPen.setWidthF(width);
	currentGraph->setPen(blueDotPen);


	MIN_X = std::min(MIN_X, static_cast<float>(*std::min_element(logSamples.begin(), logSamples.end())));
	MAX_X = std::max(MAX_X, static_cast<float>(*std::max_element(logSamples.begin(), logSamples.end())));
	MIN_Y = std::min(MIN_Y, static_cast<float>(*std::min_element(y.begin(), y.end())));
	MAX_Y = std::max(MAX_Y, static_cast<float>(*std::max_element(y.begin(), y.end())));

	graphIndex++;
}



SamplePlot::SamplePlot(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	std::vector<double> samples{10, 100, 1000, 2000, 4000, 8000};

	plot(ui.customPlot, samples, "logarithmic", [](float x) { return log2(x); }, QColor(30, 40, 255, 30), 4, Qt::DotLine);
	plot(ui.customPlot, samples, "linear", [](float x) { return x; }, QColor(30, 40, 255, 30), 4, Qt::DotLine);
	plot(ui.customPlot, samples, "xLog", [](float x) { return x * log2(x); }, QColor(30, 40, 255, 30), 4, Qt::DotLine);
	plot(ui.customPlot, samples, "quadratic", [](float x) { return x * x; }, QColor(30, 40, 255, 30), 4, Qt::DotLine);
	plot(ui.customPlot, samples, "cubic", [](float x) { return x * x * x; }, QColor(30, 40, 255, 30), 4, Qt::DotLine);

	plot(ui.customPlot, samples, "QU", [](float x) { return 10 * x + x * x; }, QColor(255, 40, 0, 255), 1, Qt::SolidLine);
	plot(ui.customPlot, samples, "QF", [](float x) { return 10 * x + 5 * x * x; }, QColor(0, 40, 100, 255), 1, Qt::SolidLine);
	plot(ui.customPlot, samples, "WQU", [](float x) { return 10 * x + 15 * x; }, QColor(0, 100, 0, 255), 1, Qt::SolidLine);
	plot(ui.customPlot, samples, "WQUPC", [](float x) { return 10 * log2(x); }, QColor(255, 0, 255, 255), 1, Qt::SolidLine);


	// give the axes some labels:
	ui.customPlot->xAxis->setLabel("log(N)");
	ui.customPlot->yAxis->setLabel("log2(T(N))");
	ui.customPlot->legend->setVisible(true);

	// set axes ranges, so we see all data:
	ui.customPlot->xAxis->setRange(MIN_X, MAX_X);
	ui.customPlot->yAxis->setRange(MIN_Y, MAX_Y);

	
	ui.customPlot->replot();
}

SamplePlot::~SamplePlot()
{

}
