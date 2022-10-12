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
    while(!in.atEnd()){
    QString text = in.readLine();

}
    file.close();
    return;
}

