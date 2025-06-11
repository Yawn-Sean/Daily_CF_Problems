/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9;

struct BIT{
    int mn;
    std::vector<int> a;
    BIT(){};
    BIT(int n){
        a.clear(),a.resize(n+2,inf);
        mn=n;
    };
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=mn;i+=lowbit(i)) a[i]=std::min(a[i],c);}
    int sum(int x){
        int res=inf;
        for(int i=x;i;i-=lowbit(i)) res=std::min(res,a[i]);
        return res;
    }
};

void solve(){
    std::string s;
    std::cin>>s;
    int n=s.size();
    std::vector<int> b(n+2);
    for(int i=1;i<=n;i++){
        s[i-1]=std::tolower(s[i-1]);
        if(s[i-1]=='a') b[i]=-1;
        else if(s[i-1]=='e') b[i]=-1;
        else if(s[i-1]=='i') b[i]=-1;
        else if(s[i-1]=='o') b[i]=-1;
        else if(s[i-1]=='u') b[i]=-1;
        else b[i]=2;
    }
    std::vector<int> q={0};
    for(int i=1;i<=n;i++) {
        b[i]+=b[i-1];
        q.pb(b[i]);
    }
    sort(all(q));
    q.erase(unique(all(q)),q.end());
    auto find=[&](int x){
        return std::lower_bound(all(q),x)-q.begin()+1;
    };

    BIT tr(n+2);
    tr.add(find(0),0);
    int len=0;
    for(int i=1;i<=n;i++){
        int t=find(b[i]);
        int idx=tr.sum(t);
        if(idx<=i){
            len=std::max(len,i-idx);
        }
        tr.add(t,i);
    }

    if(len==0){
        std::cout<<"No solution"<<"\n";
        return;
    }
    int res=0;
    for(int i=0,j=len;j<=n;i++,j++){
        if(b[j]-b[i]>=0) res++;
    }
    std::cout<<len<<" "<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
