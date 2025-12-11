#include <QtWidgets>
#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent): QWidget(parent)
{
    /* ROUGE */
    sliderR = new QSlider(Qt::Vertical);
    sliderR->setMaximum(255);
    spinR = new QSpinBox;
    spinR->setMaximum(255);
    QVBoxLayout *layoutR = new QVBoxLayout();
    layoutR->addWidget(sliderR);
    layoutR->addWidget(spinR);

    /* VERT */
    sliderG = new QSlider(Qt::Vertical);
    sliderG->setMaximum(255);
    spinG = new QSpinBox;
    spinG->setMaximum(255);
    QVBoxLayout *layoutG = new QVBoxLayout();
    layoutG->addWidget(sliderG);
    layoutG->addWidget(spinG);

    /* BLEU */
    sliderB = new QSlider(Qt::Vertical);
    sliderB->setMaximum(255);
    spinB = new QSpinBox;
    spinB->setMaximum(255);
    QVBoxLayout *layoutB = new QVBoxLayout();
    layoutB->addWidget(sliderB);
    layoutB->addWidget(spinB);

    /* LAYOUT HORIZONTAL */
    QHBoxLayout *layoutRGB = new QHBoxLayout();
    layoutRGB->addLayout(layoutR);
    layoutRGB->addLayout(layoutG);
    layoutRGB->addLayout(layoutB);

    /* LABEL COULEUR */
    labelCouleur = new QLabel("#FFFFFF");
    labelCouleur->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    labelCouleur->setAutoFillBackground(true);

    /* LAYOUT PRINCIPAL */
    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addLayout(layoutRGB);
    layoutMain->addWidget(labelCouleur);
    setLayout(layoutMain);

    /* CONNEXION SLIDER ET SPIN BOX */
    connect(sliderR, SIGNAL(valueChanged(int)), spinR, SLOT(setValue(int)));
    connect(spinR, SIGNAL(valueChanged(int)), sliderR, SLOT(setValue(int)));

    connect(sliderG, SIGNAL(valueChanged(int)), spinG, SLOT(setValue(int)));
    connect(spinG, SIGNAL(valueChanged(int)), sliderG, SLOT(setValue(int)));

    connect(sliderB, SIGNAL(valueChanged(int)), spinB, SLOT(setValue(int)));
    connect(spinB, SIGNAL(valueChanged(int)), sliderB, SLOT(setValue(int)));

    /* CONNEXION VERS LES SLOTS */
    connect(sliderR, SIGNAL(valueChanged(int)), this, SLOT(RedAdjust(int)));
    connect(sliderG, SIGNAL(valueChanged(int)), this, SLOT(GreenAdjust(int)));
    connect(sliderB, SIGNAL(valueChanged(int)), this, SLOT(BlueAdjust(int)));

    Init();
}

void MyWidget::RedAdjust(int value)
{
    QPalette palette;
    palette.setColor(QPalette::Base, QColor(value, 0, 0));
    palette.setColor(QPalette::Text, Qt::white);
    spinR->setPalette(palette);
    RGBAdjust();
}

void MyWidget::GreenAdjust(int value)
{
    QPalette palette;
    palette.setColor(QPalette::Base, QColor(0, value, 0));
    palette.setColor(QPalette::Text, Qt::white);
    spinG->setPalette(palette);
    RGBAdjust();
}

void MyWidget::BlueAdjust(int value)
{
    QPalette palette;
    palette.setColor(QPalette::Base, QColor(0, 0, value));
    palette.setColor(QPalette::Text, Qt::white);
    spinB->setPalette(palette);
    RGBAdjust();
}

void MyWidget::Init()
{
    sliderR->setValue(255);
    sliderG->setValue(255);
    sliderB->setValue(255);
}

void MyWidget::RGBAdjust()
{
    int r = sliderR->value();
    int g = sliderG->value();
    int b = sliderB->value();

    QColor couleur(r, g, b);
    QPalette palette;
    palette.setColor(QPalette::Window, couleur);
    labelCouleur->setPalette(palette);
    labelCouleur->setText(couleur.name().toUpper());
}
