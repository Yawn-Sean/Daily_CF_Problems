/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> pt(n);
    for(auto &[x,y]:pt) std::cin>>x>>y;
    std::set<std::array<int,3>> q;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dx=(pt[i][0]-pt[j][0]);
            int dy=(pt[i][1]-pt[j][1]);
            int g=std::gcd(dx,dy);
            dx/=g,dy/=g;
            if(dx<0) dx*=-1,dy*=-1;
            else if(dy<0 and dx==0) dy*=-1;
            int dt=dy*pt[i][0]-dx*pt[i][1];
            q.insert({dx,dy,dt});
        }
    } 
    long long res=((long long)q.size()*((long long)q.size()-1))/2;
    std::map<std::array<int,2>,int> cnt;
    for(auto [x,y,_]:q){
        res-=cnt[{x,y}];
        cnt[{x,y}]++;
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
