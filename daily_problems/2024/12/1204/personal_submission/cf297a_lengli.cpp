/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::string a,b;
    std::cin>>a>>b;
    int n=a.size(),m=b.size();
    if(n>=m){
        if(a.substr(n-m)==b){
            std::cout<<"YES"<<"\n";
            return;
        }
    }
    int cnt=0,k=0;
    for(auto x:a) cnt+=(x=='1');

    if(cnt&1) cnt++;

    for(auto x:b){
        int hv=(cnt+k)&1;
        if(x=='0'){
            if(hv){
                if(cnt>0) cnt--;
                else{
                    std::cout<<"NO"<<"\n";
                    return;
                }
            }
        }else{
            if(!hv){
                if(!cnt){
                    std::cout<<"NO"<<"\n";
                    return;
                }else cnt--,k++;
            }else{
                k++;
            }
        }
    }
    std::cout<<"YES"<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
