//date:20220608
//problem number: 11584
//problem name: Partitioning by Palindromes 
//type: dynamics programming
//author: jackgnez
//reference:https://yuukidach.github.io/p/uva-oj-11584-partitioning-by-palindromes/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;

char str[MAXN];  
int f[MAXN];
bool isPalind(int l, int r){
    while(l<r){
        if(str[l] != str[r]) return false;
        ++l;--r;
    }
    return true;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", str+1);
        int len = strlen(str+1);
        memset(f, 0, sizeof(f));
        for(int i = 1; i<= len; ++i){
            f[i] = i + 1;
            for(int j = 1; j <= i; ++j){
                if(isPalind(j,i)){
                    f[i] = min(f[i], f[j-1]+1);  
                }
            }
        }
        printf("%d\n",f[len]);
    }
    return 0;
}