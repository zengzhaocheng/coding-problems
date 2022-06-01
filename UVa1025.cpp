//date:20220525
//problem name: A Spy in the Metro
//author: jackgnez
#include "bits/stdc++.h";
using namespace std;

const int maxn = 50+5;
const int maxt = 200 + 5;
const int INF = 100000000;
//t是各站之间的旅行时间，has_train是在时间t，车站n初是否恰好有车的判断，0代表去，1代表回
int t[maxn], has_train[maxt][maxn][2];
int dp[maxt][maxn];

int main(){
    //n--n个车站
    //T--约定的时间
    int kase = 0,n,T;
    //输入n且n不为零
    while(cin>>n&&n){
        cin>>T;
        int M1,M2,d;
        for (int i = 1; i <= n-1; i++)
        {
            //ti 表示到第i站到第i+1站火车经过的时间；
            cin >> t[i];
        }
        memset(has_train,0,sizeof(has_train));
        cin>>M1;
        while(M1--){
            cin>>d;//输入的d是发车时间，循环输入每辆车发车时间
            for(int j = 1;j<=n-1;j++){
                //每次计算到的d在车站j都是有车的
                if(d<=T) has_train[d][j][0] = 1;
                //下一站时间
                d+=t[j];
            }
        }
        cin>>M2;
        while(M2--){
            cin>>d;//输入的d是发车时间，循环输入每辆车发车时间
            for(int j = n-1;j>=1;j--){
                //每次计算到的d在车站j都是有车的
                if(d<=T) has_train[d][j+1][1] = 1;
                //下一站时间
                d+=t[j];
            }
        }
        for(int i = 1;i<=n-1;i++) dp[T][i] = INF;
        dp[T][n] = 0;//已达，最终状态

        for(int i = T-1; i>=0; i--)
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i+1][j] + 1;//wait one minute
                if(j<n&&has_train[i][j][0] && i + t[j] <= T)
                    dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);//right
                if(j>1&&has_train[i][j][1] && i+t[j-1] <=T)
                dp[i][j] = min(dp[i][j],dp[i+t[j-1]][j-1]);//left
            }
        //输出
        cout<<"Case Number "<<++kase<<": ";
        if(dp[0][1] >=INF) cout<<"impossible\n";
        else cout<<dp[0][1]<<"\n";
        }
    return 0;
    
}