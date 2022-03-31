#include<iostream>
#include<string>

using namespace std;

class Player
{
private:
    string firstName;
    string secondName;
    int points;

public:
    Player();
    Player(string, string, int);
    ~Player();
    friend ostream& operator<<(ostream &, const Player &);
    friend istream& operator>>(istream &, Player &);

    int get_puncte_player();
    void setpunct();
};