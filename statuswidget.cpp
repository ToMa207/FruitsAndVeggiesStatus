#include "statuswidget.h"
#include <QPainter>

StatusWidget::StatusWidget(QWidget *parent)
    : QWidget{parent}
{
    this->diameter_ = 10;
    this->state_ = false;
    this->color_ = QColor("white");
}

double StatusWidget::diameter() const
{
    return diameter_;
}

void StatusWidget::setDiameter(double diameter)
{
    diameter_ = diameter;
    update();
}

bool StatusWidget::state() const
{
    return state_;
}

void StatusWidget::setState(bool state)
{
    state_ = state;
    color_ = state_ ? QColor("red") : QColor("white");
    update();
}

void StatusWidget::toggleState()
{
    state_ = !state_;
    color_ = state_ ? QColor("red") : QColor("white");
    update();
}

void StatusWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter p(this);

    QRect boundingBox = geometry();
    int height = boundingBox.height();
    int x = boundingBox.left() - 25;
    int y = (height - diameter_)/2;

    p.setPen(QColor("black"));
    p.setBrush(QBrush(color_));
    p.drawEllipse(x, y, diameter_, diameter_);
}
