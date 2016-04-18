/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *iprpiLineEdit;
    QLineEdit *portEdit;
    QPushButton *connectionButton;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QPushButton *analyseButton;
    QPushButton *actualiseButton;
    QPushButton *settingButton;
    QGridLayout *gridLayout_3;
    QLabel *NitrateLabel;
    QCustomPlot *AnalysePlot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        iprpiLineEdit = new QLineEdit(centralWidget);
        iprpiLineEdit->setObjectName(QStringLiteral("iprpiLineEdit"));
        iprpiLineEdit->setBaseSize(QSize(0, 0));
        iprpiLineEdit->setInputMethodHints(Qt::ImhPreferNumbers);
        iprpiLineEdit->setClearButtonEnabled(true);

        horizontalLayout->addWidget(iprpiLineEdit);

        portEdit = new QLineEdit(centralWidget);
        portEdit->setObjectName(QStringLiteral("portEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(portEdit->sizePolicy().hasHeightForWidth());
        portEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(portEdit);

        connectionButton = new QPushButton(centralWidget);
        connectionButton->setObjectName(QStringLiteral("connectionButton"));

        horizontalLayout->addWidget(connectionButton);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        horizontalSpacer = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        analyseButton = new QPushButton(centralWidget);
        analyseButton->setObjectName(QStringLiteral("analyseButton"));

        horizontalLayout->addWidget(analyseButton);

        actualiseButton = new QPushButton(centralWidget);
        actualiseButton->setObjectName(QStringLiteral("actualiseButton"));

        horizontalLayout->addWidget(actualiseButton);

        settingButton = new QPushButton(centralWidget);
        settingButton->setObjectName(QStringLiteral("settingButton"));

        horizontalLayout->addWidget(settingButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        NitrateLabel = new QLabel(centralWidget);
        NitrateLabel->setObjectName(QStringLiteral("NitrateLabel"));
        NitrateLabel->setMinimumSize(QSize(799, 15));
        NitrateLabel->setMaximumSize(QSize(16777215, 15));

        gridLayout_3->addWidget(NitrateLabel, 0, 0, 1, 1);

        AnalysePlot = new QCustomPlot(centralWidget);
        AnalysePlot->setObjectName(QStringLiteral("AnalysePlot"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AnalysePlot->sizePolicy().hasHeightForWidth());
        AnalysePlot->setSizePolicy(sizePolicy1);
        AnalysePlot->setMinimumSize(QSize(800, 550));
        AnalysePlot->setLayoutDirection(Qt::LeftToRight);
        AnalysePlot->setAutoFillBackground(false);

        gridLayout_3->addWidget(AnalysePlot, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_3, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Purificateur d'eau", 0));
        iprpiLineEdit->setInputMask(QString());
        iprpiLineEdit->setText(QString());
        connectionButton->setText(QApplication::translate("MainWindow", "Connexion", 0));
        analyseButton->setText(QApplication::translate("MainWindow", "Analyser", 0));
        actualiseButton->setText(QApplication::translate("MainWindow", "Actualiser", 0));
        settingButton->setText(QApplication::translate("MainWindow", "Parametres", 0));
        NitrateLabel->setText(QApplication::translate("MainWindow", "Nitrite : ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
