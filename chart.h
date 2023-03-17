#pragma once
#ifndef CHART_H
#define CHART_H

#include "i_data_parser.h"
#include "ioc_container.h"
#include "chart_drawing.h"

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <QJsonDocument>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts>


/// @brief Класс для работы с диаграммами
class Chart
{
public:
    /// @brief Constructor
    Chart();

    /// @brief Получение QChart
    /// @return QChart
    QChart* getChart() const;

    /// @brief Обновляем данные
    void updateData(const QString& filePath);

    /// @brief Перерисовываем диаграмму
    void reDrawChart() const;

    /// @brief Смена цвета
    void changeColor();

private:
    QChart *chart_;
    Data data_; // данные для отображения в виде диаграммы
    bool isColored_; // Переменная определяющая цвет Диаграммы
};

#endif // CHART_H
