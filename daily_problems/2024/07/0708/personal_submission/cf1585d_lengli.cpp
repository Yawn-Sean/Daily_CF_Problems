/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=500010;

struct BIT{
    int n=N-1;
    int a[N];
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=n;i+=lowbit(i)) a[i]+=c;}
    void init(int len){
        for(int i=0;i<=len+2;i++) a[i]=0;
    }
    long long sum(int x){
        long long res=0;
        for(int i=x;i;i-=lowbit(i)) res+=a[i];
        return res;
    }
    
}tr;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),cnt(n+2);
    bool flag=0;
    for(int i=1;i<=n;i++) {
        std::cin>>a[i];
        cnt[a[i]]++;
        if(cnt[a[i]]>=2) flag=1;
    }
    if(flag){
        std::cout<<"YES"<<"\n";
        return;
    }
    tr.init(n);
    int res=0;
    for(int i=1;i<=n;i++){
        tr.add(a[i],1);
        res+=i-tr.sum(a[i]);
    }
    std::cout<<(res&1 ? "NO" : "YES")<<"\n";

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
