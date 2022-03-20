#ifndef AREA_H
#define AREA_H
#include "figura.h"
#include <QWidget>

class Area : public QWidget
{
 int myTimer; // идентификатор таймера
 float alpha; // угол поворота квадрата вокруг своего центра
 float beta;  // угол поворота квадрата вокруг центра экрана
 float buf;
 QPointF center;
public:
 Area(QWidget *parent = 0);
 ~Area();
 QPointF myrect[4];
 QPointF rectCenter;
 QPointF* mypoint;
 QPointF myline[2];
protected:
// обработчики событий
 void paintEvent(QPaintEvent *event);
 void timerEvent(QTimerEvent *event);
 void showEvent(QShowEvent *event);
 void hideEvent(QHideEvent *event);
};
#endif // AREA_H
