#include <queue>
using namespace std;
void initalize(int n,int m,int Ppos[],const int Kpos_,const int Xpos_);
bool Checkmate(const int Kpos_,int X);
int canDown(int Ppos[],int X,int m,int n);
int canRight(int Ppos[],int X,int m,int n);
int canLeft(int Ppos[],int X,int m,int n);
int canUp(int Ppos[],int X,int m,int n);
void printinitial(int Ppos[],const int Kpos_,const int Xpos_,int n,int m);
void printsolution(queue<int> sol,int Ppos[],const int Kpos_,const int Xpos_,int n,int m);
