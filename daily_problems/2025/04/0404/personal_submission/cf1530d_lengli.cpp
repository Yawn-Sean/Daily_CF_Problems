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
    std::vector<int> st(n+2);
    int cnt=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        if(!st[a[i]]) cnt++;
        st[a[i]]=1;
    }
    
    std::vector<int> res(n+2),use(n+2);

    for(int i=1;i<=n;i++){
        if(st[a[i]] and !use[a[i]]) res[i]=a[i],use[a[i]]=1;
    }
    for(int i=1,j=1;i<=n;i++){
        if(!res[i]){
            while(use[j]) j++;
            res[i]=j;
            use[j]=1;
        }
    }

    std::vector<int> ne(n+2);
    for(int i=1;i<=n;i++) ne[res[i]]=i;
    for(int i=1;i<=n;i++){
        if(res[i]==i) std::swap(res[ne[a[i]]],res[i]);
    }
    std::cout<<cnt<<"\n";
    for(int i=1;i<=n;i++){
        std::cout<<res[i]<<" ";
    }std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
