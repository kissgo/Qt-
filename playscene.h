#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mymainwindow.h"
#include "coinbutton.h"

class PlayScene : public MyMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(int level ,QWidget *parent = nullptr);
    void flip(int row,int col);

    void judgeWin();

signals:
    void backBtnClicked();

protected:
    void paintEvent(QPaintEvent *event);


private:
    CoinButton *mCoins[4][4];
    bool mIsWin=false;
};

#endif // PLAYSCENE_H
