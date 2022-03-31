#include <iostream>
#include"Team.h"
#include<string>
using namespace std;

class Match {
        Team t1;
        Team t2;

public:
    Match(){};
    Match(Team&, Team&);

    Team getTeam1();
    Team getTeam2();
};
