/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *configLocation;
    QPushButton *openConfigBtn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *openImageBtn;
    QPushButton *detectFacesBtn;
    QPushButton *recogniseBtn;
    QPushButton *updateDatabaseBtn;
    QPushButton *saveConfigBtn;
    QWidget *widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        configLocation = new QLineEdit(centralWidget);
        configLocation->setObjectName(QStringLiteral("configLocation"));
        configLocation->setGeometry(QRect(10, 510, 441, 22));
        openConfigBtn = new QPushButton(centralWidget);
        openConfigBtn->setObjectName(QStringLiteral("openConfigBtn"));
        openConfigBtn->setGeometry(QRect(460, 505, 132, 32));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(630, 100, 160, 168));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        openImageBtn = new QPushButton(verticalLayoutWidget);
        openImageBtn->setObjectName(QStringLiteral("openImageBtn"));

        verticalLayout->addWidget(openImageBtn);

        detectFacesBtn = new QPushButton(verticalLayoutWidget);
        detectFacesBtn->setObjectName(QStringLiteral("detectFacesBtn"));

        verticalLayout->addWidget(detectFacesBtn);

        recogniseBtn = new QPushButton(verticalLayoutWidget);
        recogniseBtn->setObjectName(QStringLiteral("recogniseBtn"));

        verticalLayout->addWidget(recogniseBtn);

        updateDatabaseBtn = new QPushButton(verticalLayoutWidget);
        updateDatabaseBtn->setObjectName(QStringLiteral("updateDatabaseBtn"));

        verticalLayout->addWidget(updateDatabaseBtn);

        saveConfigBtn = new QPushButton(verticalLayoutWidget);
        saveConfigBtn->setObjectName(QStringLiteral("saveConfigBtn"));

        verticalLayout->addWidget(saveConfigBtn);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 621, 501));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "libface Example", 0));
        configLocation->setText(QApplication::translate("MainWindow", "Some Default File Location", 0));
        openConfigBtn->setText(QApplication::translate("MainWindow", "Config Directory", 0));
        openImageBtn->setText(QApplication::translate("MainWindow", "Open Image", 0));
        detectFacesBtn->setText(QApplication::translate("MainWindow", "Detect Faces", 0));
        recogniseBtn->setText(QApplication::translate("MainWindow", "Recognise", 0));
        updateDatabaseBtn->setText(QApplication::translate("MainWindow", "Update Database", 0));
        saveConfigBtn->setText(QApplication::translate("MainWindow", "Save Config", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
