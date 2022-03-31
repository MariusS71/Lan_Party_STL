#include <iostream>
#include"player.h"
#include<string>
using namespace std;

class Team
{
private:
    int nr;
    string nume;
    Player *v;

public:
    Team();
    Team(int, string,Player*);
    ~Team();
    friend ostream& operator<<(ostream &, const Team &);
    friend istream& operator>>(istream &, Team &);
    friend bool operator==(const Team&, const Team&);
    Team& operator=(const Team&);
    Team(const Team &);
    int get_puncte_team() const;
    double getmedie() const;
    void pluspct_team();
    string getnumeteam() const;
};
class my_compare {
public:
    bool operator()(const Team &x, const Team &y);

};

