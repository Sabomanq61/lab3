#include "chart_drawing.h"
#include "i_data_parser.h"
#include "ioc_container.h"


void BarChartDrawing::drawChart(Data data, bool isColored, QChart* chart_)
{
    chart_->setTitle("Bar chart");

    QBarSeries *series = new QBarSeries{chart_};

    int i = 0;
    int j = 0;
    for (element elem : data) // Идём по каждому элементу
    {
        QString legendHeader = elem.first; // Записываем Ключ
        QBarSet *set = new QBarSet(legendHeader); // Задаём набор данных для 1 вертикальной диаграммы
        if (!isColored) // Отрисовка цвета
        {
            set->setColor(QColor(j,j,j));
            j+=20;
        }
        *set << elem.second; // Добавляем в набор значение
        series->append(set); // Добавлеяем набор в серию
        i++;
    }

    chart_->removeAllSeries(); // Очищаем предыдущие серии
    chart_->addSeries(series); // Добавляем серию в Диаграмму
    chart_->setAnimationOptions(QChart::SeriesAnimations); // Красивая анимация
    chart_->createDefaultAxes(); // Устанавливаем стандартные оси
}

void PieChartDrawing::drawChart(Data data, bool isColored, QChart* chart_)
{
    chart_->setTitle("Pie chart");

    QPieSeries *series = new QPieSeries{chart_}; // Задаём серии данных для Круговой диаграммы

    int i = 0; // Переменная для подсчёта кол-ва считываемых данных из базы
    int j = 0; // Переменная для чб цвет
    for(element elem : data) // Идём по каждому элементу
    {
        QString legendHeader  = elem.first; // Записываем Ключ
        series->append(legendHeader, elem.second); // Добавлеяем ключ и значение в серию
        if (!isColored) // Отрисовка цвета
        {
            series->slices().at(i)->setColor(QColor(j,j,j));
            j+=25;
        }
        i++;
    }

    chart_->removeAllSeries(); // удаляем пред. графики
    chart_->addSeries(series); // добавляем серию в Диаграмму
    chart_->setAnimationOptions(QChart::SeriesAnimations);
    chart_->createDefaultAxes();
}

std::shared_ptr<IChartDrawing> getChartDrawing()
{
    return IOCContainer::instance().GetObject<IChartDrawing>();
}

void setChartDrawing(ChartType type)
{
    switch (type)
       {
           case ChartType::bar :
               IOCContainer::instance().RegisterInstance<IChartDrawing, BarChartDrawing>();
               break;
           case ChartType::pie :
               IOCContainer::instance().RegisterInstance<IChartDrawing, PieChartDrawing>();
               break;
       }
}
