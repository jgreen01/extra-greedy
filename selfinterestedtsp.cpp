#include "selfinterestedtsp.h"

#include "qdebug.h"

#include <math.h>
#include <time.h>

struct cityLoc{
    float x;
    float y;
};

SelfInterestedTSP::SelfInterestedTSP(int N_in)
{
    N = N_in;

    cities = (struct cityLoc*) malloc (N * sizeof(struct cityLoc));

    greedyCityPath = (int*) malloc (N * sizeof(int));
    memset(greedyCityPath, 1, sizeof(int)*N); // sets memory to 16843009
    //(arbitrary anyways)

    genCities();
    greedy();
    displaySelfishPath();
}

void SelfInterestedTSP::greedy(){
    int bestCityIndex = 0;

    for(int i = 0; i < N; i++){ // loops through all cities
        float minDist = 9999, dist;

        greedyCityPath[i] = bestCityIndex;

        for(int j = 0; j < N; j++){ // find best next city from all cities
            bool isCityInPath = false;

            for(int k = 0; (k < N) && !isCityInPath; k++)
                if(greedyCityPath[k] == j)  // makes sure the city isn't used
                    isCityInPath = true;

            if(!isCityInPath){ // if it's not used then test if minDist

                // find dist between prev best city and other cities
                dist = cityDis(cities[greedyCityPath[i]], cities[j]);

                if((minDist >= dist) && (dist != 0)){
                    minDist = dist;
                    bestCityIndex = j;
                }
            }
        }
    }
}

void SelfInterestedTSP::displaySelfishPath(){
    for(int i = 0; i < N; i++)
        qDebug() << "greedyCityPath[" << i << "]: " << greedyCityPath[i];
}

float SelfInterestedTSP::cityDis(struct cityLoc frst, struct cityLoc scnd){
    // sqrt(dX^2 + dY^2)
    return sqrt((frst.y - scnd.y)*(frst.y - scnd.y) +
                (frst.x - scnd.x)*(frst.x - scnd.x));
}

void SelfInterestedTSP::genCities(){
    srand(time(NULL));

    // generate random locations for my cities
    for(int i = 0; i < N; i++){
        cities[i].x = (float)rand()/(float)RAND_MAX;
        cities[i].y = (float)rand()/(float)RAND_MAX;
    }
}
