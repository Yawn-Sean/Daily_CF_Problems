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
    if(n&1) std::cout<<"-1"<<"\n";
    else{
        std::vector<std::vector<int>> res(n,std::vector<int> (n,0));

        for(int i=0;i<n;i++){
            for(int j=0,k=0;j<n;j+=2,k++){
                if(i&1){
                    if(k&1) continue;
                    else res[i][j]=1,res[i][j+1]=1;
                }else{
                    if(k&1) res[i][j]=1,res[i][j+1]=1;
                }
            }
        }

        for(int i=0,k=0;i<n;i+=2,k++){
            for(auto x:res){
                for(auto y:x){
                    if(k&1) std::cout<<(y ? "b" : "w");
                    else std::cout<<(y ? "w" : "b");
                }
                std::cout<<"\n";
            }
            for(auto x:res){
                for(auto y:x){
                    if(k&1) std::cout<<(y ? "b" : "w");
                    else std::cout<<(y ? "w" : "b");
                }
                std::cout<<"\n";
            }
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
