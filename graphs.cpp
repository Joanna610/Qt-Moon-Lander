#include "graphs.h"

/*!
* Inicjalizuje wszystkie osie, to jakie będą miały kolory oraz ich przedziały
*/
graphs::graphs(QChartView *chartView)
{
    series =new QLineSeries();

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setBackgroundBrush(QBrush(QColor(0, 0, 5)));

    // osie
    axisX = new QValueAxis();
    axisX->setRange(0, 100);
    axisX->setLabelFormat("%i");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setRange(-1500, 1500);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QBrush axisBrush(QColor(64, 64, 64));
    axisX->setLabelsBrush(axisBrush);
    axisX->setLinePenColor(QColor(204, 224, 255));
    axisX->setGridLineColor(QColor(204, 224, 255));

    axisY->setLabelsBrush(axisBrush);
    axisY->setLinePenColor(QColor(204, 224, 255));
    axisY->setGridLineColor(QColor(204, 224, 255));

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setVisible(true);
    time = 0;
}

/*!
* Wyrysowuje dany wykres i jeśli przekracza maksymalny czas
* to wtedy wykres jest przesuwany o 100
*/
void graphs::drawData(int data){
    series->append(time,data);
    if (time > axisX->max()) {
        axisX->setRange(axisX->min(), axisX->max() + 100);
    }
    time++;

}

graphs::~graphs(){
    delete series;
    delete chart;
}
