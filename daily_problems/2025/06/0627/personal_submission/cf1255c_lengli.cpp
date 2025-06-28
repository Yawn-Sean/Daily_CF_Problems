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
    std::vector<std::vector<int>> a(n-2,std::vector<int> (3));
    std::vector<int> q(n+2);

    std::vector<std::vector<int>> eg(n+2);

    for(auto &t:a){
        for(int j=0;j<3;j++){
            std::cin>>t[j];
            q[t[j]]++;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j) continue;
                eg[t[i]].pb(t[j]);
            }
        }
    }

    std::vector<int> res;

    int s=0;

    for(int i=1;i<=n;i++){
        if(q[i]==1){
            s=i;
            break;
        }
    }
    int x=s,y=eg[s][0],z=eg[s][1];
    if(q[y]==3) std::swap(y,z);
    std::vector<int> st(n+2);
    
    st[x]=1;res.pb(x);
    st[y]=1;res.pb(y);
    for(int i=1;i<=n-2;i++){
        for(auto c:eg[x]){
            if(!st[c]) z=c;
        }
        res.pb(z);
        st[z]=1;
        x=y,y=z;
    }
    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
