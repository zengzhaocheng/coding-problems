//date:20220601
//problem number: 11400
//problem name: Lighting System Design
//type: dynamics programming
//author: jackgnez
#include "bits/stdc++.h";
using namespace std;
const int inf = 99999999;
struct light
{
    int v,k,c,l;
};
light ls[1001];
int cmp(const light &l1, const light &l2)
{
    return l1.v<l2.v;
}
int dp[1001];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    //输入n且n不等于零
    while(cin>>n,n)
    {
        //输入灯泡参数
        for(int i = 1;i<=n;i++)
            cin>>ls[i].v>>ls[i].k>>ls[i].c>>ls[i].l;
        //排序
        sort(ls+1,ls+1+n,cmp);
        memset(dp,0,sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            dp[i] = inf;
            //当前的灯泡的需求量
            int temp = 0;
            for(int j = i;j>=1;j--)
            {
                //从i往前数，把比较小的灯泡数量累加
                temp+=ls[j].l;
                dp[i] = min(dp[i],dp[j-1]+temp*ls[i].c+ls[i].k);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
