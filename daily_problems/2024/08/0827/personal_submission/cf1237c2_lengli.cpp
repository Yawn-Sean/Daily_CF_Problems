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
    std::vector<std::array<int,4>> pt(n);
    std::vector<std::array<int,2>> res;
    std::vector<int> st(n+2,0);
    int cnt=1;
    for(auto &[x,y,z,id]:pt) std::cin>>x>>y>>z,id=cnt++;

    auto get1=[&](std::vector<std::array<int,3>> &pt,std::vector<int> &seq){
        std::vector<std::array<int,2>> a;
        for(auto x:seq) a.pb({pt[x][1],pt[x][2]});
        sort(all(a));
        int n=a.size();
        for(int i=0;i<n;i+=2){
            if(i+1<n){
                res.pb({a[i][1],a[i+1][1]});
                st[a[i][1]]=st[a[i+1][1]]=1;
            }
        }
        return;
    };

    auto get2=[&](std::vector<int> &seq){
        std::vector<std::array<int,3>> a;
        for(auto x:seq) a.pb({pt[x][1],pt[x][2],pt[x][3]});
        sort(all(a));
        int n=a.size();
        for(int i=0;i<n;i++){
            int j=i;
            std::vector<int> q;
            while(j<n and a[j][0]==a[i][0]) q.pb(j++);
            get1(a,q);
            i=j-1;
        }
        std::vector<int> p;
        for(int i=0;i<n;i++){
            if(!st[a[i][2]]) p.pb(a[i][2]);
        }
        for(int i=0;i<p.size();i+=2){
            if(i+1<p.size()){
                res.pb({p[i],p[i+1]});
                st[p[i]]=st[p[i+1]]=1;
            }
        }
        return;
    };

    auto get3=[&](){
        sort(all(pt));
        for(int i=0;i<n;i++){
            int j=i;
            std::vector<int> q;
            while(j<n and pt[j][0]==pt[i][0]) q.pb(j++);
            get2(q);
            i=j-1;
        }
        std::vector<int> p;
        for(int i=0;i<n;i++){
            if(!st[pt[i][3]]) p.pb(pt[i][3]);
        }
        for(int i=0;i<p.size();i+=2){
            res.pb({p[i],p[i+1]});
            st[p[i]]=st[p[i+1]]=1;
        }
        return;
    };

    get3();

    for(auto [x,y]:res) std::cout<<x<<" "<<y<<"\n";

    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
