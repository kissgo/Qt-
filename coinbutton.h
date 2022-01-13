#ifndef COINBUTTON_H
#define COINBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CoinButton(QWidget *parent = nullptr);

    int state() const;
    void setState(int state);

    void setStateWithAnimation(int state);
    void flip();


protected:
    void paintEvent(QPaintEvent *e);



signals:
private:
    int mState;

    int mFrame;

    QTimer mTimer;
};

#endif // COINBUTTON_H
