//date:202206011
//problem number: 1625
//problem name: Color Length
//type: dynamics programming
//author: jackgnez
//https://blog.csdn.net/bobodem/article/details/50199019

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 0x3f;
const int inf = -INF;
const int N = 5005;
const int M = 2005;
const int mod = 1000000007;
const double pi = acos(-1.0);

#define cls(x,c) memset(x,c,sizeof(x))
#define cpy(x,a) memcpy(x,a,sizeof(a))
#define ft(i,s,n) for(int i = s; i<=n; i++)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define lrt rt<<1
#define rrt rt<<1|1
#define middle int m = (r+1)>>1
#define lowbit(x) (x&-x)
#define pii pair<int,int>
#define mk make_pair
#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);

char s[N];
int len[2],a[2][N];
int f[N][N];
int ft[2][26], lt[2][26], g[N][N];
void sol(){
    cls(ft,0);cls(lt,0);
    ft(i,0,1) ft(j,1,len[i]){
        if(!ft[i][a[i][j]]) ft[i][a[i][j]] = j;
        lt[i][a[i][j]] = j;
    }

    ft(i,1,len[0]){
        g[i][0] = g[i-1][0];
        if(ft[0][a[0][i]] == i) g[i][0]++;
        if(lt[0][a[0][i]] == i && !lt[1][a[0][i]]) g[i][0]--;
    }

    ft(i,0,len[0]) ft(j,1,len[1]){
        g[i][j] = g[i][j-1];
        if(ft[1][a[1][j]] == j&&(!ft[0][a[1][j]]||ft[0][a[1][j]]>i)) g[i][j]++;
        if(lt[1][a[1][j]] == j&<[0][a[1][j]]<=i) g[i][j]--;
    }

}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ft(i,0,1){
        scanf("%s",s+1);
        len[i]=strlen(s+1);
        ft(j,1,len[i]) a[i][j]=s[j]-'A';
        }
        sol();
        ft(i,1,len[0]) f[i][0]=f[i-1][0]+g[i-1][0];
        ft(i,1,len[1]) f[0][i]=f[0][i-1]+g[0][i-1];
        ft(i,1,len[0]) ft(j,1,len[1])
        f[i][j]=min(f[i-1][j]+g[i-1][j],f[i][j-1]+g[i][j-1]);
        printf("%d\n",f[len[0]][len[1]]);
    }