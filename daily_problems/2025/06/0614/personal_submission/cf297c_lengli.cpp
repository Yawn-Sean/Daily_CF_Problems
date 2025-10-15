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
    std::vector<std::array<int,2>> s(n+2);
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        s[i]={x,i};
    }
    std::sort(s.begin()+1,s.end()-1);
    
    int k=n/3;
    if(n%3) k++;

    std::vector<int> a(n+2),b(n+2);

    for(int i=1;i<=k;i++){
        auto [v,j]=s[i];
        b[j]=i-1;
        a[j]=v-b[j];
    }
    for(int i=k+1;i<=n-k;i++){
        auto [v,j]=s[i];
        a[j]=i-1;
        b[j]=v-a[j];
    }
    for(int i=n-k+1;i<=n;i++){
        auto [v,j]=s[i];
        a[j]=n-i;
        b[j]=v-a[j];
    }
    std::cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++) std::cout<<a[i]<<" ";
    std::cout<<"\n";
    for(int i=1;i<=n;i++) std::cout<<b[i]<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
