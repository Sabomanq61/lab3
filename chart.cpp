#include "chart.h"
#include "chart_drawing.h"


Chart::Chart()
: chart_( new QChart()), isColored_ (true)
{}

QChart* Chart::getChart() const
{
    return chart_;
}

void Chart::updateData(const QString& filePath)
{
    // получаем реализацию парсера данных
    // обновляем данные
    data_ = getDataParser()->parseSource(filePath);

    if (data_.isEmpty())
    {
        QMessageBox messageBox;
        messageBox.setText("Файл пустой");
        messageBox.exec();
        return;
    }

    reDrawChart();
}

void Chart::reDrawChart() const
{
    /// получаем из ioc реализацию
    getChartDrawing()->drawChart(data_,isColored_,chart_);
}

void Chart::changeColor()
{
    if(isColored_ == true)
    {
        isColored_ = false;
    }
    else
    {
        isColored_ = true;
    }
}
