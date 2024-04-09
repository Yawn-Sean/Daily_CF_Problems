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
    int n,a,cf,cm,m;
    cin>>n>>a>>cf>>cm>>m;
    vector<int> l(n);
    vector<array<int,2>> q(n);

    int cnt=0;
    for(auto &x:l) {
        cin>>x;
        if(x==a) cnt++;
    }

    for(int i=0;i<n;i++){
        q[i][0]=l[i];
        q[i][1]=i;
    }

    sort(all(l));
    sort(all(q));
    vector<int> b=l;
    for(int i=1;i<n;i++) b[i]+=b[i-1];

    int res=0,rf=-1,rm=-1;
    for(int i=0,j=n;i<=n and m>=0;m-=(a-l[j-1]),i++,j--){
        auto check=[&](int x)->bool{
            auto it=upper_bound(l.begin(),l.begin()+j,x)-l.begin()-1;
            if(it==-1) return 1;
            int sum=(it+1)*x;
            return sum-b[it]<=m;
        };
        int l=0,r=a;
        while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        if(check(l)){
            int ans=i*cf+l*cm;
            if(ans>res) res=ans,rf=i,rm=l;
        }
    }
    cout<<res<<endl;

    for(int i=n-1;rf>0;rf--,i--){
        q[i][0]=a;
    }
    for(int i=0;i<n;i++){
        if(q[i][0]<rm) q[i][0]=rm;
        else break;
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        ans[q[i][1]]=q[i][0];
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
