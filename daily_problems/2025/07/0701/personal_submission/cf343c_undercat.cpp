#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;cin>>n>>m;
    vector<int>h(n),p(m);
    for(auto&i:h)cin>>i;
    for(auto&i:p)cin>>i;
    int l=0,r=(1e11)+10,ans=0;
    while(l<=r){
        int mid=(l+r)/2,flag=1;
        int xb=0;
        for(auto i:h){
            if(p[xb]<i-mid){
                flag=0;break;
            }
            if(p[xb]<i){
                int sub=max(0ll,mid-(i-p[xb])*2);
                int pre=p[xb];
                while(xb<m&&p[xb]<=i+sub)xb++;
                while(xb<m&&((p[xb]-i)*2+(i-pre))<=mid)xb++;
            }else{
                while(xb<m&&p[xb]<=i+mid)xb++;
            }
            if(xb==m)break;
        }
        if(xb<m)flag=0;
        if(flag){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}