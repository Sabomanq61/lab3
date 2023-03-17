#pragma once
#ifndef I_CHART_DRAWING_H
#define I_CHART_DRAWING_H

#include <QtCharts>

#include "i_data_parser.h"
#include "memory"

/// @brief Интерфейс рисования графиков
class IChartDrawing
{
public:
    /// @brief Прорисовывание графика
    /// @param data - данные
    /// @param isColored - цветной/(темно-серый)
    /// @param QChart - класс для работы с диаграммой
    virtual void drawChart(Data data, bool isColored = true, QChart* chart_ = new QChart()) = 0;
};

/// @brief получение интерфейса рисования диаграммы
std::shared_ptr<IChartDrawing> getChartDrawing();

#endif
