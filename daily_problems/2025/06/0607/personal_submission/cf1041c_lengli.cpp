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
    int n,m,d;
    std::cin>>n>>m>>d;
    std::set<std::array<int,2>> s;
    std::vector<int> res(n),a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        s.insert({a[i],i});
    }

    int idx=1;
    while(s.size()){
        auto it=s.begin();
        res[(*it)[1]]=idx;
        int la=(*it)[0];
        s.erase(it);

        while(1){
            auto nt=s.lower_bound({la+d+1,0});
            if(nt==s.end()) break;

            res[(*nt)[1]]=idx;
            la=(*nt)[0];
            s.erase(nt);
        }

        idx++;
    }

    std::cout<<idx-1<<"\n";
    for(int i=0;i<n;i++) std::cout<<res[i]<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
