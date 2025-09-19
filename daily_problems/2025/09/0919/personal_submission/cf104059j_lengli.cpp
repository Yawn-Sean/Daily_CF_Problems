/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    std::string s;
    std::cin>>s;
    int n=s.size();

    int res=inf;

    std::vector<char> q={'h','c','d','s'};

    auto check=[&](std::vector<char> &a){
        std::vector<std::vector<int>> f(n+2,std::vector<int> (4,0));

        for(int i=1;i<=n;i++){
            for(int j=0;j<4;j++){
                if(s[i-1]==a[j]){
                    f[i][j]=inf;
                    for(int k=0;k<=j;k++){
                        f[i][j]=std::min(f[i][j],f[i-1][k]);
                    }
                }else{
                    f[i][j]=f[i-1][j]+1;
                }
            }
        }
        int ans=inf;
        for(int i=0;i<4;i++) ans=std::min(ans,f[n][i]);
        return ans;
    };

    std::sort(all(q));

    do{
        res=std::min(check(q),res);
    }while(std::next_permutation(all(q)));
    std::cout<<res<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
