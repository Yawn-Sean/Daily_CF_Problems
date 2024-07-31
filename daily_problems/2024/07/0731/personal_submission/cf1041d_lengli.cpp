#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0);std::cin.tie(0);
#define all(x) x.begin(),x.end()

#define int long long

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,2>> a(n);
    for(auto &[x,y]:a) std::cin>>x>>y;
    sort(all(a));
    int res=0;
    std::vector<int> b(n);
    for(int i=1;i<n;i++) b[i]=a[i][0]-a[i-1][1];
    for(int i=1;i<n;i++) b[i]+=b[i-1];
    for(int i=0;i<n;i++){
        int l=i,r=n-1;
        while(l<r){
            int mid=(l+r+1)/2;
            if(b[mid]-b[i]<m) l=mid;
            else r=mid-1;
        }

        int h=m-b[l]+b[i];
        int ans=a[l][1]-a[i][0]+h;
        res=std::max(res,ans);
    }
    std::cout<<res;
    
}

signed main(){
    fastio;

    int T;
    T=1;
    while(T--) solve();

    return 0;
}
