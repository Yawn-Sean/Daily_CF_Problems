/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,h;
    std::cin>>n>>h;
    std::vector<std::array<int,2>> a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i][0];
        a[i][1]=i;
    }

    if(n==2){
        std::cout<<"0\n1 1"<<"\n";
        return;
    }

    sort(all(a));

    int res=a[n-1][0]+a[n-2][0]-a[0][0]-a[1][0];
    int ans=std::max(a[n-1][0]+a[n-2][0],a[n-1][0]+a[0][0]+h)-std::min(a[1][0]+a[2][0],a[1][0]+a[0][0]+h);
    std::cout<<std::min(res,ans)<<"\n";
    std::vector<int> st(n);
    st[a[0][1]]=(ans<res ? 2 : 1);
    for(int i=1;i<n;i++) st[a[i][1]]=1;
    for(auto x:st) std::cout<<x<<" ";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
