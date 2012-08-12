#ifndef TSPGRAPHIC_H
#define TSPGRAPHIC_H

#include <QWidget>

#include "selfinterestedtsp.h"

struct cityLoc{
    float x;
    float y;
};

class tspGraphic : public QWidget
{
    Q_OBJECT
public:
    explicit tspGraphic(QWidget *parent);
    ~tspGraphic();
    
signals:

private:
    void paintEvent(QPaintEvent *);
    float getCoordinate(float coord, float sceenDim, float offset);
    struct cityLoc *cities;
    int N;
    int *greediestPath;
    SelfInterestedTSP *selfish;
    QTimer *myTimer;
    float width;
    float height;
    int numDotsToDraw;

public slots:
    void sliderEventHandler(int sliderValue);
    void connectDots();
    
};

#endif // TSPGRAPHIC_H
