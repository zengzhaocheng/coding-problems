//date:20220607
//problem number: 1347
//problem name: Tour 
//type: dynamics programming
//author: jackgnez

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000 + 10
int x[MAXN], y[MAXN];
double dp[MAXN][MAXN], dist[MAXN][MAXN];
int N;
double di(int a, int b){
    return hypot(x[a] - x[b], y[a] - y[b]);//h = √(x2+y2 
}
//recur a , b 代表的是 a，b之间的最短距离？
double recur(int a, int b){
    if(dp[a][b]!=-1.0) return dp[a][b];//如果已经被计算就返回
    //如果较大的那一个已经到了最后一个节点
    if (a==N-1){
        return dp[a][b] = dp[b][a] = dist[b][N-1];//那ab的距离就是b到最后一个节点的距离
    }
    //看成两个人走，a在前，b在后，后面是两种状态转移
    return dp[a][b] = dp[b][a] = min(recur(a+1,b) + dist[a][a+1], recur(a+1,a) + dist [b][a+1]);
}
int main(){
    cout<<fixed<<setprecision(2);
    while(cin>>N){
        for(int i = 0;i<N;i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = -1.0;
        for(int i = 0,a,b; i<N; i++)
            cin>>x[i]>>y[i];
        for(int i = 0; i<N-1;i++)
            for(int j = i+1;j<N;j++)
                dist[i][j] = dist[j][i] = di(i,j);
        cout<<recur(0,0)<<endl;
    }
}
