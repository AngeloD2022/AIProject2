#ifndef ADDVALUEDIALOG_H
#define ADDVALUEDIALOG_H

#include <QDialog>
#include <QObject>
#include <QLineEdit>

namespace Ui {
    class AddValueDialog;
}

class AddValueDialog : public QDialog {
Q_OBJECT

public:
    explicit AddValueDialog(QWidget *parent = nullptr);

    ~AddValueDialog();


    double getNumber() {
        return number;
    }

    int getChoice() {
        return choice; // 0 if custom value is chosen, 1 if AI inference is chosen.
    }

private slots:

    void on_comboBox_currentIndexChanged(const QString &arg1);


    void on_applyBtn_clicked();

    void on_cancelBtn_clicked();

private:
    int choice;
    double number;
    QLineEdit *ledit = new QLineEdit();
    Ui::AddValueDialog *ui{};
};

#endif // ADDVALUEDIALOG_H
