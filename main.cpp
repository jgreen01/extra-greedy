/*  Extracredit:
 *      traveling salesman problem
 *
 *  by:
 *      Jonathon Green
 */

#include <QtGui/QApplication>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "qgridlayout.h"
#include "qslider.h"
#include "qdebug.h"

#include "widget.h"
#include "tspgraphic.h"
#include "selfinterestedtsp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(660,680);
    w.show();

    QGridLayout *myLayout = new QGridLayout();

    tspGraphic *cityGraphic = new tspGraphic(&w);

    w.setLayout(myLayout);

    QSlider *mySlider = new QSlider();
    mySlider->setMinimum(2);
    mySlider->setMaximum(500);
    mySlider->setOrientation(Qt::Horizontal);

    myLayout->addWidget(cityGraphic,0,0);
    myLayout->addWidget(mySlider,2,0);

    QObject::connect(mySlider,SIGNAL(valueChanged(int)),cityGraphic,
                     SLOT(sliderEventHandler(int)));

    return a.exec();
}
