#include <iostream>
#include <queue>
#include <stack>
#include <ctime>
#include "functions.h"
using namespace std;
void initalize(int n,int m,int Ppos[],int Kpos_,int Xpos_)
{
    for(int i=0 ; i<n+2 ; i++)//-----------------initalize board
    {
        for(int j=0 ; j<m+2 ; j++)
        {
            if(i==0 || i==n+1)
            {
                Ppos[i*(m+2)+j]=-1;//放牆
            }
            else if(j==0 || j==m+1)
            {
                Ppos[i*(m+2)+j]=-1;//放牆
            }
            else
            {
                Ppos[i*(m+2)+j]=1;//放卒
            }
        }
    }
    Ppos[Kpos_]=1;//將
    Ppos[Xpos_]=0;//砲//-----------------initalize board end
}
bool Checkmate(const int Kpos_,int X)
{
    return Kpos_==X;
}
int canDown(int Ppos[],int X,int m,int n)
{
    int i=X;
    int ps=0;
    while(Ppos[i]!=-1)
    {
        if(ps==1 && Ppos[i]==1)
        {
            return i;
        }
        else
        {
            ps+=Ppos[i];
            i+=(m+2);
        }
    }
    return -1;
}
int canRight(int Ppos[],int X,int m,int n)
{
    int i=X;
    int ps=0;
    while(Ppos[i]!=-1)
    {
        if(ps==1 && Ppos[i]==1)
        {
            return i;
        }
        else
        {
            ps+=Ppos[i];
            i+=1;
        }
    }
    return -1;
}
int canLeft(int Ppos[],int X,int m,int n)
{
    int i=X;
    int ps=0;
    while(Ppos[i]!=-1)
    {
        if(ps==1 && Ppos[i]==1)
        {
            return i;
        }
        else
        {
            ps+=Ppos[i];
            i-=1;
        }
    }
    return -1;
}
int canUp(int Ppos[],int X,int m,int n)
{
    int i=X;
    int ps=0;
    while(Ppos[i]!=-1)
    {
        if(ps==1 && Ppos[i]==1)
        {
            return i;
        }
        else
        {
            ps+=Ppos[i];
            i-=(m+2);
        }
    }
    return -1;
}
void printinitial(int Ppos[],int Kpos_,const int Xpos_,int n,int m)
{
    for(int i=1 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<m+2 ; j++)
        {
            if(i*(m+2)+j==Xpos_)cout << "x";
            else if(i*(m+2)+j==Kpos_)cout << "k";
            else if(Ppos[i*(m+2)+j]==1)cout << "o";
        }
        cout << endl;
    }
}
void printsolution(queue<int> sol,int Ppos[],const int Kpos_,const int Xpos_,int n,int m)
{
    int step=1;
    Ppos[sol.front()]=2;//eaten
    sol.pop();
    cout << "An optimal solution has " << sol.size() << " steps:" << endl;
    while(!sol.empty())
    {
        Ppos[sol.front()]=2;//eaten
        cout << "step " << step << endl;
        for(int i=1 ; i<n+1 ; i++)
        {
            for(int j=0 ; j<m+2 ; j++)
            {
                if(i*(m+2)+j==sol.front())cout << "x";
                else if(i*(m+2)+j==Kpos_)cout << "k";
                else if(Ppos[i*(m+2)+j]==1)cout << "o";
                else if(Ppos[i*(m+2)+j]==2)cout << ".";
            }
            cout << endl;
        }
        cout << endl;
        sol.pop();
        step+=1;
    }
}
