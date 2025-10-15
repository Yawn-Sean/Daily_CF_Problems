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
    int a,b;
    std::cin>>a>>b;
    if((a|b)!=a){
        std::cout<<"-1"<<"\n";
        return;
    }
    std::vector<int> res;
    int v=0;

    std::vector<int> st(a+1);

    for(int i=0;i<=a;i++){
        if((i|a)==a){
            st[i]=1;
            res.pb(i);
            v^=i;
        }
    }

    v^=b;

    if(!st[v]){
        std::cout<<"-1"<<"\n";
        return;
    }

    if(!v) v=-1;
    std::vector<int> out;
    int A=0,B=0;
    for(auto x:res){
        if(x==v) continue;
        A|=x;
        B^=x;
        out.pb(x);
    }
    if(A!=a or B!=b){
        std::cout<<"-1"<<"\n";
        return;
    }
    std::cout<<out.size()<<"\n";
    for(auto x:out) std::cout<<x<<" ";
    std::cout<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
