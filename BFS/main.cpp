#include <iostream>
#include <queue>
#include <ctime>
#include <stdlib.h>
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
        if(!(a<=n && b<=m)){ cout << "error location."; }
        else
        {
            system("cls");
            int boardlen=(n+2)*(m+2)+1;
            int Ppos[boardlen];
            const int Kpos_=a*(m+2)+b;;
            const int Xpos_=1*(m+2)+1;
            queue<queue<int>> steps;
            bool found = false;
            initalize(n,m,Ppos,Kpos_,Xpos_);
            printinitial(Ppos,Kpos_,Xpos_,n,m);
            start = clock();
            //BFS
            queue<int> new_;
            queue<int> ini;
            ini.push(Xpos_);
            steps.push(ini);
            while(!steps.empty())
            {
                initalize(n,m,Ppos,Kpos_,Xpos_);
                queue<int> now_=steps.front();
                new_=steps.front();
                int X;
                while(!now_.empty())//translate
                {
                    X=now_.front();
                    Ppos[X]=0;//eaten
                    now_.pop();
                }
                //search Down,Right,Left,Up
                int nextX;
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
                    else{ steps.push(new_); }
                }
                new_=steps.front();
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
                    else{ steps.push(new_); }
                }
                new_=steps.front();
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
                    else{ steps.push(new_); }
                }
                new_=steps.front();
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
                    else{ steps.push(new_); }
                }
                steps.pop();
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
