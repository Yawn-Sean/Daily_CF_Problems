//考虑最大值为x,则合法情况数量为x^n-(x-1)^n
//总情况数为m^n
//每种最大值对答案的贡献为x*(x^n-(x-1)^n)/m^n
//将m^n先除掉，可以避免次幂过程中数字过大的问题

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

double qmi(double a,int b){
    double res=1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b/=2;
    }
    return res;
}

void solve(){
    int m,n;
    cin>>m>>n;
    double sum=0;
    for(int i=1;i<=m;i++){
        double t=qmi((double)i/m,n)-qmi((double)(i-1)/m,n);
        sum+=t*i;
    }
    cout<<fixed<<setprecision(12)<<(double)sum<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
