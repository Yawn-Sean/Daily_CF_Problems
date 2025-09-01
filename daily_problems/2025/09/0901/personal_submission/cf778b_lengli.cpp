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
    std::vector<std::vector<std::string>> q;

    for(int i=1;i<=n;i++){
        std::vector<std::string> t;
        std::string s;
        std::cin>>s;
        t.pb(s);
        std::cin>>s;
        std::cin>>s;
        if(std::isdigit(s[0])) t.pb(s);
        else{
            t.pb(s);
            std::cin>>s;
            t.pb(s);
            std::cin>>s;
            t.pb(s);
        }
        q.pb(t);
    }

    auto get=[&](int pos,char c)->int{
        std::unordered_map<std::string,int> tmp;
        tmp.reserve(1024);
        tmp.max_load_factor(0.25);
        tmp["?"]=c-'0';
        for(auto &v:q){
            if(v.size()==2){
                tmp[v[0]]=v[1][pos];
            }else{
                std::string l=v[1],r=v[3],op=v[2];
                if(op=="AND") tmp[v[0]]=tmp[l]&tmp[r];
                else if(op=="OR") tmp[v[0]]=tmp[l]|tmp[r];
                else tmp[v[0]]=tmp[l]^tmp[r];
            }
        }
        int res=0;
        for(auto [v,t]:tmp){
            if(v=="?") continue;
            res+=t;
        }
        return res;
    };

    std::string mi="",mx="";
    for(int i=0;i<m;i++){
        auto c1=get(i,'0');
        auto c2=get(i,'1');
        if(c2>c1){
            mi+='0';
            mx+='1';
        }else if(c1>c2){
            mi+='1';
            mx+='0';
        }else{
            mi+='0';
            mx+='0';
        }
    }
    std::cout<<mi<<"\n"<<mx<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
