/********************************************************************************
** Form generated from reading UI file 'csqiyuan.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSQIYUAN_H
#define UI_CSQIYUAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_csqiyuanClass
{
public:
    QCheckBox *checkBox;
    QPushButton *zhuru;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;

    void setupUi(QWidget *csqiyuanClass)
    {
        if (csqiyuanClass->objectName().isEmpty())
            csqiyuanClass->setObjectName(QStringLiteral("csqiyuanClass"));
        csqiyuanClass->resize(600, 400);
        checkBox = new QCheckBox(csqiyuanClass);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(50, 20, 91, 19));
        zhuru = new QPushButton(csqiyuanClass);
        zhuru->setObjectName(QStringLiteral("zhuru"));
        zhuru->setGeometry(QRect(210, 300, 93, 28));
        checkBox_2 = new QCheckBox(csqiyuanClass);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(290, 20, 91, 19));
        checkBox_3 = new QCheckBox(csqiyuanClass);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(50, 70, 91, 19));
        checkBox_4 = new QCheckBox(csqiyuanClass);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(290, 70, 91, 19));

        retranslateUi(csqiyuanClass);

        QMetaObject::connectSlotsByName(csqiyuanClass);
    } // setupUi

    void retranslateUi(QWidget *csqiyuanClass)
    {
        csqiyuanClass->setWindowTitle(QApplication::translate("csqiyuanClass", "csqiyuan", Q_NULLPTR));
        checkBox->setText(QApplication::translate("csqiyuanClass", "\351\224\201\350\241\200", Q_NULLPTR));
        zhuru->setText(QApplication::translate("csqiyuanClass", "\346\263\250\345\205\245", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("csqiyuanClass", "\346\227\240\345\220\216\345\235\220\345\212\233", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("csqiyuanClass", "\346\227\240\351\231\220\345\255\220\345\274\271", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("csqiyuanClass", "\344\272\272\347\211\251\351\200\217\350\247\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class csqiyuanClass: public Ui_csqiyuanClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSQIYUAN_H
