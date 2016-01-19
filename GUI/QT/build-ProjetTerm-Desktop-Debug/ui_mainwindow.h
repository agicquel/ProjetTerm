/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *iprpiLineEdit;
    QPushButton *connectionButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *analyseButton;
    QPushButton *actualiseButton;
    QPushButton *settingButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QCustomPlot *AnalysePlot;
    QLabel *NitrateLabel;
    QLabel *TempLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 781, 34));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        iprpiLineEdit = new QLineEdit(layoutWidget);
        iprpiLineEdit->setObjectName(QStringLiteral("iprpiLineEdit"));
        iprpiLineEdit->setBaseSize(QSize(0, 0));
        iprpiLineEdit->setInputMethodHints(Qt::ImhPreferNumbers);
        iprpiLineEdit->setClearButtonEnabled(true);

        horizontalLayout->addWidget(iprpiLineEdit);

        connectionButton = new QPushButton(layoutWidget);
        connectionButton->setObjectName(QStringLiteral("connectionButton"));

        horizontalLayout->addWidget(connectionButton);

        horizontalSpacer = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        analyseButton = new QPushButton(layoutWidget);
        analyseButton->setObjectName(QStringLiteral("analyseButton"));

        horizontalLayout->addWidget(analyseButton);

        actualiseButton = new QPushButton(layoutWidget);
        actualiseButton->setObjectName(QStringLiteral("actualiseButton"));

        horizontalLayout->addWidget(actualiseButton);

        settingButton = new QPushButton(layoutWidget);
        settingButton->setObjectName(QStringLiteral("settingButton"));

        horizontalLayout->addWidget(settingButton);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 40, 801, 561));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        AnalysePlot = new QCustomPlot(layoutWidget1);
        AnalysePlot->setObjectName(QStringLiteral("AnalysePlot"));

        verticalLayout->addWidget(AnalysePlot);

        NitrateLabel = new QLabel(layoutWidget1);
        NitrateLabel->setObjectName(QStringLiteral("NitrateLabel"));
        NitrateLabel->setMaximumSize(QSize(16777215, 15));

        verticalLayout->addWidget(NitrateLabel);

        TempLabel = new QLabel(layoutWidget1);
        TempLabel->setObjectName(QStringLiteral("TempLabel"));
        TempLabel->setMaximumSize(QSize(16777215, 15));

        verticalLayout->addWidget(TempLabel);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Purificateur d'eau", 0));
        iprpiLineEdit->setInputMask(QString());
        iprpiLineEdit->setText(QString());
        connectionButton->setText(QApplication::translate("MainWindow", "Connection", 0));
        analyseButton->setText(QApplication::translate("MainWindow", "Analyser", 0));
        actualiseButton->setText(QApplication::translate("MainWindow", "Actualiser", 0));
        settingButton->setText(QApplication::translate("MainWindow", "Parametres", 0));
        NitrateLabel->setText(QApplication::translate("MainWindow", "NItrate", 0));
        TempLabel->setText(QApplication::translate("MainWindow", "Temperature", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
