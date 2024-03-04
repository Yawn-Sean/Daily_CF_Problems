//abs可以抽象成两个数字的距离，那么就可以转换成n个线段。
//在纸上简单画一下，可以发现，如果两个线段不相交的时候，才有贡献。
//问题就转换成了找到一组线段，使得两线段距离最远
//直接枚举右端点最靠前的位置，和左端点最靠后的位置即可。

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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int res=0;
    for(int i=1;i<=n;i++) res+=abs(a[i]-b[i]);
    int mi=1e9,ma=0;
    for(int i=1;i<=n;i++){
        mi=min(mi,max(a[i],b[i]));
        ma=max(ma,min(a[i],b[i]));
    }
    if(mi>=ma) cout<<res<<endl;
    else cout<<res+2*(ma-mi)<<endl;
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
