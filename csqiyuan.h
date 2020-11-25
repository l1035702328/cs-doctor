#ifndef CSQIYUAN_H
#define CSQIYUAN_H

#include <QtWidgets/QWidget>
#include "ui_csqiyuan.h"

class csqiyuan : public QWidget
{
	Q_OBJECT

public:
	csqiyuan(QWidget *parent = 0);
	~csqiyuan();

private slots:
void on_checkBox_clicked(bool checked);
void on_checkBox_2_clicked(bool checked);
void on_checkBox_3_clicked(bool checked);
void on_checkBox_4_clicked(bool checked);
void on_zhuru_clicked();


private:
	Ui::csqiyuanClass ui;
};

#endif // CSQIYUAN_H
