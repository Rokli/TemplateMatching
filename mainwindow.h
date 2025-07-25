#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_load_one_photo_clicked();

    void on_button_load_photo_two_clicked();

    void on_button_compare_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
