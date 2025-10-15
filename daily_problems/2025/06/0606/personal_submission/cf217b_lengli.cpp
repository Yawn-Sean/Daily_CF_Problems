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
    int n,r;
    std::cin>>n>>r;

    int cnt=inf;
    std::string res="";

    auto get=[&](int a,int b){
        std::vector<std::pair<int,char>> q;

        int ans=0,len=0;

        while(a!=1 or b!=0){
            if(a>b){
                int na=a%b;
                if(!na) na++;
                if((a-na)%b) return;
                int k=(a-na)/b;
                ans+=std::max(k-1,0);
                len+=k;
                q.pb({k,'B'});
                a=na;
            }else{
                int nb=b%a;
                int k=(b-nb)/a;
                ans+=std::max(k-1,0);
                len+=k;
                q.pb({k,'T'});
                b=nb;
            }
            if(!b) break;
        }
        if(a!=1 or b) return;
        if(len!=n) return;
        if(q.back().second!='T') return;

        if(ans<cnt){
            cnt=ans;
            std::string tmp="";
            std::reverse(all(q));
            for(auto [c,t]:q){
                tmp+=std::string(c,t);
            }
            res=tmp;
        }
    };
    for(int i=1;i<=r;i++){
        get(i,r);
        get(r,i);
    }

    if(cnt==inf){
        std::cout<<"IMPOSSIBLE"<<"\n";
        return;
    }

    std::cout<<cnt<<"\n";
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
