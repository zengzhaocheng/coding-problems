//date:20220608
//problem number: 11584
//problem name: Partitioning by Palindromes 
//type: dynamics programming
//author: jackgnez
//reference:https://yuukidach.github.io/p/uva-oj-11584-partitioning-by-palindromes/


#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char s[maxn];
int d[maxn], idx[maxn][maxn], cas;
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin>>cas;
    while(cas--){
        cin>>s+1;//把s[0]空出来，从s[1]开始输入。
        int n = strlen(s+1);
        memset(d,0x3f,sizeof(d));//0x3f一个很大的数
        d[0] = 0;
        for (int  i = 1; i <= n; i++)
        {
            idx[i][i] = 1;
            for (int j = i+1; j <= n; j++)
            {
                bool isOK = false;
                for (int k = 0; k < (j-i+1>>1); k++)
                {
                    if(s[i+k] !=s[j-k]){
                        idx[i][j] = j-i+1;
                        isOK = true;
                        break;
                    }
                    if(isOK) continue;
                    idx[i][j] = 1;
                }
            } 
            for (int i = 1; i <= n; i++)
            {
                for (int  j = 0; j <= i; j++)
                {
                    d[i] = min(d[i],d[j]+idx[j+1][i]);
                }
            }
        }
        cout<<d[n]<<'\n';
    }
    return 0;
}
