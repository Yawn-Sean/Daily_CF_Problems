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
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<std::vector<char>> a(n+2,std::vector<char> (m+2,0));
    std::vector<std::vector<int>> cnt(n+2,std::vector<int> (m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) std::cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt[i][j]=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
            if(a[i][j]=='a') cnt[i][j]++;
        }
    }

    i64 res=0;
    for(int i=1;i<=n-1;i++){
        std::vector<int> num(30,0);
        for(int j=i+1;j<=n;j++){
            for(int l=1,r=1;l<=m;l++){
                if(a[i][l]!=a[j][l]) continue;
                num[a[i][l]-'a']--;
                while(r<=m and cnt[j][r]-cnt[i-1][r]-cnt[j][l-1]+cnt[i-1][l-1]<=k){
                    if(a[i][r]==a[j][r]) num[a[i][r]-'a']++;
                    r++;
                }
                if(num[a[i][l]-'a']>0) res+=num[a[i][l]-'a'];
            }
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    std::freopen("input.txt","r",stdin);
    std::freopen("output.txt","w",stdout);

    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
