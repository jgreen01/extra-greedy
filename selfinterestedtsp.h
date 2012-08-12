#ifndef SELFINTERESTEDTSP_H
#define SELFINTERESTEDTSP_H

class SelfInterestedTSP
{

public:
    SelfInterestedTSP(int N_in);
    int *greedyCityPath;
    struct cityLoc *cities;

private:
    void greedy();
    void displaySelfishPath();
    void genCities();
    float cityDis(struct cityLoc frst, struct cityLoc scnd);
    int N;

};

#endif // SELFINTERESTEDTSP_H
