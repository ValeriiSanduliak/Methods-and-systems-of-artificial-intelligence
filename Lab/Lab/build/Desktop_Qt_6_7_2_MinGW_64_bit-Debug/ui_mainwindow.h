/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *buttonSelectImages1;
    QPushButton *buttonNextImage1;
    QPushButton *buttonTransform;
    QSlider *thresholdSpinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1015, 702);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 461, 611));
        buttonSelectImages1 = new QPushButton(centralwidget);
        buttonSelectImages1->setObjectName("buttonSelectImages1");
        buttonSelectImages1->setGeometry(QRect(490, 30, 80, 24));
        buttonNextImage1 = new QPushButton(centralwidget);
        buttonNextImage1->setObjectName("buttonNextImage1");
        buttonNextImage1->setGeometry(QRect(490, 80, 80, 24));
        buttonTransform = new QPushButton(centralwidget);
        buttonTransform->setObjectName("buttonTransform");
        buttonTransform->setGeometry(QRect(490, 200, 80, 24));
        thresholdSpinBox = new QSlider(centralwidget);
        thresholdSpinBox->setObjectName("thresholdSpinBox");
        thresholdSpinBox->setGeometry(QRect(490, 140, 160, 16));
        thresholdSpinBox->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1015, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        buttonSelectImages1->setText(QCoreApplication::translate("MainWindow", "Load 1", nullptr));
        buttonNextImage1->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        buttonTransform->setText(QCoreApplication::translate("MainWindow", "Transform", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
