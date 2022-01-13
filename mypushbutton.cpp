#include "mypushbutton.h"
#include <QPainter>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDebug>

MyPushButton::MyPushButton(QString normalImg, QString pressedImg ,QWidget *parent)
    : QPushButton(parent),
      mNormalImg(normalImg),
      mPressedImg(pressedImg)
{
//    this->mState = Normal;
//    qDebug()<<mState;
}

void MyPushButton::moveDown()
{
    auto *animation = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setDuration(200);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::moveUp()
{
    auto *animation = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animation->setDuration(200);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(this->mState == Normal){
        painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(mNormalImg));


    }
    if (this->mState == Pressed){
        painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(mPressedImg));

    }

    painter.drawText(0,0,this->width(),this->height()
                     ,Qt::AlignCenter|Qt::AlignVCenter,this->text());

}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    this->mState = Pressed;
//    qDebug()<< "pressed";
//    qDebug()<<mState;

    update();
    QPushButton::mousePressEvent(e);

}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    this->mState = Normal;
//    qDebug()<< "normal";
//    qDebug()<<mState;

    update();
    QPushButton::mouseReleaseEvent(e);
}
