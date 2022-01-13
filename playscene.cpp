#include "playscene.h"
#include "mypushbutton.h"
#include <QPainter>
#include <QPixmap>
#include <QMenuBar>
#include <QLabel>
#include <coinbutton.h>
#include <dataconfig.h>
#include <QTimer>
#include <QMessageBox>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSound>


PlayScene::PlayScene(int level, QWidget *parent) : MyMainWindow(parent)
{
    auto *btnBack = new MyPushButton(":/res/BackButton.png",
                                     ":/res/BackButtonSelected.png",this);
    btnBack->resize(72,32);
    connect(btnBack,&QPushButton::clicked,this,&PlayScene::backBtnClicked);

    btnBack->move(this->width()-btnBack->width(),
                  this->height()-btnBack->height());

    auto *label = new QLabel(this);
    label->setText(QString("Level: %1").arg(level));
    label->setFont(QFont("华文新魏",20));
    label->resize(150,50);
    label ->move(30,this->height()-label->height());

    const int colWidth = 50;
    const int rowHeight = 50;

    dataConfig data;
    auto dataArray = data.mData[level];


    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {

            auto *btn = new CoinButton(this);
            mCoins[row][col] = btn;



            int x = col * colWidth + 57;
            int y = row * rowHeight + 200;

            btn->resize(50,50);
            btn->move(x,y);

            btn->setState(dataArray[row][col]);

            connect(btn,&CoinButton::clicked,[=](){
                this->flip(row,col);

            });

        }
    }

}

void PlayScene::flip(int row, int col)
{
    if(mIsWin)
        return;


    this->mCoins[row][col]->flip();

    QSound::play(":/res/ConFlipSound.wav");
    QTimer::singleShot(250,[=](){

        if(row+1<4)
        this->mCoins[row+1][col]->flip();

        if(row-1>=0)
        this->mCoins[row-1][col]->flip();

        if(col+1<4)
        this->mCoins[row][col+1]->flip();

        if(col-1>=0)
        this->mCoins[row][col-1]->flip();


        this->judgeWin();

    });


}

void PlayScene::judgeWin()
{
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if(!this->mCoins[row][col]->state()){
                return;
            }
        }
    }
    //QMessageBox::information(this,"恭喜","you win !");

    this->mIsWin = true;

    QSound::play(":/res/LevelWinSound.wav");

    auto *labelWin = new QLabel(this);

    QPixmap pix(":/res/LevelCompletedDialogBg.png");


    labelWin->setPixmap(pix);
    labelWin->resize(pix.size());
    labelWin->show();
    labelWin->move((this->width()-labelWin->width())/2,-labelWin->height());

    auto *animation = new QPropertyAnimation(labelWin,"geometry",this);
    animation->setStartValue(labelWin->geometry());
    animation->setEndValue(QRect(labelWin->x(),labelWin->y()+150,
                                 labelWin->width(),labelWin->height()));

    animation->setDuration(1000);

    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start(QAbstractAnimation::DeleteWhenStopped);


}


void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.translate(0,this->menuBar()->height());


    painter.drawPixmap(0,0,this->width(),this->height(),
                       QPixmap(":/res/PlayLevelSceneBg.png"));

    QPixmap pix(":/res/Title.png");

    painter.drawPixmap(0,0,pix.scaled(pix.width()/2,pix.height()/2));

}
