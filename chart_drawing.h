#pragma once
#ifndef CHART_DRAWING_H
#define CHART_DRAWING_H

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <QJsonDocument>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts>
#include "i_chart_drawing.h"
#include "i_data_parser.h"
#include "ioc_container.h"

/// @brief Реализация вертикальных графиков
class BarChartDrawing : public IChartDrawing
{
public:
    /// @brief Прорисовывание графика
    /// @param data - данные
    /// @param isColored - цветной/(темно-серый)
    /// @param QChart - класс для работы с графиком
    virtual void drawChart(Data data, bool isColored = true, QChart* chart_= new QChart()) override;
};

/// @brief Реализация круговых графиков
class PieChartDrawing : public IChartDrawing
{
public:
    /// @brief Прорисовывание графика
    /// @param data - данные
    /// @param isColored - цветной/(темно-серый)
    /// @param QChart - класс для работы с графиком
    virtual void drawChart(Data data, bool isColored = true, QChart* chart_= new QChart()) override;
};

/// @brief enum содержит тип графиков
enum class ChartType: uint8_t
{
    bar = 0,
    pie
};

/// @brief установка типа рисования диаграммы
/// @param ChartType - тип диаграмм
void setChartDrawing(ChartType type);

#endif // CHART_DRAWING_H
