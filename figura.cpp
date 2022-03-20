#include <math.h>
#include "figura.h"



const QPointF rotate(QPointF point, QPointF center, double angle)
{
    point = QPointF(point.x()-center.x(), point.y()-center.y());
    point = QPointF(point.x()*cos(angle) - point.y()*sin(angle),point.x()*sin(angle) + point.y()*cos(angle));
    point = QPointF(point.x()+center.x(), point.y()+center.y());
    return point;
}

void drawRect(QPainter *Painter, QPointF rect[4])
{
    Painter->drawLine(rect[0].x(),rect[0].y(),rect[1].x(),rect[1].y());
    Painter->drawLine(rect[1].x(),rect[1].y(),rect[2].x(),rect[2].y());
    Painter->drawLine(rect[2].x(),rect[2].y(),rect[3].x(),rect[3].y());
    Painter->drawLine(rect[3].x(),rect[3].y(),rect[0].x(),rect[0].y());
}

void drawPoint(QPainter *Painter, QPointF point)
{
    Painter->drawPoint(point.x(), point.y());
}

void drawLine(QPainter *Painter,  QPointF line[2])
{
 Painter->drawLine(line[0].x(), line[0].y(), line[1].x(), line[1].y());
}
