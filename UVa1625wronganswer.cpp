//date:202206011
//problem number: 1625
//problem name: Color Length
//type: dynamics programming
//author: jackgnez
//reference: https://www.cnblogs.com/hkxy125/p/8593539.html

#include<bits/stdc++.h>
using namespace std;


const int INF = 0x3f;
const int UP = 5000 + 5;
int sa[26],sb[26],ea[26],eb[26];//sa[i] 代表 序列a 中颜色i的开始位置
int d[2][UP], c[2][UP]; // d[i][j] 为两个序列分别移走了i和j个元素的最小费用
//c数组记录有多少个颜色已经出现但尚未结束，d，c均为滚动数组
char a[UP], b[UP];//元素序号从1开始

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s%s",a+1,b+1);
        int La = strlen(a+1),Lb = strlen(b+1);
        for(int i = 0; i < 26; i++) sa[i] = sb[i] = INF, ea[i] = eb[i] = 0;
        for(int i = 1; i<= La; i++){
            a[i] -= 'A';
            sa[a[i]] = min(sa[a[i], i],i);
            ea[a[i]] = i;
        }
        for(int i = 1; i<=Lb; i++){
            b[i] -= 'A';
            sb[b[i]] = min(sb[b[i]],i);
            eb[b[i]] = i;
        }
        d[0][0] = c[0][0] = 0;
        for(int j = 0, t = 0; t<= La; t++, j^=1){
            for(int i = 0;i<=Lb;i++){
                if(!t && !i) continue;
                int v = INF, v2 = INF;
                if(t) v = d[j^1][i] + c[j^1][i];//在a[1..t-1]与b[1..i]后面加a[t]
                if(i) v2 = d[j][i-1] + c[j][i-1]; //在a[1..t] yu b[1..i-1]后面加b[i]
                d[j][i] = min(v,v2);

                if(t){
                    c[j][i] = c[j^1][i];
                    if(sa[a[t]] == t && sb[a[t]] > i) c[j][i]++;
                    if(ea[a[t]] == t && eb[a[t]] <= i) c[j][i]--;
                }
                else{
                    c[j][i] = c[j][i-1];
                    if(sb[b[i]] == i && sa[b[i]] > t) c[j][i]++;
                    if(eb[b[i]] == i && ea[b[i]] <= t) c[j][i]--;
                }
            }
        }
        printf("%d\n", d[La&1][Lb]);
    }
    system("pause");
    return 0;
}



