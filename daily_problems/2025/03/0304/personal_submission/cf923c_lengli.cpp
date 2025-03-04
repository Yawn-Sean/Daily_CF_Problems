/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=300010;

int nex[N*32][2],idx;
int cnt[N*32];

void insert(int x) {
    int p=0;
    for(int i=30;i>=0;i--){
        int c=(x>>i&1);
        if(!nex[p][c]) nex[p][c]=++idx;
        p=nex[p][c];
        cnt[p]++;
    }
}

int find(int x){
    int p=0;
    int res=0;
    for (int i=30;i>=0;i--) {
        int c=(x>>i&1);
        if(nex[p][c] and cnt[nex[p][c]]){
            p=nex[p][c];
            cnt[p]--;
        }else {
            p=nex[p][c^1];
            res+=(1<<i);
            cnt[p]--;
        }
    }
    return res;
}

int n;
int a[N],b[N];

void solve(){
    std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>a[i];   
    for(int i=1;i<=n;i++) {
        std::cin>>b[i];
        insert(b[i]);
    }
    for(int i=1;i<=n;i++){
        auto v=find(a[i]);
        std::cout<<v<<" ";
    }

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
