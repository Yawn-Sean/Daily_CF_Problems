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
    int n,k,p;
    std::cin>>n>>k>>p;
    std::vector<int> a(n);

    std::vector<int> odd,even;

    for(auto &x:a){
        std::cin>>x;
        if(x%2==0) even.pb(x);
        else odd.pb(x);
    }

    int i=0,j=0;
    int l=odd.size(),r=even.size();
    std::vector<std::vector<int>> res(k);
    if(l>=k-p and (l-k+p)%2==0 and (l-k+p)/2+r>=p){
        std::cout<<"YES"<<"\n";
        int t;
        for(t=0;t<p;t++){
            if(i<r) res[t].pb(even[i]),i++;
            else{
                res[t].pb(odd[j]),j++;
                res[t].pb(odd[j]),j++;
            }
        }
        while(i<r) res[0].pb(even[i]),i++;
        for(;t<k and j<l;t++) res[t].pb(odd[j]),j++;
        while(j<l) res[0].pb(odd[j]),j++;
        for(int t=0;t<k and res[t].size();t++){
            std::cout<<res[t].size()<<" ";
            for(int tt=0;tt<res[t].size() and res[t][tt];tt++){
                std::cout<<res[t][tt]<<" ";
            }
            std::cout<<"\n";
        }
    }else std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
