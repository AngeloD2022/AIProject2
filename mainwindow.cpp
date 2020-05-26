#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "NeuralNetworkLibrary/neuralnetwork.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QList<int> configuration = {3,8,2};
    neuralNetwork = new NeuralNetwork(configuration);

}

MainWindow::~MainWindow() {
    delete ui;
}

