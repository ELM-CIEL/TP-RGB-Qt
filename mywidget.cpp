#include <QtWidgets>
#include <QColor>
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

    /* ITERATION 2 : LISTE DE COULEUR */
    QStringList listeCouleur = QColor::colorNames();
    QStringListModel *modeleCouleurs = new QStringListModel(listeCouleur);
    QListView *vueCouleurs = new QListView;
    vueCouleurs->setModel(modeleCouleurs);

    // BOUTON CONSERVER AVEC SLOTS
    boutonConserver = new QPushButton("Conserver");

    QHBoxLayout *layoutChoix = new QHBoxLayout();
    for (int i = 0; i < 6; i++)
    {
        choix[i] = new QLabel("Choix" + QString::number(i + 1));
        choix[i]->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        choix[i]->setAutoFillBackground(true);
        layoutChoix->addWidget(choix[i]);
    }
    indexChoix =0;

    /* LAYOUT PRINCIPAL */
    QVBoxLayout *layoutGauche = new QVBoxLayout();
    layoutGauche->addLayout(layoutRGB);
    layoutGauche->addWidget(labelCouleur);
    layoutGauche->addWidget(boutonConserver);
    layoutGauche->addLayout(layoutChoix);

    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addLayout(layoutGauche);
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

    /* ITERATION 2 : SIGNAL */
    connect(vueCouleurs, SIGNAL(clicked(const QModelIndex &)),
            this, SLOT(ColorChoice(const QModelIndex &)));
    // bouton conserver
    connect(boutonConserver, SIGNAL(clicked()),
            this, SLOT(ColorKeep()));

    sliderR->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sliderG->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sliderB->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


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

void MyWidget::ColorChoice(const QModelIndex &model)
{
    QVariant nom = model.data(Qt::DisplayRole);
    QColor c(nom.toString());

    if (c.isValid())
    {
        sliderR->setValue(c.red());
        sliderG->setValue(c.green());
        sliderB->setValue(c.blue());
    }
}

void MyWidget::ColorKeep()
{
    // couleur courante
    int r = sliderR->value();
    int g = sliderG->value();
    int b = sliderB->value();
    QColor c(r, g, b);

    // on met la couleur dans le QLabel courant
    QPalette palette;
    palette.setColor(QPalette::Window, c);
    choix[indexChoix]->setPalette(palette);
    choix[indexChoix]->setText(c.name().toUpper());

    // tampon circulaire : on avance, puis modulo 6
    indexChoix = (indexChoix + 1) % 6;
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
