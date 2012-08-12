#include "tspgraphic.h"

#include "qpainter.h"
#include "qtimer.h"
#include "qdebug.h"

#include "selfinterestedtsp.h"

tspGraphic::tspGraphic(QWidget *parent) :
    QWidget(parent)
{
    N = 1000;
    numDotsToDraw = 0;

    SelfInterestedTSP *selfish = new SelfInterestedTSP(N);

    cities = selfish->cities;
    greediestPath = selfish->greedyCityPath;

    myTimer = new QTimer(this);
    myTimer->setInterval(200);
    myTimer->start();

    QObject::connect(myTimer,SIGNAL(timeout()),this,SLOT(connectDots()));
}

tspGraphic::~tspGraphic(){

}

void tspGraphic::paintEvent(QPaintEvent *){
    int width,height;
    float currX, currY;
    float beginX,beginY,endX,endY;

    width = 600;
    height = 600;

    QPainter p(this);

    QColor myBrushColor, myPenColor;

    myBrushColor.setRgb(0,255,0);
    myPenColor.setRgb(0,0,0);

    QBrush myBrush;
    myBrush.setColor(myBrushColor);
    myBrush.setStyle(Qt::SolidPattern);
    p.setBrush(myBrush);

    QPen myPen;
    myPen.setColor(myPenColor);
    myPen.setWidth(1);
    p.setPen(myPen);

    for(int i = 0; i < N; i++){
        currX = getCoordinate(cities[i].x,width,20);
        currY = getCoordinate(cities[i].y,height,10);

        p.drawEllipse(currX-5,currY-5,10,10);
        //p.drawPoint(currX,currY);
    }

    for(int i = 0; i < numDotsToDraw; i++){
        beginX = getCoordinate(cities[greediestPath[i]].x,width,20);
        beginY = getCoordinate(cities[greediestPath[i]].y,height,10);

        if(i+1 == N){ // so I'll connect to the beginning
            endX = getCoordinate(cities[greediestPath[0]].x,width,20);
            endY = getCoordinate(cities[greediestPath[0]].y,height,10);
        } else {
            endX = getCoordinate(cities[greediestPath[i+1]].x,width,20);
            endY = getCoordinate(cities[greediestPath[i+1]].y,height,10);
        }

        p.drawLine(beginX,beginY,endX,endY);
    }
}

float tspGraphic::getCoordinate(float coord, float sceenDim, float offset){
    return (coord * sceenDim) + offset;
}

void tspGraphic::sliderEventHandler(int sliderValue){
    N = sliderValue;
    numDotsToDraw = 0;
    SelfInterestedTSP *selfish = new SelfInterestedTSP(N);

    cities = selfish->cities;
    greediestPath = selfish->greedyCityPath;

    update();
}

void tspGraphic::connectDots(){
    if(numDotsToDraw < N){
        numDotsToDraw++;
        update();
    }
}
