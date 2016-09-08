#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>
QTranslator *tor;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*add language first is Chinese*/
    tor = new QTranslator();
    tor->load(":/trans/zh.qm");
    qApp->installTranslator(tor);
    /*fresh*/
    this->ui->retranslateUi(this);
}

Widget::~Widget()
{
    delete ui;
    delete tor;
}

void Widget::on_pushButton_clicked()
/*chinese*/
{
    QApplication::removeTranslator(tor);
    tor->load(":/trans/zh.qm");
    qApp->installTranslator(tor);
    this->ui->retranslateUi(this);
}

void Widget::on_pushButton_2_clicked()
/*english*/
{
    QApplication::removeTranslator(tor);
    tor->load(":/trans/en.qm");
    qApp->installTranslator(tor);
    this->ui->retranslateUi(this);
}

void Widget::on_pushButton_3_clicked()
{
     QMessageBox::information(this, "information", tr("动态切换中英文"));
}

void Widget::on_pushButton_4_clicked()
/*German*/
{
    QApplication::removeTranslator(tor);
    tor->load(":/trans/Ge.qm");
    qApp->installTranslator(tor);
    this->ui->retranslateUi(this);
}
