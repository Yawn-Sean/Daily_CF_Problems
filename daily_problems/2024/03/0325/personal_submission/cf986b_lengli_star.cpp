//首先操作的是一个排列
//那么交换相邻两个位置，一定会导致逆序对奇偶性变化。
//那么我们只需要计算逆序对数量，并和操作次数的奇偶性进行比较即可。
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

const int N=1000010;

int tr[N];
void add(int x){
    for(int i=x;i<N;i+=(i&-i)) tr[i]+=1;
}
int sum(int x){
    int res=0;
    for(int i=x;i;i-=(i&-i)) res+=tr[i];
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    reverse(all(a));
    int res=0;
    for(auto x:a){
        res+=sum(x);
        add(x);
    }
    if((3*n)&1) cout<<(res&1 ? "Petr" : "Um_nik");
    else cout<<(res&1 ? "Um_nik" : "Petr");
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
