#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QtCore>
#include <QTimer>
#include <QEventLoop>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //Private variables:
    QVector<double> missionTime;
    QVector<double> altitude;
    QVector<double> temperature;
    QVector<double> voltage;
    QVector<double> GPS_Altitude;
    QVector<double> GPS_Sats;
    QVector<double> tilt_X;
    QVector<double> tilt_Y;

    //Private functions:
    void startExec();
    void setupPlots();
    void updateValues(QString);
    void updatePlots(QString);
    void addDelay();
};
#endif // MAINWINDOW_H
