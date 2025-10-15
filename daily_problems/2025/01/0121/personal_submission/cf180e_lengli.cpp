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
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<std::vector<std::array<int,2>>> seg(m+2);
    for(int i=1;i<=n;i++){
        int v=a[i];
        if(seg[v].empty() or seg[v].back()[1]+1!=i) seg[v].pb({i,i});
        else seg[v].back()[1]+=1;
    }

    int res=0;

    for(int i=1;i<=m;i++){
        auto &q=seg[i];

        int cnt=0,len=0;
        for(int r=0,l=0;r<q.size();r++){
            if(!r) len+=q[r][1]-q[r][0]+1;
            else{
                cnt+=q[r][0]-q[r-1][1]-1;
                len+=q[r][1]-q[r][0]+1;
            }
            while(l<r and cnt>k){
                cnt-=q[l+1][0]-q[l][1]-1;
                len-=q[l][1]-q[l][0]+1;
                l++;
            }
            res=std::max(res,len);
        }
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
