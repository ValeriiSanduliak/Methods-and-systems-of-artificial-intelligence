// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Clear all previous connections
    QObject::disconnect(ui->buttonSelectImages1, nullptr, nullptr, nullptr);


    // Connect the button's clicked signal to the slot
    connect(ui->buttonSelectImages1, &QPushButton::clicked, this, &MainWindow::on_buttonSelectImages1_clicked);

    connect(ui->buttonTransform, &QPushButton::clicked, this, &MainWindow::on_buttonTransform_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonSelectImages1_clicked()
{
    // Open a file dialog to select one or more images
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Select Images", "", "Images (*.png *.xpm *.jpg);;All Files (*)");

    // Clear previous images
    images.clear();

    // Load selected images
    for (const QString &fileName : fileNames) {
        QImage image(fileName);
        if (!image.isNull()) {
            images.append(image);
        } else {
            // Handle error if image fails to load
            qWarning() << "Failed to load image:" << fileName;
        }
    }

    // Update the UI or perform further processing
    // For example, you could display the number of images loaded:
    ui->label->setText(QString("Loaded %1 images").arg(images.size()));
}

void MainWindow::convertImagesToGrayscale()
{
    for (int i = 0; i < images.size(); ++i) {
        QImage &image = images[i];
        QImage grayscaleImage = image.convertToFormat(QImage::Format_Grayscale8);

        // Replace the original image with the grayscale version
        images[i] = grayscaleImage;
    }

    //Clear the label
    ui->label->clear();
}

// Convert grayscale pixels to black and white based on a threshold
void MainWindow::convertGrayPixelsToBlack(int threshold)
{
    for (QImage &image : images) {
        for (int y = 0; y < image.height(); ++y) {
            for (int x = 0; x < image.width(); ++x) {
                QRgb pixel = image.pixel(x, y);
                int gray = qGray(pixel);
                int newPixel = (gray < threshold) ? 0 : 255;
                image.setPixel(x, y, qRgb(newPixel, newPixel, newPixel));
            }
        }
    }
}


void MainWindow::cropImages()
{
    for (QImage &image : images) {
        int top = 0, bottom = image.height() - 1;
        int left = 0, right = image.width() - 1;

        // Find the top boundary
        for (int y = 0; y < image.height(); ++y) {
            bool rowHasNonEmptyPixel = false;
            for (int x = 0; x < image.width(); ++x) {
                if (image.pixel(x, y) != qRgb(255, 255, 255)) { // Assuming white is empty
                    rowHasNonEmptyPixel = true;
                    break;
                }
            }
            if (rowHasNonEmptyPixel) {
                top = y;
                break;
            }
        }

        // Find the bottom boundary
        for (int y = image.height() - 1; y >= top; --y) {
            bool rowHasNonEmptyPixel = false;
            for (int x = 0; x < image.width(); ++x) {
                if (image.pixel(x, y) != qRgb(255, 255, 255)) { // Assuming white is empty
                    rowHasNonEmptyPixel = true;
                    break;
                }
            }
            if (rowHasNonEmptyPixel) {
                bottom = y;
                break;
            }
        }

        // Find the left boundary
        for (int x = 0; x < image.width(); ++x) {
            bool columnHasNonEmptyPixel = false;
            for (int y = top; y <= bottom; ++y) {
                if (image.pixel(x, y) != qRgb(255, 255, 255)) { // Assuming white is empty
                    columnHasNonEmptyPixel = true;
                    break;
                }
            }
            if (columnHasNonEmptyPixel) {
                left = x;
                break;
            }
        }

        // Find the right boundary
        for (int x = image.width() - 1; x >= left; --x) {
            bool columnHasNonEmptyPixel = false;
            for (int y = top; y <= bottom; ++y) {
                if (image.pixel(x, y) != qRgb(255, 255, 255)) { // Assuming white is empty
                    columnHasNonEmptyPixel = true;
                    break;
                }
            }
            if (columnHasNonEmptyPixel) {
                right = x;
                break;
            }
        }

        // Crop the image
        image = image.copy(left, top, right - left + 1, bottom - top + 1);
    }
}


void MainWindow::on_buttonTransform_clicked()
{
    convertImagesToGrayscale();

   // Convert the grayscale images to black and white

    //Read from QTextEdit
    int threshold = ui->limitEdit->toPlainText().toInt();

    convertGrayPixelsToBlack(threshold);

    //Display images lables
    // Crop the images to remove empty spaces
    cropImages();

    // Display the first image after transformation and cropping
    if (!images.isEmpty()) {
        ui->label->setPixmap(QPixmap::fromImage(images[0]));
    }
}


