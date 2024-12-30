#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2;
#define int long long
int n,m=1e9+7;

void mul(int c[],int a[],int b[][N]){
    int temp[N]={0};
    for(int i=0;i<N;i++){//列
        for(int j=0;j<N;j++){//行
            temp[i]=(temp[i]+(LL)a[j]*b[j][i])%m;
        }
    }
    memcpy(c,temp,sizeof(temp));
}
void mul(int c[][N],int a[][N],int b[][N]){
    int temp[N][N]={0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                temp[i][j]=(temp[i][j]+(LL)a[i][k]*b[k][j])%m;
            }
        }
    }
    memcpy(c,temp,sizeof(temp));
}
signed main(){
    int A,B,x,n;cin>>A>>B>>n>>x;

    int f1[N] = {B,x};
    int a[N][N] = {
        {1,1},
        {0,A}
    };

    
    while (n)
    {
        if (n & 1) mul(f1, f1, a);  // res = res * a
        mul(a, a, a);  // a = a * a
        n >>= 1;
    }

    cout << f1[1] << endl;

    return 0;

}
