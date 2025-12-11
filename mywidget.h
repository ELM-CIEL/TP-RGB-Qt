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
        MyWidget(QWidget *parent=0);

    protected slots:
        void horizontalSlider_Rouge(int value);
        void horizontalSlider_Vert(int value);
        void horizontalSlider_Bleu(int value);

    private:
        /* Je dois ajouter les widgets & méthodes privées*/
        QSlider *sliderR;
        QSlider *sliderG;
        QSlider *sliderB;

        QSpinBox *spinBoxR;
        QSpinBox *spinBoxG;
        QSpinBox *spiBoxB;

        QLabel *labelCouleur;

        void init();
        void changeCouleur();
};

#endif // MYWIDGET_H
