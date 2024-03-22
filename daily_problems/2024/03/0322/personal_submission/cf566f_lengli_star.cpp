//定义dp(i),表示以数字i作为最大值的最大团大小
//不难发现，对于某个数字，我们只需要把他的所有倍数的dp值更新即可
//这样做复杂度为调和级数

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

const int N=1000010;

int a[N],b[N],w[N],tt=0;
int f[N];
int idx[N];

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int la=-1,cnt=-1;
    for(int i=1;i<=n;i++){
        if(la==-1) la=a[i],cnt=1;
        else if(la!=a[i]){
            b[++tt]=la;
            w[tt]=cnt;
            idx[la]=tt;
            la=a[i],cnt=1;
        }else cnt++;
    }
    if(la!=-1){
        b[++tt]=la;
        w[tt]=cnt;
        idx[la]=tt;
    }
    int res=0;
    for(int i=1;i<=tt;i++){
        int v=b[i];
        f[i]=max(f[i],w[i]);
        for(int j=2;j*v<N;j++){
            int k=idx[j*v];
            if(k) f[k]=max(f[k],f[i]+w[k]);
        }
        res=max(res,f[i]);

    }
    cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
