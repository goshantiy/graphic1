#include "area.h"

#define PI 3.14159265

Area::Area(QWidget *parent):QWidget(parent)
{
setFixedSize(QSize(600,600));
center = QPointF(300,300);
rectCenter = QPointF(500,300);
myrect[0] = QPointF(550,250);
myrect[1] = QPointF(450,250);
myrect[2] = QPointF(450,350);
myrect[3] = QPointF(550,350);
mypoint = &myrect[0];
myline[0] = center;
myline[1] = rectCenter;
alpha=2;
beta=-1;
buf = 0;
}
void Area::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
 myTimer=startTimer(25); // создать таймер
}
void Area::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
 QPainter painter(this);
 painter.setRenderHint(QPainter::Antialiasing);
 painter.setPen(Qt::black);
 drawRect(&painter, myrect);
 painter.setPen(QPen(Qt::DashLine));
 drawLine(&painter, myline);
 painter.setPen(QPen(Qt::red,3,Qt::SolidLine));
 drawPoint(&painter, *mypoint);
}
void Area::timerEvent(QTimerEvent *event)
{
 if (event->timerId() == myTimer && -buf < 360) // если наш таймер
 {
 buf+= beta;
 rectCenter = rotate(rectCenter, center, beta * PI / 180);
 myline[1] = rectCenter;
 for(int i = 0; i < 4; i++)
 {
     myrect[i] = rotate(myrect[i], center,  beta * PI / 180);
     myrect[i] = rotate(myrect[i], rectCenter,  alpha * PI / 180);
 }

 update(); // обновить внешний вид
 }

 else
 QWidget::timerEvent(event); // иначе передать для стандартной
 // обработки
}
void Area::hideEvent(QHideEvent *event)
{
    Q_UNUSED(event);
killTimer(myTimer); // уничтожить таймер
}
Area::~Area()
{

}
