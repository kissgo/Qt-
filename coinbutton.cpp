#include "coinbutton.h"
#include <QPainter>
#include <QPixmap>
CoinButton::CoinButton(QWidget *parent) : QPushButton(parent)
{
    this->setState(0);
    this->setStyleSheet("QPushButton{border:0px;}");

    connect(&this->mTimer,&QTimer::timeout,[=](){
        if(this->mState){
            this->mFrame--;
        }
        else {
            this->mFrame++;
        }


        auto frameName =  QString(":/res/Coin000"+QString::number(mFrame)+".png");
        this->setIcon(QIcon(frameName));

        if(this->mFrame==8||this->mFrame==1){
            this->mTimer.stop();
        }

    });

}

int CoinButton::state() const
{
    return mState;
}

void CoinButton::setState(int state)
{
    mState = state;
    if(this->mState){
        this->setIcon(QIcon(":/res/Coin0001.png"));
    }
    else {
        this->setIcon(QIcon(":/res/Coin0008.png"));
    }
    this->setIconSize(this->size());
}

void CoinButton::setStateWithAnimation(int state)
{
    mState = state;

    if(this->mState){
        this->mFrame =8 ;
    }
    else {
        this->mFrame =1 ;
    }


    this->mTimer.start(30);
}

void CoinButton::flip()
{
    this->setStateWithAnimation(!this->state());
}

void CoinButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/res/BoardNode.png"));

    QPushButton::paintEvent(e);

}
