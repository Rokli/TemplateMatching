#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_load_one_photo_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите изображение", "", "Images (*.png *.jpg *.jpeg)");
    if (filePath.isEmpty()) return;

    cv::Mat image = cv::imread(filePath.toStdString());
    if (image.empty())
    {
        qWarning() << "Ошибка загрузки!!!";
        return;
    }

    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    QImage qImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    ui->image_label_one->setPixmap(QPixmap::fromImage(qImage).scaled(ui->image_label_two->size(), Qt::KeepAspectRatio));

}


void MainWindow::on_button_load_photo_two_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите изображение", "", "Images (*.png *.jpg *.jpeg)");
    if (filePath.isEmpty()) return;

    cv::Mat image = cv::imread(filePath.toStdString());
    if (image.empty())
    {
        qWarning() << "Ошибка загрузки!!!";
        return;
    }

    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
    QImage qImage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    ui->image_label_two->setPixmap(QPixmap::fromImage(qImage).scaled(ui->image_label_two->size(), Qt::KeepAspectRatio));
}


void MainWindow::on_button_compare_clicked()
{

}

bool areIdentical(const cv::Mat &img1, const cv::Mat &img2) {
    if (img1.size() != img2.size()) return false;

    cv::Mat diff;
    cv::absdiff(img1, img2, diff);
    return cv::countNonZero(diff) == 0;
}

