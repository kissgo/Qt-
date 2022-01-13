#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include <QPainter>
#include <QPixmap>


MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("翻金币");
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setFixedSize(320,588);

}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);


    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/res/MenuSceneBg.png"));

}

