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
    std::string a,b;
    std::cin>>a>>b;
    for(int i=0;i<a.size();i++){
        int idx=i;
        for(int j=i+1;j<a.size();j++)
            if(a[j]<=a[idx]) idx=j;
        
        std::swap(a[i],a[idx]);
        if(a<b){
            std::cout<<a<<"\n";
            return;
        }
        std::swap(a[i],a[idx]);
    }
    std::cout<<"---"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
