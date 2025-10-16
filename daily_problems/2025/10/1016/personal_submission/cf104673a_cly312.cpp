#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const ll L=1000000000ll;
ll C(int n,int k){
    if(k<0||k>n) return 0;
    if(k>n-k) k=n-k;
    i128 r=1;
    for(int i=1;i<=k;++i){
        r=r*(n-k+i)/i;
        if(r>L) return L+1;
    }
    return (ll)r;
}
unordered_map<int,int> B;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int s=2;;++s){
        ll v=C(2*s,s);
        if(v>L) break;
        ll n=2*s;
        while(v<=L){
            int t=n+1;
            if(!B.count(v)||t<B[v])B[v]=t;
            ++n;
            i128 nx=(i128)v*n/(n-s);
            if(nx>L) break;
            v=(ll)nx;
        }
    }
    int q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<"1\n";
            continue;
        }
        ll a=n+1;
        if(B.count(n)) a=min(a,(ll)B[n]);
        cout<<a<<'\n';
    }
}
