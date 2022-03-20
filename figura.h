#ifndef FIGURA_H
#define figura_h
#include <QtGui>
#include <QtMath>


    void drawRect(QPainter *Painter, QPointF[4]);
    void drawLine(QPainter *Painter, QPointF[2]);
    void drawPoint(QPainter *Painter, QPointF);
    const QPointF rotate(QPointF point, QPointF center, double angle);

#endif
