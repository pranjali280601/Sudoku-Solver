 #include <iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define lli long long int
#define precise(x) fixed << setprecision(x) 
const int m = 1e9+7;
bool isvalid(vector<vector<int>>&board,int x,int y,int val){

    for(int i=0;i<9;i++)
    if(board[i][y]==val)
    return false;    
    for(int i=0;i<9;i++)
    if(board[x][i]==val)
    return false;
    
    int bi=x/3*3;
    int bj=y/3*3;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if(board[i+bi][j+bj]==val)
    return false;
    
    return true;
}
void solve(vector<vector<int>>&board,int i,int j){
    if(i==9)
    {
        for(int l=0;l<9;l++){
        for(int m=0;m<9;m++)
        cout<<board[l][m]<<" ";
        cout<<endl;
        }
        return;
    }
    int ni=0;
    int nj=0;
    if(j==8){
        nj=0;
        ni=i+1;
    }
    else{
        nj=j+1;
        ni=i;
    }
    if(board[i][j]!=0)
    solve(board,ni,nj);
    else{
    for(int k=1;k<=9;k++){
        if(isvalid(board,i,j,k)){
           
            board[i][j]=k;
            solve(board,ni,nj);
            board[i][j]=0;
        }
        
    }
    }
}
int main()
{
    int r=9,c=9;
   vector<vector<int>>board(9,vector<int>(9));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cin>>board[i][j];
    }
    solve(board,0,0);
     
     
  return 0;
}
