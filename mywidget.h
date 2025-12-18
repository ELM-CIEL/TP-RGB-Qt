#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QLabel>
#include <QStringListModel>
#include <QListView>
#include <QPushButton>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = 0);

protected slots:
    void RedAdjust(int value);
    void GreenAdjust(int value);
    void BlueAdjust(int value);

    //Itération 2
    void ColorChoice(const QModelIndex & model);
    void ColorKeep();

private:
    // Widgets privés
    QSlider *sliderR;
    QSlider *sliderG;
    QSlider *sliderB;

    QSpinBox *spinR;
    QSpinBox *spinG;
    QSpinBox *spinB;

    QLabel *labelCouleur;

    //itéraiton 2 : list de couleur
    QStringListModel *modeleCouleurs;
    QListView *vueCouleurs;

    //Bouton conservé
    QPushButton *boutonConserver;
    QLabel *choix[6];
    int indexChoix;

    // Méthodes privées
    void Init();
    void RGBAdjust();
};

#endif // MYWIDGET_H
