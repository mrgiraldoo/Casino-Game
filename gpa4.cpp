#include <iostream>
using namespace std;
#include <stdio.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<vector>

class game{
    int n;//number of players
    int w; //amount of win
    public:
    vector<int> money;
    game(int players, int win){
        n = players;
        w = win;
        int m;
        for(int i=0;i<n;i++){
            cout << "enter amount of player "<< i+1 << endl;
            cin >> m;
            money.push_back(m);
        }
        cout << "All players loaded succesfully" << endl;        
    }
    void visual();

    void royale(int n, int w, vector<int> &money, bool &flag);
    

};

void game::visual(){
    vector <int>::iterator it;
        for(it=money.begin(); it!=money.end(); it++){
            cout<< *it << endl;
        }
}

void game::royale(int n, int w, vector<int> &money, bool &flag){
    if (n==2){
        cout << "Game might end";
        flag = true;
        return;
    }else{
        vector <int>::iterator it;
        vector <int>::iterator jt;
        int foulCount=0;
        for (it = money.begin(); it != money.end(); it++){
            for(jt =money.begin(); jt !=money.end(); jt++){
                if((*it!=*jt) && ((*it-*jt)%(w+1)!=0)){
                    foulCount++;
                }
            }
        }
        if(foulCount/2 > (n-1)){
            cout << "Game won't end, there are " << foulCount << " Cases which don't comply\n";
            flag = false;
        }else{
            cout << "Game might end\n";
            flag = true;
        }
    }

}

int main(){
    int n;
    int w;
    bool flag;

    cout << "Welcome to Royal, enter number of players: " << endl;
    cin >> n;
    cout << "Now enter amount to win in each round please " << endl;
    cin >> w;

    game g(n, w);

    g.visual();
    g.royale(n, w, g.money, flag);


    return 0;
}

