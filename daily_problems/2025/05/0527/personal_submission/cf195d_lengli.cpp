/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct Node{
    int fz,fm;
    Node(){};
    Node(int fz_,int fm_):fz(fz_),fm(fm_){
        if(fm<0){
            fm*=-1;
            fz*=-1;
        }
    };
    bool operator == (const Node &W){
        return 1ll*fz*W.fm==1ll*fm*W.fz;
    };
    friend bool operator==(const Node &lhs,const Node &rhs) {
        return 1ll*lhs.fz*rhs.fm==1ll*rhs.fz*lhs.fm;
    }
    friend bool operator<(const Node &lhs,const Node &rhs) {
        return 1ll*lhs.fz*rhs.fm<1ll*rhs.fz*lhs.fm;
    }
};

void solve(){
    int n;
    std::cin>>n;
    std::set<Node> s;
    for(int i=1;i<=n;i++){
        int k,b;
        std::cin>>k>>b;
        if(!k) continue;
        s.insert(Node(-b,k));
    }
    std::cout<<s.size()<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
