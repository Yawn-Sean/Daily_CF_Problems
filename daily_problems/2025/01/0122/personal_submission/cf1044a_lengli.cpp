/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> col,row;

    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        col.pb(x);
    }
    col.pb(inf);

    for(int i=0;i<m;i++){
        int l,r,y;
        std::cin>>l>>r>>y;
        if(l==1) row.pb(r);
    }

    sort(all(col));
    sort(all(row));

    int res=inf;

    int idx=0;

    for(int i=0;i<col.size();i++){
        while(idx<row.size() and row[idx]<col[i]) idx++;
        int cnt=i+row.size()-idx;
        res=std::min(res,cnt);
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
