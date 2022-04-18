#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QObject>
#include <QWidget>

class StatusWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double diameter READ diameter WRITE setDiameter)
    Q_PROPERTY(bool state READ state WRITE setState)

    double diameter() const;
    void setDiameter(double diameter);

    bool state() const;

public slots:
    void setState(bool state);
    void toggleState();

public:
    explicit StatusWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event);

private:
    double diameter_;
    QColor color_;
    bool state_;
};

#endif // STATUSWIDGET_H
