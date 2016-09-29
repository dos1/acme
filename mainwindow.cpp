#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QProcessEnvironment>
#include "unistd.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::textChanged() {

    ui->outputEdit->setPlainText(QString("%1(%2): %3\n\n%4\n\n%5\n\n%6\n").arg(
                                        ui->typeBox->currentText(),
                                        ui->scopeEdit->text(),
                                        ui->subjectEdit->text(),
                                        ui->messageEdit->toPlainText(),
                                        ui->breaksEdit->toPlainText(),
                                        ui->closesEdit->toPlainText()
                                     ));
}

void MainWindow::setFilename(QString filename) {
    this->filename = filename;

    QFile file(filename);

    QString content;

    if (file.open(QFile::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        while (true) {
            QString line = stream.readLine();
            if (line.isNull()) {
                break;
            }
            content.append(line).append("\n");
        }

        ui->plainTextEdit->setPlainText(content);

    }
}

void MainWindow::openInEditor() {
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QString editor = env.value("VISUAL", env.value("EDITOR", "nano"));

    execlp(editor.toStdString().c_str(), editor.toStdString().c_str(), filename.toStdString().c_str(), NULL);
}

void MainWindow::save() {

    QFile file(filename);

    if (file.open(QFile::WriteOnly | QIODevice::Text | QFile::Truncate)) {
        file.write(ui->outputEdit->toPlainText().toLocal8Bit());
    }

    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
