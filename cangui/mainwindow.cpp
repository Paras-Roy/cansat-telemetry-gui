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
//    updatePlots(text);

    addDelay();
}
    file.close();
    return;
}

void MainWindow::updateValues(QString in)
{
    QList input = in.split(',');

    //Update basic info
    ui->team_id->setText(input[0]);
    ui->mission_time->setText(input[1]);
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

void MainWindow::addDelay()
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(1000);
    loop.exec();
    return;
}

