#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#if 0
    QLineSeries* line1 = new QLineSeries();
    for(double x=0;x<10;x+=0.1)
    {
        line1->append(x,sin(x));
    }
    QChart* c = new QChart();
    c->addSeries(line1);
    ui->widget->setChart(c);
#elif 0
    QLineSeries *series = new QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(chartView);
#else
    QLineSeries *series = new QLineSeries();
    series->setPen(QPen(Qt::blue,1,Qt::SolidLine));
    *series << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
            << QPointF(16, 7) << QPointF(18, 5);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple example");
    chart->setAnimationOptions(QChart::SeriesAnimations);//设置曲线呈动画显示

    QValueAxis *axisX = new QValueAxis; //定义X轴
    axisX->setRange(0, 20); //设置范围
    axisX->setLabelFormat("%g"); //设置刻度的格式
    axisX->setTitleText("X Axis"); //设置X轴的标题
    axisX->setGridLineVisible(true); //设置是否显示网格线
    axisX->setMinorTickCount(4); //设置小刻度线的数目
   // axisX->setLabelsVisible(false); //设置刻度是否显示

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 20);
    axisY->setTitleText("Y Axis");
    axisY->setLabelFormat("%.2f");
    axisY->setGridLineVisible(true);

    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
