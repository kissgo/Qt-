#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    enum MyPushButtonState{
        Normal,
        Pressed
    };

    explicit MyPushButton(QString normalImg, QString pressedImg ,QWidget *parent = nullptr);

    void moveDown();

    void moveUp();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:


private:
    QString mNormalImg;
    QString mPressedImg;

    MyPushButtonState mState = Normal;

};

#endif // MYPUSHBUTTON_H
