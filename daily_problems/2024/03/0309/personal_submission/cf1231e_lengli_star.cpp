//注意观察题目范围
//我们扫描b，对于每个起点为i的后缀，我们找到a中最长子序列长度len。
//其他位置只需要n-len+i次放置就是答案，n^3

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
    string a,b;
    cin>>a>>b;
    int res=1e9;
    for(int i=0;i<n;i++){
        int idx=i;
        for(int j=0;j<n;j++){
            if(idx<n and b[idx]==a[j]) idx++;
        }
        res=min(res,n-idx+i);
    }
    sort(all(a)),sort(all(b));
    if(a!=b) cout<<-1<<endl;
    else cout<<res<<endl;
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
