#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

QTranslator *tor;
int flag = 0;

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
    updateUI();
}

Widget::~Widget()
{
    delete ui;
    delete tor;
}

/* 更新UI */
void Widget::updateUI()
{
    this->setWindowTitle(tr("语言切换"));
    ui->groupBox->setTitle(tr("语言选择"));
    ui->pushButton->setText(tr("测试"));
    ui->label->setText(tr("好久不见"));
    ui->comboBox->setItemText(0,tr("中文"));
    ui->comboBox->setItemText(1,tr("英语"));
    ui->comboBox->setItemText(2,tr("德语"));
    //this->ui->retranslateUi(this);
}

void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this, "information", tr("动态切换语言"));
}
void Widget::LanguageChange(QString language)
{
    qDebug()<<language;

    QApplication::removeTranslator(tor);
    tor->load(language);
    qApp->installTranslator(tor);
    updateUI();
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        LanguageChange(":/trans/zh.qm");
        qDebug()<<"Chinese"<<endl;
        break;
    case 1:
        LanguageChange(":/trans/en.qm");
        qDebug()<<"English"<<endl;
        break;
    case 2:
        LanguageChange(":/trans/Ge.qm");
        qDebug()<<"German"<<endl;
        break;
    default:
        break;
    }
}
