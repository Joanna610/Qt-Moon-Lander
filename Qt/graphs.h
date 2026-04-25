#ifndef GRAPHS_H
#define GRAPHS_H

/*!
* \file
* \brief Definicja klasy Graphs
*
* Plik zawiera definicję klasy Graphs, która
* przedstawie wykresy z danymi
*/

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QT_USE_NAMESPACE

class graphs
{

    QLineSeries *series;
    QChart *chart;

    int time;
    /*!
     * \brief Oś pozioma
     */
    QValueAxis *axisX;
    /*!
     * \brief Oś pionowa
     */
    QValueAxis *axisY;
public:
    /*!
     * \brief Konstruktor inicjalizujący wykresy
     */
    graphs(QChartView *chartView);
    ~graphs();

    /*!
     * \brief Funkcja aktualizująca wczytane dane na wykresach
     */
    void drawData(int data);

};

#endif // GRAPHS_H
