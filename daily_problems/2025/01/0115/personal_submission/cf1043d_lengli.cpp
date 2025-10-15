/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> a(m+2,std::vector<int> (n+2));
    std::vector<std::vector<int>> id(m+2,std::vector<int> (n+2,-1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            std::cin>>a[i][j];
            id[i][a[i][j]]=j;
        }
    }

    auto check=[&](int idx){
        int l=a[1][idx],r=a[1][idx+1];
        for(int i=2;i<=m;i++){
            if(id[i][l]+1!=id[i][r]) return 1;
        }
        return 0;
    };

    i64 res=0;
    for(int i=1,j=1;i<=n;i++){
        if(i>1 and check(i-1)) j=i;
        while(i-j+1>1){
            if(check(j)) j++;
            else break;
        }
        res+=i-j+1;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
