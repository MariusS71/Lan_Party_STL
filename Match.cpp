#include <iostream>
#include<list>
#include"Match.h"
#include<fstream>
using namespace std;

Match::Match(Team &a, Team &b) {

        t1=a;
        t2=b;
}

Team Match::getTeam1() {
    return t1;
}

Team Match::getTeam2() {
    return t2;
}
