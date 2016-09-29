#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setFilename(QString filename);
    ~MainWindow();

public slots:
    void textChanged();
    void save();
    void openInEditor();

private:
    Ui::MainWindow *ui;
    QString filename;
};

#endif // MAINWINDOW_H
