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
    int x;
    std::cin>>x;
    if(x==3){
        std::cout<<5<<"\n";
    }else{
        std::vector<int> a(1000);
        int cnt=0;
        for(int i=0;cnt<200;i++){
            cnt=((2*i+1)*(2*i+1)+1)/2;
            a[i]=cnt;
        }
        int idx=0;
        while(a[idx]<x) idx++;
        std::cout<<idx*2+1<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
