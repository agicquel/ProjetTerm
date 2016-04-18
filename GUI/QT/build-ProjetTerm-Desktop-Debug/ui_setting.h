/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *TauxNitrite;
    QSlider *horizontalSlider;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *TauxNitrite_2;
    QSlider *horizontalSlider_2;
    QDialogButtonBox *quit_button;

    void setupUi(QDialog *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(400, 300);
        gridLayout = new QGridLayout(Setting);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Setting);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        TauxNitrite = new QLCDNumber(Setting);
        TauxNitrite->setObjectName(QStringLiteral("TauxNitrite"));
        TauxNitrite->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(TauxNitrite);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSlider = new QSlider(Setting);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(20);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Setting);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        TauxNitrite_2 = new QLCDNumber(Setting);
        TauxNitrite_2->setObjectName(QStringLiteral("TauxNitrite_2"));
        TauxNitrite_2->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_2->addWidget(TauxNitrite_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalSlider_2 = new QSlider(Setting);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(48);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_2);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        quit_button = new QDialogButtonBox(Setting);
        quit_button->setObjectName(QStringLiteral("quit_button"));
        quit_button->setOrientation(Qt::Horizontal);
        quit_button->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(quit_button, 1, 0, 1, 1);


        retranslateUi(Setting);
        QObject::connect(quit_button, SIGNAL(accepted()), Setting, SLOT(accept()));
        QObject::connect(quit_button, SIGNAL(rejected()), Setting, SLOT(reject()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), TauxNitrite, SLOT(display(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), TauxNitrite_2, SLOT(display(int)));

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QDialog *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Parametres", 0));
        label->setText(QApplication::translate("Setting", "Taux de Nitrite", 0));
        label_2->setText(QApplication::translate("Setting", "Rafra\303\256chissement", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
