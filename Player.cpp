#include <iostream>
#include"player.h"
#include<string>
using namespace std;

Player::Player()
{
//	cout<<"constr fara param Player"<<endl;
    firstName="";
    secondName="";
    points=0;
}

Player::Player(string nume1, string nume2, int p)
{
//	cout<<"constr cu param Player"<<endl;
    firstName=nume1;
    secondName=nume2;
    points=p;
}

Player::~Player()
{
//	cout<<"Destructor player"<<endl;
}

ostream& operator<<(ostream &dev, const Player &p)
{
    dev<<p.firstName<<" ";
    dev<<p.secondName<<" ";
    dev<<p.points;
    return dev;
}

istream& operator>>(istream &dev,  Player &p)
{
    dev>>p.firstName;
    dev>>p.secondName;
    dev>>p.points;
    return dev;
}

int Player::get_puncte_player()
{
    return points;
}

void Player::setpunct()
{
    points=points+1;
}