/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    std::string s;
    int k;
    std::cin>>s>>k;
    int n=s.size();
    std::vector<std::vector<int>> g(n+2,std::vector<int> (n+2,0));
    auto cal=[&](int l,int r){
        int ans=0;
        for(int i=l,j=r;i<j;i++,j--) ans+=s[i]!=s[j];
        return ans;
    };
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            g[i][j]=cal(i-1,j-1);
        }
    }
    std::vector<std::vector<int>> f(n+2,std::vector<int> (k+2,inf));
    std::vector<std::vector<int>> pre(n+2,std::vector<int> (k+2,-1));
    f[0][0]=0;
    int res=inf,cnt=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            for(int la=0;la<i;la++){
                int v=f[la][j-1]+g[la+1][i];
                if(v<f[i][j]){
                    f[i][j]=v;
                    pre[i][j]=la;
                }
                if(i==n and f[i][j]<res){
                    res=f[i][j];
                    cnt=j;
                }
            }
        }
    }
    std::cout<<res<<"\n";
    std::string out="";
    int idx=n;
    while(cnt){
        int la=pre[idx][cnt];
        for(int l=la+1,r=idx;l<r;l++,r--){
            if(s[l-1]!=s[r-1]) s[l-1]=s[r-1];
        }
        for(int i=idx;i>la;i--) out+=s[i-1];
        out+="+";
        idx=la;cnt--;
    }
    out.pop_back();
    reverse(all(out));
    std::cout<<out<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
