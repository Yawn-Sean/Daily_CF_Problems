#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=LLONG_MIN/2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,l,r;
    cin>>n>>l>>r;
    vector<ll>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    int len=r-l+1;
    vector<ll>f(n+1,inf);
    priority_queue<ll,vector<ll>,greater<ll>>q;
    ll s=0;
    for(int i=1;i<=n;++i){
        q.push(a[i]);
        s+=a[i];
        if((int)q.size()>len){
            s-=q.top();
            q.pop();
        }
        if(i>=len)f[i]=s;
    }
    ll x=f[n-l+1],y=inf;
    for(int i=len;i<=r;++i)y=max(y,f[i]);
    cout<<max(x,y)<<"\n";
}