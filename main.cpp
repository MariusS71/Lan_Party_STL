#include <iostream>
#include<list>
#include<map>
#include<set>
#include<queue>
#include"Node.h"
#include<fstream>
using namespace std;

void creeazalista(list<Team> &, int &, fstream &);
void afiseazalista(list<Team> &, ostream &);
void structureaza(list<Team> &, int &);
void makecoada(queue<Match>&, list<Team> &);
void joaca(queue<Match> &, int &, list<Team>&, ostream &);
void afisarecoada(ostream &, queue<Match> );
void stive(queue<Match>&, list<Team>&, list<Team>&);
void adaugapuncte(list<Team>&);
void afiseazalista_puncte(list<Team>&, ostream &);
void makearbore( set<Team, my_compare >&, list<Team>&);
void afisarearbore( set<Team, my_compare >&, ostream &);
void makeAVL(set<Team, my_compare >&, list<Team>&);
void printLevel2(set<Team, my_compare >&, ostream &);
bool notmy_compare(const Team &, const Team &);
void makeAVL(Node *& ,list<Team>&);

int main(int argc, char *argv[]) {
    fstream c(argv[1], ios::in);
    if(!c)
    {
        cout<<"Eroare la deschidere c.in!"<<endl;
    }
    fstream d(argv[2], ios::in);
    if(!d)
    {
        cout<<"Eroare la deschidere d.in!"<<endl;
    }
    fstream r(argv[3], ios::out);
    if(!r)
    {
        cout<<"Eroare la deschidere r.out!"<<endl;
    }

    int n;
    list<Team> head, last8;
    queue<Match> meci;
    set<Team, my_compare> root;
    //set<Team, my_compare > nod;
    Node *nod, *last;
    nod=NULL;

    int task[5];
    for (int i = 0; i < 5; i++)
    {
        c>> task[i];
    }
    for (int i = 0; i < 5; i++) {
        switch (i) {
            case 0: {
                if (task[0] == 1)
                {
                    creeazalista(head, n, d);  //construieste lista initiala
                    if(task[1]==0)					//conditie pentru c.in: 1 0 0 0 0
                    afiseazalista(head, r);
                }
                break;

            }
            case 1: {
                if (task[1] == 1)
                {
                    structureaza(head, n);  //structureaza in asa fel incat sa ramana 2^k echipe
                    afiseazalista(head, r);
                }
                break;

            }
            case 2: {
                if (task[2] == 1)
                {
                    makecoada(meci, head);
                    joaca(meci, n, last8, r); //jucarea rundelor
                }
                break;
            }
            case 3: {
                if (task[3] == 1)
                {
                    makearbore(root, last8);
                    r<<endl;
                    r<<"TOP 8 TEAMS:"<<endl;
                    afisarearbore(root,r);
                }
                break;
            }
            case 4: {
                if (task[4] == 1)
                {
                    last8.sort(notmy_compare);
                    makeAVL(nod, last8);
                    r<<endl<<"THE LEVEL 2 TEAMS ARE:"<<endl;
                    last->printGivenLevel(nod, 3, r);
                    last->delet(nod);//stergere arbore

                }
                break;
            }
            default: {
                cout << "Error! " << endl;
                break;
            }
        }

    }
    last8.clear();
    head.clear();
    root.clear();

    r.close();
    c.close();
    d.close();
    return 0;
}
