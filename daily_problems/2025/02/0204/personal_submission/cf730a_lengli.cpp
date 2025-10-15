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
    std::vector<int> a(n+2);

    std::set<int> s;
    std::map<int,int> q;

    auto modify=[&](int x,int v){
        q[x]+=v;
        if(!q[x]) s.erase(x);
        if(q[x]==1) s.insert(x);  
    };

    auto cut=[&](int idx){
        modify(a[idx],-1);
        a[idx]=std::max(a[idx]-1,0);
        modify(a[idx],1);
    };

    for(int i=1;i<=n;i++) {
        std::cin>>a[i];
        modify(a[i],1);
    }

    std::vector<std::string> res;
    
    while(s.size()!=1){
        auto it=s.rbegin();
        auto mx=*it;
        int cnt=q[mx];
        if(cnt==1){
            it++;
            auto smx=*it;
            int l=-1,r=-1;
            std::string str=std::string(n,'0');
            for(int i=1;i<=n and l==-1;i++){
                if(a[i]==mx) l=i,str[i-1]='1';
            }
            for(int i=1;i<=n and r==-1;i++){
                if(a[i]==smx) r=i,str[i-1]='1';
            }
            cut(l),cut(r);
            res.pb(str);
        }else{
            int len=cnt&1 ? 3 : 2;
            std::vector<int> tmp;
            std::string str=std::string(n,'0');
            for(int i=1;i<=n and tmp.size()<len;i++){
                if(a[i]==mx and tmp.size()<len) tmp.pb(i);
            }
            for(auto x:tmp) {
                cut(x);
                str[x-1]='1';
            }
            res.pb(str);
        }
    }
    std::cout<<*s.begin()<<"\n";
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
