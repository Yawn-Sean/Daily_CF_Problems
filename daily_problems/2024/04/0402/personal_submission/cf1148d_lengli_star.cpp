//好像就是个排序？
//只考虑a<b
//把所有这样的数对挑出来，然后按b从大到小排序即可。
//因为a(i+1) <b(i+1) < b(i) 即 b(i) > a(i+1) < b(i+1)
//就满足条件了
//b>a再做一遍即可

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
    int n;
    cin>>n;
    vector<array<int,3>> a,b;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x<y) a.pb({x,y,i});
        else b.pb({x,y,i});
    }
    sort(all(a),[&](auto l,auto r){
        return l[1]>r[1];
    });
    sort(all(b));
    if(a.size()>b.size()){
        cout<<a.size()<<endl;
        for(auto x:a) cout<<x[2]<<" ";
    }else{
        cout<<b.size()<<endl;
        for(auto x:b) cout<<x[2]<<" ";
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
