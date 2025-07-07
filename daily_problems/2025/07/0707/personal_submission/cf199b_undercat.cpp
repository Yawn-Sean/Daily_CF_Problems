#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int x[2],y[2],r[2],R[2];
    for(int i=0;i<2;i++)cin>>x[i]>>y[i]>>r[i]>>R[i];
    if(r[0]<r[1]){
        swap(x[0],x[1]);
        swap(y[0],y[1]);
        swap(r[0],r[1]);
        swap(R[0],R[1]);
    }
    int dist=(x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]);
    int res=0;
    auto get=[&](int x,int r,int R)->void{
        if (x >= R && (x - R)*(x - R) >= dist) res++;
        else if (x <= r && (r - x)*(r - x) >= dist) res++;
        else if ((R + x)*(R + x) <= dist) res++;
    };
    get(r[0],r[1],R[1]);
    get(R[0],r[1],R[1]);
    get(r[1],r[0],R[0]);
    get(R[1],r[0],R[0]);
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}