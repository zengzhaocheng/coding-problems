//date:20220525
//problem name: A Spy in the Metro
//author: jackgnez
#define INF 100000000
#include iostream;
using namespace std;
int main(){
    int n = 0, T = 0;
    cin>>n>>T;
    
    for(int i = 1;i<=n-1;i++) dp[T][i] = INF;
    dp[T][n] = 0;

    for(int i = T-1; i>=0; i--)
    for (int j = 1; j <= n; j++)
    {
        dp[i][j] = dp[i+1][j] + 1;//wait one minute
        if(j<n&&has_train[i][j][0] && i + t[j] <= T)
            dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);//right
        if(j>1&&has_train[i][j][1] && i+t[j-1] <=T)
        dp[i][j] = min(dp[i][j],dp[i+t[j-1]][j-1]);//left
    }
    
}