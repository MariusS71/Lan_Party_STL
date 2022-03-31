#include <iostream>
#include<list>
#include<set>
#include<map>
#include<fstream>
#include<queue>
#include <iomanip>
#include"Node.h"
using namespace std;

void creeazalista(list<Team> &head, int &n, fstream &f)
{

    f>>n;
    Team aux;
    f>>aux;
    head.push_front(aux);
    for(int i=1; i<n; i++)
    {
        f>>aux;
        head.push_front(aux);
    }
}

void afiseazalista(list<Team> & head, ostream & dev)
{
    for(list<Team>::iterator it=head.begin(); it!=head.end(); ++it)
    {
        dev<<(*it);
        dev<<endl;
    }

}

void structureaza(list<Team> & head, int &n)
{
    int i=1;
    while(i<=n)
    {
        i=i*2;
    }
    i=i/2;  //i va fi nr de echipe care trebuie sa ramana in lista
    while(i!=n) //eliminarea echipelor pana la i
    {
        //calculam minimul
        int min=head.begin()->get_puncte_team();
        for(list<Team>::iterator it=head.begin(); it!=head.end(); ++it)
        {
            if(min>(it->get_puncte_team()))
            {
                min=it->get_puncte_team();
            }
        }

        //se elimina echipa cu punctajul minim
        for(list<Team>::iterator it=head.begin(); it!=head.end(); ++it)
        {
            if(min==(it->get_puncte_team()))
            {
                head.erase(it);
                break;
            }
        }
        n--;
    }
}

void makecoada(queue<Match> &meci, list<Team>& head )
{
    for(list<Team>::iterator it=head.begin(); it!=head.end(); ++it)
    {
        Match *aux=new Match((*it),(*(++it)));
        meci.push(*aux);
    }
}

void afisarecoada(ostream & dev, queue<Match>  meci)
{
    while (!meci.empty()){
        string size="                                 -                                 ";
        size=size.substr(0, size.length()-meci.front().getTeam2().getnumeteam().length());
        size.erase(0, meci.front().getTeam1().getnumeteam().length());

        dev<<meci.front().getTeam1()<<size<<meci.front().getTeam2()<<endl;

        meci.pop();
    }
}

void stive(queue<Match>& meci, list<Team>&win, list<Team>&lose) {
    while(!meci.empty())
    {
        if(meci.front().getTeam1().get_puncte_team() > meci.front().getTeam2().get_puncte_team())
        {
            win.push_front(meci.front().getTeam1());
            lose.push_front(meci.front().getTeam2());
            meci.pop();
        }
        else
        {
            win.push_front(meci.front().getTeam2());
            lose.push_front(meci.front().getTeam1());
            meci.pop();
        }
    }
}

void adaugapuncte(list<Team>&win)
{
    for(list<Team>::iterator it=win.begin(); it!=win.end(); ++it)
    {
        it->pluspct_team();
    }
}

void afiseazalista_puncte(list<Team>&win, ostream &dev)
{
    for(list<Team>::iterator it=win.begin(); it!=win.end(); ++it)
    {
        string size="                                  -  ";
        size.erase(0, it->getnumeteam().length());
        dev<<left<<(*it)<<size;
        dev<<fixed<<setprecision(2);
        dev<<right<<(double)it->getmedie();
        dev<<endl;
    }
}

void joaca(queue<Match> & meci, int &n, list<Team>& last8, ostream & f)
{

    int i=0;
    f<<endl;
    while(n!=1) //se repeta ciclul pana ramane o singura echipa
    {
        i++;
        f << "--- ROUND NO:" << i << endl;
        afisarecoada(f, meci);

        list<Team> win, lose;
        stive(meci, win, lose);//apel de creeare a stivelor

        //adaugare punte pentru wineri
        adaugapuncte(win);

        //afisare  Liste lose win
        f << endl;
        f << "WINNERS OF ROUND NO:" << i << endl;
        afiseazalista_puncte(win, f);
        if (n != 2)
            f << endl;

        n = n / 2;

        //salvarea ultimelor 8 echipe
        if (n == 8) {
            last8=win;
        }

        //extragerea elementelor din lista win inapoi in coada

        if(n!=1)
            makecoada(meci, win);

        //stergere liste win si lose
        win.empty();
        lose.empty();
    }
}


void makearbore(set<Team, my_compare >& root, list<Team>& last8)
{
    for(list<Team>::iterator it=last8.begin(); it!=last8.end(); ++it)
    {
        root.insert(*it);
    }
}

void afisarearbore(set<Team, my_compare >& root, ostream &f)
{
    for(set<Team, my_compare >::reverse_iterator it=root.rbegin(); it!=root.rend(); ++it)
    {
        string size="                                  -  ";
        size.erase(0, it->getnumeteam().length());
        f<<*it<<size;

        f<<fixed<<setprecision(2);
        f<<std::right<<it->getmedie()<<endl;
    }
}
/*
void makeAVL(set<Team, my_compare> &nod, list<Team> &last8)
{
    for(list<Team>::iterator it=last8.begin(); it!=last8.end(); ++it)
    {
       nod.insert(*it);
    }
}

void printLevel2(set<Team, my_compare> &nod, ostream &f)
{
    int i=2;
    for(set<Team, my_compare>::reverse_iterator it=nod.rbegin(); it!=nod.rend(); ++it)
    {
       if(i%2==0)
       {
           f<<it->getnumeteam();
           f<<endl;
       }
        i++;
    }

}
*/


bool notmy_compare(const Team &a, const Team &b)
{
    return !(my_compare()(a,b));
}


void makeAVL(Node *&node, list<Team> &last8)
{
    Node *apel;
    for(list<Team>::iterator it=last8.begin(); it!=last8.end(); ++it)
    {
        node=apel->insert(node, *it);
    }
}




