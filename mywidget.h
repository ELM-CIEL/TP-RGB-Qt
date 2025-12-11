#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = 0);

protected slots:
    void RedAdjust(int value);
    void GreenAdjust(int value);
    void BlueAdjust(int value);

private:
    // Widgets privés
    QSlider *sliderR;
    QSlider *sliderG;
    QSlider *sliderB;

    QSpinBox *spinR;
    QSpinBox *spinG;
    QSpinBox *spinB;

    QLabel *labelCouleur;

    // Méthodes privées
    void Init();
    void RGBAdjust();
};

#endif // MYWIDGET_H
