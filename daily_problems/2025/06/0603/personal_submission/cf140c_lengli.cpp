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
    std::map<int,int> cnt;
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        cnt[x]++;
    }
    std::priority_queue<std::array<int,2>> q;
    for(auto [v,c]:cnt) q.push({c,v});

    std::vector<std::array<int,3>> res;
    while(q.size()>=3){
        auto a=q.top();q.pop();
        auto b=q.top();q.pop();
        auto c=q.top();q.pop();
        
        std::vector<int> tmp={a[1],b[1],c[1]};
        sort(all(tmp),std::greater<>());
        res.pb({tmp[0],tmp[1],tmp[2]});
        a[0]--,b[0]--,c[0]--;
        if(a[0]) q.push(a);
        if(b[0]) q.push(b);
        if(c[0]) q.push(c);
    }
    std::cout<<res.size()<<"\n";
    for(auto [a,b,c]:res){
        std::cout<<a<<" "<<b<<" "<<c<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
