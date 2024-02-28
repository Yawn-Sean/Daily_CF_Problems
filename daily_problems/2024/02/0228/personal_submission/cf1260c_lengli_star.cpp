//特判k==1时候无解;r==b时候有解。
//只考虑r<b的情况(r>b交换即可)。
//考虑blue的染色情况：b*y b*(y+1) b*(y+2) ...
//考虑red的染色情况：a*x a*(x+1) a*(x+2) ...
//其中x,y均为任意正整数
//我们只需要计算相邻两个blue之间，最多能放多少个a即可
//那么我们需要找到一对(x,y)使得ax-by尽可能小(这样才能尽可能在两个b之间多放a)
//根据EXGCD我们可以知道最小值为gcd(a,b)
//那么如果b+gcd(a,b)+(k-1)*a<2*b则无解，否则有解
//即gcd(a,b)+(k-1)*a<b

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

void solve(){
    int a,b,k;
    cin>>a>>b>>k;
    if(a>b) swap(a,b);
    if(k==1) cout<<"REBEL"<<endl;
    else if(a==b) cout<<"OBEY"<<endl;
    else{
        bool flag=gcd(a,b)+(k-1)*a<b;
        cout<<(!flag ? "OBEY" : "REBEL")<<endl;
    }
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
