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
    int n,a,b;
    std::cin>>n>>a>>b;
    std::vector<int> res(n,1);
    i64 sum=1,x=1;

    if(!b){
        for(int i=2;i<n and a;i++){
            x++;
            sum+=x;
            res[i]=x;
            a--;
            
        }
    }else{
        for(int i=1;i<n and (a or b);i++){
            if(!b){
                x++;
                sum+=x;
                res[i]=x;
                a--;
            }else{
                x=sum+1;
                sum+=x;
                res[i]=x;
                b--;
            }
        }
    }
    
    if(a or b){
        std::cout<<"-1"<<"\n";
        return;
    }

    for(int i=0;i<n;i++){
        if(res[i]>50000){
            std::cout<<"-1"<<"\n";
            return;
        }
    }
    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
