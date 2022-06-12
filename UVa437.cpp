//date:20220603
//problem number: 437
//problem name: The Tower of Babylon 
//type: dynamics programming
//author: jackgnez

#include <bits/stdc++.h>
using namespace std;
typedef struct{
    int x,y,z;
}Block;


void swap(int *a,int*b){
    int tmp;
    tmp = *a, *a = *b, *b = tmp;
}

int cmp(const void *i, const void *j){
    Block *a, *b;
    a = (Block *)i, b = (Block*)j;
    return b->x - a->x;
}

int main(){
    int n,Case = 0;
    Block D[91];
    while(scanf("%d", &n) == 1&&n){
        for (int  i = 0; i < n; i++)
        {
            //输入长宽高
           scanf("%d %d %d", &D[i].x,&D[i].y,&D[i].z);
           //对长宽排序，让y始终是较小的一个
           if(D[i].y > D[i].x) swap(&D[i].x, &D[i].y);
           //？赋值i到下一个n
           D[n+i] = D[i];
           //交换下一个n中的x和z？
           swap(&D[n+i].x, &D[n+i].z);
           //让y成为比较小的一个，事实上是y成为y和z中比较小的一个
           //这题要考虑xyz都有可能当作高，所以这种情况是把原来输入的x当作高
           if(D[n+i].y>D[n+i].x) swap(&D[n+i].x, &D[n+i].y);
           D[2*n+i] = D[i];
           //这是把y当作高
           swap(&D[2*n+i].y,&D[2*n+i].z);
           if(D[2*n+i].y>D[2*n+i].x) swap(&D[2*n+i].x,&D[2*n+i].y);
        }
        qsort(D, 3*n, sizeof(Block),cmp);
        int DP[90] = {};
        for (int i = 0; i < 3*n; i++)
        {
            DP[i] = D[i].z;
        }
        //因为每个立方体的xyz都可以当高，现在等于有3n种立方体，它们的z已经都被设置成了高。
        for (int i = 0; i < 3*n; i++)
        {
            for (int j = i+1; j < 3*n; j++)
            {
                if((D[i].x > D[j].x && D[i].y > D[j].y) ||
                    (D[i].x > D[j].y && D[i].y > D[j].x)){
                        if(DP[j]<DP[i]+D[j].z){
                            DP[j] = DP[i] +D[j].z;
                        }
                    } 
            }
        }
        int ans = 0;
        for (int i = 0; i < 3*n; i++)
        {
            ans = ans > DP[i] ? ans : DP[i];
        }
        printf("Case %d: maximum height = %d\n", ++Case, ans);
    }
    return 0;
}
