#include "selectscene.h"
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QMenuBar>
#include "mypushbutton.h"
#include "playscene.h"
#include <QSound>


SelectScene::SelectScene(QWidget *parent) : MyMainWindow(parent)
{
    auto *btnBack = new MyPushButton(":/res/BackButton.png",
                                     ":/res/BackButtonSelected.png",this);
    btnBack->resize(72,32);
    connect(btnBack,&QPushButton::clicked,this,&SelectScene::backBtnClicked);

    btnBack->move(this->width()-btnBack->width(),
                  this->height()-btnBack->height());


    const int colWidth = 70;
    const int rowHeight = 70;



    for (int i = 0; i < 20; ++i) {
        auto *btn = new MyPushButton(":/res/LevelIcon.png",":/res/LevelIcon.png",this);
        //
        btn->setText(QString::number(i+1));

        int row = i/4;
        int col = i%4;


        int x = col * colWidth + 25;
        int y = row * rowHeight + 130;

        btn->resize(57,57);
        btn->move(x,y);

        connect(btn,&MyPushButton::clicked,[=](){

            QSound::play(":/res/TapButtonSound.wav");
            auto *playscene = new PlayScene(i+1);

            playscene->setAttribute(Qt::WA_DeleteOnClose);

            playscene->move(this->pos());
            playscene->show();
            this->hide();

            connect(playscene,&PlayScene::backBtnClicked,[=](){

                QSound::play(":/res/BackButtonSound.wav");

                playscene->close();
                this->move(playscene->pos());
                this->show();
            });
        });
    }

}

void SelectScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.translate(0,this->menuBar()->height());


    painter.drawPixmap(0,0,this->width(),this->height(),
                       QPixmap(":/res/OtherSceneBg.png"));

    painter.drawPixmap(0,0,QPixmap(":/res/Title.png"));

}
