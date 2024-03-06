//如果没有k那么显然n%3==0先手必败(参考nim游戏)
//显然当k%3==0时候,才会对局面产生影响
//k%==0将原本的胜负分成了k+1块,k会影响不同块的胜负关系
//则胜负关系将会以k+1为周期循环
//那么将n对k+1取模后，变成了只有1,2的nim游戏

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n,k;
    cin>>n>>k;
    if(k%3==0){
        n%=(k+1);
    }
    if(n==k) cout<<"Alice"<<endl;
    else{
        if(n%3==0) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
