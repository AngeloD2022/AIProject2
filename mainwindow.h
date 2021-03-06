#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <NeuralNetworkLibrary/backpropagationworker.h>
#include <QThread>
#include <NeuralNetworkLibrary/neuralnetwork.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_addButton_clicked();

    void on_backpropButton_clicked();

private:
    Ui::MainWindow *ui;

    // Thread for asynchronous backpropagation
    QThread backpropThread;

    NeuralNetwork *neuralNetwork;
};

#endif // MAINWINDOW_H
