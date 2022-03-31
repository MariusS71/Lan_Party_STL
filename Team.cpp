#include <iostream>
#include<string>
#include<string.h>
#include"Team.h"
using namespace std;

Team::Team()
{
//	cout<<"constr fara param Team"<<endl; 
    nr=0;
    nume="";
    v=NULL;
}

Team::Team(int nr, string n, Player* p)
{
//	cout<<"constr cu param Team"<<endl; 

    this->nr=nr;

    nume=n;

    if(p!=NULL)
    {
        v=new Player[nr];
        for(int i=0; i<nr; i++)
        {
            v[i]=p[i];
        }
    }
    else
    {
        v=NULL;
    }
}

Team::~Team()
{
//	cout<<"Destructor team"<<endl;
    if(v!=NULL)
    {
        delete []v;
    }
}

ostream& operator<<(ostream &dev, const Team &t)
{
//	dev<<t.nr<<" ";
    dev<<t.nume;
/*	if(t.v!=NULL)
	{
		for(int i=0; i<t.nr; i++)
		{
			dev<<t.v[i]<<endl;
		}
	}*/
    return dev;
}

istream & operator >> (istream & dev, Team &t)
{
    dev>>t.nr;
    getline(dev, t.nume);
    t.nume.erase(0,1);

    if(t.nume[t.nume.length()-1]==' ')
    {
        t.nume.erase(t.nume.length()-1 ,t.nume.length());
    }

    t.v=new Player[t.nr];
    for(int i=0; i<t.nr; i++)
    {
        dev>>t.v[i];
    }
    return dev;
}

Team& Team::operator=(const Team& t)
{

//	cout<<"Operator egal team"<<endl;
    if(this!=&t)
    {
        nr=t.nr;
        nume=t.nume;
        if(v!=NULL)
        {
            delete []v;
        }

        if(t.v!=NULL)
        {
            v=new Player[nr];
            for(int i=0; i<nr; i++)
            {
                v[i]=t.v[i];
            }
        }
        else
        {
            v=NULL;
        }
    }
    return *this;
}

Team::Team(const Team &t)
{
//	cout<<"Constr de copiere team"<<endl;
    if(v!=NULL)
    {
        v=NULL;
    }
    *this=t;
}

int Team::get_puncte_team() const {
    int puncte=0;
    for(int i=0; i<nr; i++)
    {
        puncte=puncte+v[i].get_puncte_player();
    }
    return puncte;
}

double Team::getmedie() const {
    double a=this->get_puncte_team();
    a=a/nr;
    return a;
}

void Team::pluspct_team()
{
    for(int i=0; i<nr; i++)
    {
        v[i].setpunct();
    }
}

string Team::getnumeteam() const {
    return nume;
}

bool operator==(const Team &a, const Team &b) {
    if(a.nume==b.nume)
        return true;
    else
        return false;
}

bool my_compare::operator()(const Team &x,const Team &y) {
    if (x.getmedie()<y.getmedie())
        return true;
    else if (x.getmedie()>y.getmedie())
        return false;
    else
    {
        if(x.getnumeteam()<y.getnumeteam())
            return true;
        else
            return false;
    }
}
