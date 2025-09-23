/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

class Trie {
private:
    int end=0;
    int ans=0;
    Trie* ne[2];
public:
    Trie() {
        end=0;
        memset(ne,0,sizeof ne);
    }
    void insert(int x) {
        Trie* p = this;
        for(int i=30;i>=0;i--){
            int t=(x>>i)&1;
            if(p->ne[t]==nullptr) p->ne[t]=new Trie();
            p=p->ne[t];
        }
        p->end=1;
    }
    int find_max(int x) {
        Trie* p = this;
        int res=0;
        for(int i=30;i>=0;i--){
            int t=(x>>i)&1;
            if(p->ne[t^1]!=nullptr){
                res|=(1<<i);
                p=p->ne[t^1];
            }else p=p->ne[t];
        }
        return res;
    }
};


void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),pre(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i],pre[i]=pre[i-1]^a[i];
    Trie tr;
    for(int i=0;i<=n;i++) tr.insert(pre[i]);

    std::vector<int> res(n+2);

    for(int i=0;i<n;i++){
        if(tr.find_max(i)==n-1){
            res[1]=i;
            break;
        }
    }
    
    for(int i=1;i<n;i++){
        res[i+1]=res[1]^pre[i];
    }

    for(int i=1;i<=n;i++) std::cout<<res[i]<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
