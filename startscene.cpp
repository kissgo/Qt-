#include "startscene.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QTimer>
#include <QSound>


StartScene::StartScene(QWidget *parent) : MyMainWindow(parent)
{
    this->setWindowTitle("开始场景");

    auto *btnStart = new MyPushButton(":/res/MenuSceneStartButton.png",
                                      ":/res/MenuSceneStartButton.png",
                                      this);

    btnStart->resize(114,114);
    //水平居中，垂直四分之三
    btnStart->move((this->width()-btnStart->width())/2,
                   this->height()*3/4-btnStart->height()/2);

    connect(&this->mSelectScene,SelectScene::backBtnClicked,[=](){

        QSound::play(":/res/BackButtonSound.wav");
        this->mSelectScene.hide();
        this->move(this->mSelectScene.pos());
        this->show();
    });

    connect(btnStart,&MyPushButton::clicked,[=](){

        QSound::play(":/res/TapButtonSound.wav");


        //使按钮不可用
        btnStart->setEnabled(false);

        //播放向下的动画
        btnStart->moveDown();
        QTimer::singleShot(250,[=](){
            //250ms之后向上
            btnStart->moveUp();
        });

        QTimer::singleShot(500,[=](){
            btnStart->setEnabled(true);
        //切换选择
        this->hide();

        this->mSelectScene.move(this->pos());
        this->mSelectScene.show();
        });
    });



}
