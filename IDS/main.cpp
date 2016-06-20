#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <ctime>
#include "functions.h"
clock_t start, stop;
using namespace std;
int main()
{
    int n,m;//n長,m寬
    int a,b;//將的位置
    cout << "Do you want to start the program THE CANNON CAPTURE THE KING?(Y/N):" ;
    char input;
    cin >> input;
    while(input=='Y' || input== 'y')
    {
        cout << "Please input the width and length of the chesscoard" << endl;
        cout << "AND the location of the KING(n m y x):";
        cin >> n >> m >> a >> b;
        if(!(a<=n && b<=m)){    cout << "error location.";  }
        else
        {
            system("cls");
            int boardlen=(n+2)*(m+2)+1;
            int Ppos[boardlen];//
            const int Kpos_=a*(m+2)+b;;
            const int Xpos_=1*(m+2)+1;
            stack<queue<int>> steps;
            queue<int> new_;
            bool found = false;
            initalize(n,m,Ppos,Kpos_,Xpos_);
            printinitial(Ppos,Kpos_,Xpos_,n,m);
            start = clock();
            //IDS search
            for(int depth=2 ; depth<n*m ; depth++)
            {
                queue<int> ini;
                ini.push(Xpos_);
                steps.push(ini);
                while(!steps.empty())
                {

                    queue<int> now_= steps.top();
                    steps.pop();
                    if(now_.size() < depth)
                    {
                        new_=now_;
                        queue<int> trans_=now_;
                        initalize(n,m,Ppos,Kpos_,Xpos_);
                        int X;
                        while(!trans_.empty())//translate
                        {
                            X=trans_.front();
                            Ppos[X]=0;//eaten
                            trans_.pop();
                        }
                        //search Down,Right,Left,Up
                        int nextX;
                        nextX=canUp(Ppos,X,m,n);
                        if(nextX!=-1)
                        {
                            new_.push(nextX);
                            if(Checkmate(Kpos_,nextX))
                            {
                                stop = clock();
                                found = true;
                                break;
                            }
                            else{   steps.push(new_);  }
                        }
                        new_=now_;
                        nextX=canLeft(Ppos,X,m,n);
                        if(nextX!=-1)
                        {
                            new_.push(nextX);
                            if(Checkmate(Kpos_,nextX))
                            {
                                stop = clock();
                                found = true;
                                break;
                            }
                            else{   steps.push(new_);  }
                        }
                        new_=now_;
                        nextX=canRight(Ppos,X,m,n);
                        if(nextX!=-1)
                        {
                            new_.push(nextX);
                            if(Checkmate(Kpos_,nextX))
                            {
                                stop = clock();
                                found = true;
                                break;
                            }
                            else{   steps.push(new_);  }
                        }
                        new_=now_;
                        nextX=canDown(Ppos,X,m,n);
                        if(nextX!=-1)
                        {
                            new_.push(nextX);
                            if(Checkmate(Kpos_,nextX))
                            {
                                stop = clock();
                                found = true;
                                break;
                            }
                            else{   steps.push(new_);  }
                        }
                    }
                }
                if(found)break;
            }
            if(found)
            {
                initalize(n,m,Ppos,Kpos_,Xpos_);
                printsolution(new_,Ppos,Kpos_,Xpos_,n,m);
            }
            else
            {
                stop = clock();
                cout << "No solution." << endl;
            }
            cout << "Total run time = " << double(stop - start) / CLOCKS_PER_SEC << " seconds" <<endl;
        }
        cout << endl;
        cout << "Do you want to start the program THE CANNON CAPTURE THE KING?(Y/N):" ;
        cin >> input;
    }
    return 0;
    system("pause");
}
