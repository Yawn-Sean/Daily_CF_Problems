/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<char,2>> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i][0];
    for(int i=1;i<=n;i++) std::cin>>a[i][1];
    std::vector<int> res[3];
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i][0]=='0' and a[i][1]=='0') res[0].pb(i);
        else if(a[i][0]=='0' or a[i][1]=='0') res[1].pb(i);
        else res[2].pb(i);
        sum+=a[i][1]=='1';
    }
    for(int i=0;i<=res[0].size();i++){
        for(int j=0;j<=res[1].size();j++){
            if(i+j>n/2) continue;
            int k=n/2-i-j;
            if(k>res[2].size()) continue;
            if(j+k*2!=sum) continue;
            for(int ii=0;ii<i;ii++) std::cout<<res[0][ii]<<" ";
            for(int jj=0;jj<j;jj++) std::cout<<res[1][jj]<<" ";
            for(int kk=0;kk<k;kk++) std::cout<<res[2][kk]<<" ";
            return;
        }
    }

    std::cout<<"-1"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
