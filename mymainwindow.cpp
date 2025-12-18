#include <QtWidgets>
#include "mymainwindow.h"
#include "mywidget.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MyWidget *centralWidget = new MyWidget;
    setCentralWidget(centralWidget);
    setWindowTitle("Visionneur RGB v1");
    resize(400,500);


}
