/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    if(n==0){
        std::cout<<"+"<<"\n";
        return;
    }
    int mx=(1<<n),cnt=mx/2;
    std::vector<std::vector<char>> res(mx,std::vector<char> (mx));

    auto dfs=[&](auto self,int k)->void{
        if(k==1){
            res[0][0]='+',res[1][0]='+',res[0][1]='+';
            res[1][1]='*';
            return;
        }
        self(self,k-1);
        int len=(1<<k)/2;
        for(int i=0;i<len;i++)
            for(int j=len;j<len*2;j++) res[i][j]=res[i][j-len];
        for(int i=len;i<len*2;i++)
            for(int j=0;j<len;j++) res[i][j]=res[i-len][j];
        for(int i=len;i<len*2;i++)
            for(int j=len;j<len*2;j++) {
                res[i][j]=res[i-len][j]=='*' ? '+' : '*';
            }
    };

    dfs(dfs,n);

    for(auto x:res){
        for(auto y:x) std::cout<<y;
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
