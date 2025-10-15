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
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> q,p;
    for(int i=1;i<=n;i++){
        int c,v;
        std::cin>>c>>v;
        if(c) q.pb({v,i});
        else p.pb({{v,i}});
    }
    sort(all(q));
    sort(all(p));
    int i=0,j=0,l=0,r=0;;
    std::vector<std::array<int,3>> res;
    while(i<p.size() and j<q.size()){
        l=p[i][1],r=q[j][1];
        if(p[i][0]<q[j][0]){
            res.pb({l,r,p[i][0]});
            q[j][0]-=p[i][0];
            i++;
            if(i>=p.size()) j++;
        }else{
            res.pb({l,r,q[j][0]});
            p[i][0]-=q[j][0];
            j++;
            if(j>=q.size()) i++;
        }
    }
    while(i<p.size()){
        res.pb({r,p[i][1],p[i][0]});
        i++;
    }
    while(j<q.size()){
        res.pb({r,q[j][1],q[j][0]});
        j++;
    }
    for(auto [u,v,w]:res) std::cout<<u<<" "<<v<<" "<<w<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
