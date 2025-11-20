/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100010;

struct Trie {
    int nex[N*32][2], idx;
    int cnt[N*32];
    void init(){
        for(int i=0;i<N*32;i++) cnt[i]=0;
        for(int i=0;i<N*32;i++){
            for(int j=0;j<2;j++) nex[i][j]=0;
        }
        idx=0;
    }
    void insert(int x,int k){
        int p=0;
        for(int i=31;i>=0;i--){
            int c=(x>>i)&1;
            if(!nex[p][c]) nex[p][c]=++idx;
            p=nex[p][c];
            cnt[p]+=k;
        }
    }
    
    int find(int x){
        int p=0;
        int res=0;
        for(int i=31;i>=0;i--) {
	        int c=(x>>i)&1;
	        if(nex[p][c] and cnt[nex[p][c]]) p=nex[p][c];
	        else {
                p=nex[p][c^1];
                res+=(1<<i);
            }
        }
        return res;
    }
}tr;

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    auto cal=[&](int val)->i64{
        i64 res=0;
        tr.init();
        for(int i=1,j=1;i<=n;i++){
            if(i==j) tr.insert(a[j],1),j++;
            while(j<=n){
                if(tr.find(a[j])>=val){
                    tr.insert(a[j],1),j++;
                }
                else break;
            }
            res+=j-i;
            tr.insert(a[i],-1);
        }
        return res;
    };

    std::cout<<cal(k)-cal(k+1)<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
