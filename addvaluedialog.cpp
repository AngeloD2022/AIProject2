#include "addvaluedialog.h"
#include "ui_addvaluedialog.h"

AddValueDialog::AddValueDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddValueDialog) {
    ui->setupUi(this);
}

AddValueDialog::~AddValueDialog() {
    delete ui;
}

void AddValueDialog::on_comboBox_currentIndexChanged(const QString &arg1) {
    if (arg1 == "Pattern Base") {
        choice = 0;
        ui->gridLayout->addWidget(ledit, 1, 0);
    } else if (arg1 == "AI Inference") {
        choice = 1;
    }
}

void AddValueDialog::on_applyBtn_clicked() {
    if (ui->comboBox->currentText() == "Choose Value Type") {
        this->done(0);
    } else {
        if (choice == 0) {
            number = ledit->text().toDouble();
        }
        this->done(1);
    }
}

void AddValueDialog::on_cancelBtn_clicked() {
    this->done(0);
}
