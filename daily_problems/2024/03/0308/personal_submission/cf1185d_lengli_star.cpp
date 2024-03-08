//先排序，然后暴力模拟删除某个数字后，剩余的差值情况即可，就像模拟链表一样。

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
    vector<array<int,2>> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i][0],a[i][1]=i;
    sort(a.begin()+1,a.begin()+n+1);
    map<int,int> q;
    for(int i=2;i<=n;i++){
        q[a[i][0]-a[i-1][0]]++;
    }
    int res=-1;
    for(int i=1;i<=n;i++){
        if(i==1){
            int d=a[i+1][0]-a[i][0];
            q[d]--;
            if(!q[d]) q.erase(d);
            if(q.size()<=1) res=a[i][1];
            q[d]++;
        }else if(i==n){
            int d=a[i][0]-a[i-1][0];
            q[d]--;
            if(!q[d]) q.erase(d);
            if(q.size()<=1) res=a[i][1];
            q[d]++;
        }else{
            int l=a[i+1][0]-a[i][0],r=a[i][0]-a[i-1][0];
            q[l]--,q[r]--;
            q[l+r]++;
            if(!q[l]) q.erase(l);
            if(l!=r and !q[r]) q.erase(r);
            q[l+r]--;
            if(q.size()<=1) res=a[i][1];
            q[l]++,q[r]++;
            if(!q[l+r]) q.erase(l+r);
        }
    }
    cout<<res<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
