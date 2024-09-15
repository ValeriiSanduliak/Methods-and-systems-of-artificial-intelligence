// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QVector>

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


    void convertImagesToGrayscale();
    void convertToBlackAndWhite();
    void cropImages();
private slots:
    void on_buttonSelectImages1_clicked(); // Slot for image selection
      void on_buttonTransform_clicked(); // Slot for image transformation
private:
    Ui::MainWindow *ui;
    QVector<QImage> images; // Store loaded images
    void convertGrayPixelsToBlack(int threshold);
};
#endif // MAINWINDOW_H
