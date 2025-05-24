#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int w,m,k;cin>>w>>m>>k;
    int x=1,y=0,z=0;
    while(x<m){
        x*=10;
        y++;
    }
    w/=k;
    z=m;
    int temp=x*y-z*y;
    while(w>=temp){
        w-=temp;
        z=x;
        x*=10;
        y++;
        temp=x*y-z*y;
    }
    int res=z+(w/y)-m;
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}