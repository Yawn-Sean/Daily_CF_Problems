#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using d64=double;
using ld64=long double;
void solve(){
    std::string s;
    int k;
    std::cin>>s>>k;
    int n=s.size();
    int m;
    std::cin>>m;
    std::vector mp(26,std::vector<int>(26,0));
    char a,b;
    int c;
    for(int i=0;i<m;i++){
        std::cin>>a>>b>>c;
        mp[a-'a'][b-'a']=c;
    }
    std::vector dp(26,std::vector<i64>(k+1,-4e18));
    dp[s[0]-'a'][0]=0;
    if(k!=0){
        for(int i=0;i<26;i++){
            dp[i][1]=0;
        }
    }
    for(int i=1;i<n;i++){
        std::vector ndp(26,std::vector<i64>(k+1,-4e18));
        for(int j=0;j<26;j++){
            for(int l=0;l<k;l++){
                if(dp[j][l]==-4e18){
                    continue;
                }
                for(int q=0;q<26;q++){
                    ndp[q][l+1]=std::max(ndp[q][l+1],dp[j][l]+mp[j][q]);

                }
            }
            for(int l=0;l<=k;l++){
                if(dp[j][l]==-4e18){
                    continue;
                }
                ndp[s[i]-'a'][l]=std::max(ndp[s[i]-'a'][l],dp[j][l]+mp[j][s[i]-'a']);
            }
        }
        dp=std::move(ndp);
    }
    i64 ans=-4e18;
    for(int i=0;i<26;i++){
        for(int j=0;j<=k;j++){
            ans=std::max(dp[i][j],ans);
        }

    }
    std::cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
