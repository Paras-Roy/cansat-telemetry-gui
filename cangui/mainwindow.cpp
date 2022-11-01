#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMainWindow::showMaximized();
    ui->main_container_frame->setContentsMargins(0, 0, 0, 0);
    // ==>Start Executing Functions
    startExec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startExec()
{
    setupPlots();
    //Open CSV file with data
    QString filename = QFileDialog::getOpenFileName(this, "Open the file");

    //If file not found throw error
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Warning", "Cant Open File");
    }

    //Create a text stream to parse CSV file
    QTextStream in(&file);
    in.readLine();
    while(!in.atEnd()){
    QString text = in.readLine();

    updateValues(text);
    updatePlots();

    addDelay();
}
    file.close();
    return;
}

void MainWindow::setupPlots()
{
    //    QLinearGradient plotGradient;
    //    plotGradient.setStart(0, 0);
    //    plotGradient.setFinalStop(0, 350);
    //    plotGradient.setColorAt(0, QColor(80, 80, 80));
    //    plotGradient.setColorAt(1, QColor(50, 50, 50));

    ui->alt_plot->addGraph();
    ui->alt_plot->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->alt_plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->alt_plot->graph(0)->setPen(QColor(240, 0, 45));
    ui->alt_plot->graph(0)->setBrush(QColor(240, 0, 45));
    ui->alt_plot->setInteraction(QCP::iRangeDrag, false);
    ui->alt_plot->setInteraction(QCP::iRangeZoom, false);
    ui->alt_plot->xAxis->setBasePen(QPen(Qt::gray, 1));
    ui->alt_plot->yAxis->setBasePen(QPen(Qt::gray, 1));
    ui->alt_plot->xAxis->setTickPen(QPen(Qt::gray, 1));
    ui->alt_plot->yAxis->setTickPen(QPen(Qt::gray, 1));
    ui->alt_plot->xAxis->setSubTickPen(QPen(Qt::gray, 1));
    ui->alt_plot->yAxis->setSubTickPen(QPen(Qt::gray, 1));
    ui->alt_plot->xAxis->setTickLabelColor(Qt::gray);
    ui->alt_plot->yAxis->setTickLabelColor(Qt::gray);
    ui->alt_plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->alt_plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->alt_plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->alt_plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->alt_plot->xAxis->grid()->setSubGridVisible(true);
    ui->alt_plot->yAxis->grid()->setSubGridVisible(true);
    ui->alt_plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->alt_plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->alt_plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->alt_plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);    
    ui->alt_plot->setBackground(QColor(44, 45, 46));

    ui->temp_plot->addGraph();
    ui->temp_plot->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->temp_plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->temp_plot->graph(0)->setPen(QColor(240, 0, 45));
    ui->temp_plot->graph(0)->setBrush(QColor(240, 0, 45));
    ui->temp_plot->setInteraction(QCP::iRangeDrag, false);
    ui->temp_plot->setInteraction(QCP::iRangeZoom, false);
    ui->temp_plot->xAxis->setBasePen(QPen(Qt::gray, 1));
    ui->temp_plot->yAxis->setBasePen(QPen(Qt::gray, 1));
    ui->temp_plot->xAxis->setTickPen(QPen(Qt::gray, 1));
    ui->temp_plot->yAxis->setTickPen(QPen(Qt::gray, 1));
    ui->temp_plot->xAxis->setSubTickPen(QPen(Qt::gray, 1));
    ui->temp_plot->yAxis->setSubTickPen(QPen(Qt::gray, 1));
    ui->temp_plot->xAxis->setTickLabelColor(Qt::gray);
    ui->temp_plot->yAxis->setTickLabelColor(Qt::gray);
    ui->temp_plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->temp_plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->temp_plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->temp_plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->temp_plot->xAxis->grid()->setSubGridVisible(true);
    ui->temp_plot->yAxis->grid()->setSubGridVisible(true);
    ui->temp_plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->temp_plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->temp_plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->temp_plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->temp_plot->setBackground(QColor(44, 45, 46));

    ui->tilt_plot->addGraph();
    ui->tilt_plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->tilt_plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->tilt_plot->graph(0)->setPen(QColor(240, 0, 45));
    ui->tilt_plot->addGraph();
    ui->tilt_plot->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->tilt_plot->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->tilt_plot->graph(1)->setPen(QColor(240, 0, 45));
    ui->tilt_plot->setInteraction(QCP::iRangeDrag, false);
    ui->tilt_plot->setInteraction(QCP::iRangeZoom, false);
    ui->tilt_plot->xAxis->setBasePen(QPen(Qt::gray, 1));
    ui->tilt_plot->yAxis->setBasePen(QPen(Qt::gray, 1));
    ui->tilt_plot->xAxis->setTickPen(QPen(Qt::gray, 1));
    ui->tilt_plot->yAxis->setTickPen(QPen(Qt::gray, 1));
    ui->tilt_plot->xAxis->setSubTickPen(QPen(Qt::gray, 1));
    ui->tilt_plot->yAxis->setSubTickPen(QPen(Qt::gray, 1));
    ui->tilt_plot->xAxis->setTickLabelColor(Qt::gray);
    ui->tilt_plot->yAxis->setTickLabelColor(Qt::gray);
    ui->tilt_plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->tilt_plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->tilt_plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->tilt_plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->tilt_plot->xAxis->grid()->setSubGridVisible(true);
    ui->tilt_plot->yAxis->grid()->setSubGridVisible(true);
    ui->tilt_plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->tilt_plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->tilt_plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->tilt_plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->tilt_plot->setBackground(QColor(44, 45, 46));

    ui->voltage_plot->addGraph();
    ui->voltage_plot->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->voltage_plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->voltage_plot->graph(0)->setPen(QColor(240, 0, 45));
    ui->voltage_plot->graph(0)->setBrush(QColor(240, 0, 45));
    ui->voltage_plot->setInteraction(QCP::iRangeDrag, false);
    ui->voltage_plot->setInteraction(QCP::iRangeZoom, false);
    ui->voltage_plot->xAxis->setBasePen(QPen(Qt::gray, 1));
    ui->voltage_plot->yAxis->setBasePen(QPen(Qt::gray, 1));
    ui->voltage_plot->xAxis->setTickPen(QPen(Qt::gray, 1));
    ui->voltage_plot->yAxis->setTickPen(QPen(Qt::gray, 1));
    ui->voltage_plot->xAxis->setSubTickPen(QPen(Qt::gray, 1));
    ui->voltage_plot->yAxis->setSubTickPen(QPen(Qt::gray, 1));
    ui->voltage_plot->xAxis->setTickLabelColor(Qt::gray);
    ui->voltage_plot->yAxis->setTickLabelColor(Qt::gray);
    ui->voltage_plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->voltage_plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->voltage_plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->voltage_plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->voltage_plot->xAxis->grid()->setSubGridVisible(true);
    ui->voltage_plot->yAxis->grid()->setSubGridVisible(true);
    ui->voltage_plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->voltage_plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->voltage_plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->voltage_plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->voltage_plot->setBackground(QColor(44, 45, 46));

}

void MainWindow::updateValues(QString in)
{
    QList input = in.split(',');

    //Update basic info
    ui->team_id->setText(input[0]);
    ui->mission_time->setText(input[1]);
    {
        QList currtime = input[1].split(':');
        missionTime.append((3600*(currtime[0].toDouble()))+60*(currtime[1].toDouble())+(currtime[2].toDouble()));
    }
    ui->packet_count->setText(input[2]);

    //Update operation mode
    if(input[3]=='F') ui->mode->setText("FLIGHT");
    else if(input[3]=='S') ui->mode->setText("SIMULATION");
    else ui->mode->setText("ERROR");

    //Update state
    ui->state->setText(input[4]);

    //Update altitude value and vector
    altitude.append(input[5].toDouble());
    ui->altitude->setText(input[5]);

    //Update heat shield deploy status
    if(input[6]=='Y')
    {
        ui->hs_deployed->setText("YES");
        ui->hs_deployed->setStyleSheet("color: green;"
                                       "border: none;"
                                       "border-radius: 4px;"
                                       "background-color: rgb(46, 47, 48)");
    }
    else if(input[6]=='N') ui->hs_deployed->setText("NO");
    else ui->hs_deployed->setText("ERROR");

    //Update parachute deploy status
    if(input[7]=='Y')
    {
        ui->pc_deployed->setText("YES");
        ui->pc_deployed->setStyleSheet("color: green;"
                                       "border: none;"
                                       "border-radius: 4px;"
                                       "background-color: rgb(46, 47, 48)");
    }
    else if(input[7]=='N') ui->pc_deployed->setText("NO");
    else ui->pc_deployed->setText("ERROR");

    //Update mast raised status
    if(input[8]=='Y')
    {
        ui->mast_raised->setText("YES");
        ui->mast_raised->setStyleSheet("color: green;"
                                       "border: none;"
                                       "border-radius: 4px;"
                                       "background-color: rgb(46, 47, 48)");
    }
    else if(input[8]=='N') ui->mast_raised->setText("NO");
    else ui->mast_raised->setText("ERROR");

    //Update temperature value and vector
    temperature.append(input[9].toDouble());
    ui->temperature->setText(input[9]);

    //Update voltage value and vector
    voltage.append(input[10].toDouble());
    ui->voltage->setText(input[10]);

    //Update GPS_Time
//    ui->gps_time->setText(input[11]);

    //Update GPS GPS_Altitude value and vector
    GPS_Altitude.append(input[12].toDouble());
//    ui->gps_altitude->setText(input[12]);

//Update GPS_Latitude and GPS_Longitude input[13] and input[14]

    //Update GPS_Sats value and vector
    GPS_Sats.append(input[15].toDouble());
//    ui->gps_sats->setText(input[15]);

    //Update tilt_X and tilt_Y values and vectors
    tilt_X.append(input[16].toDouble());
    tilt_Y.append(input[17].toDouble());
    ui->tilt_x->setText(input[16]);
    ui->tilt_y->setText(input[17]);

    //Update CMD_Echo (last command processed by CANSAT
    ui->cmd_echo->setText(input[18]);


    return;
}


void MainWindow::updatePlots()
{
    ui->alt_plot->graph(0)->setData(missionTime, altitude);
    ui->alt_plot->rescaleAxes();
    ui->alt_plot->xAxis->setRange(0,ceil(missionTime.back()/60)*60);
    ui->alt_plot->yAxis->setRange(0, 1000);
    ui->alt_plot->replot();
    ui->alt_plot->update();


    ui->temp_plot->graph(0)->setData(missionTime, temperature);
    ui->temp_plot->rescaleAxes();
    ui->temp_plot->xAxis->setRange(0,ceil(missionTime.back()/60)*60);
    ui->temp_plot->yAxis->setRange(0, 50);
    ui->temp_plot->replot();
    ui->temp_plot->update();


    ui->tilt_plot->graph(0)->setData(missionTime, tilt_X);
    ui->tilt_plot->graph(1)->setData(missionTime, tilt_Y);
    ui->tilt_plot->rescaleAxes();
    ui->tilt_plot->xAxis->setRange(0,ceil(missionTime.back()/60)*60);
    ui->tilt_plot->yAxis->setRange(0, 360);
    ui->tilt_plot->replot();
    ui->tilt_plot->update();


    ui->voltage_plot->graph(0)->setData(missionTime, voltage);
    ui->voltage_plot->rescaleAxes();
    ui->voltage_plot->xAxis->setRange(0,ceil(missionTime.back()/60)*60);
    ui->voltage_plot->yAxis->setRange(0, 10);
    ui->voltage_plot->replot();
    ui->voltage_plot->update();

    return;
}

void MainWindow::addDelay()
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(1000);
    loop.exec();
    return;
}

