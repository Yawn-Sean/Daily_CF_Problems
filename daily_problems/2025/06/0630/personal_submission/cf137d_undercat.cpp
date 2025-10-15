#include<bits/stdc++.h>
using namespace std;
int cnt[501][501];
int dp[501][501];
int pre[501][501];
void solve(){
    string s;cin>>s;int k;cin>>k;
    int n=s.size();
    for(int l=0;l<n;l++)for(int r=l;r<n;r++){
        int len=r-l+1;
        for(int i=0;i<len/2;i++){
            cnt[l][r]+=(s[l+i]!=s[r-i]);
        }
    }
    memset(dp,0x3f,sizeof dp);
    for(int r=0;r<n;r++)dp[r][0]=cnt[0][r],pre[r][0]=-1;
    for(int r=0;r<n;r++){
        for(int i=1;i<k;i++){
            for(int l=1;l<=r;l++){
                if(dp[r][i]>(dp[l-1][i-1]+cnt[l][r])){
                    dp[r][i]=dp[l-1][i-1]+cnt[l][r];
                    pre[r][i]=l-1;
                }
            }
        }
    }
    int res=1e9,tk=-1;
    for(int i=0;i<k;i++){
        if(dp[n-1][i]<res){
            res=dp[n-1][i];
            tk=i;
        }
    }
    cout<<res<<'\n';
    vector<string>ans;
    int nr=n-1;
    while(pre[nr][tk]!=-1){
        int l=pre[nr][tk]+1;
        int r=nr;
        string temp="";
        for(int i=l;i<=r;i++)temp.push_back(s[i]);
        int len=r-l+1;
        for(int i=0;i<len/2;i++){
            temp[len-1-i]=temp[i];
        }
        tk--;
        ans.push_back(temp);
        nr=l-1;
    }
    int l=0;
    int r=nr;
    string temp="";
    for(int i=l;i<=r;i++)temp.push_back(s[i]);
    int len=r-l+1;
    for(int i=0;i<len/2;i++){
        temp[len-1-i]=temp[i];
    }
    ans.push_back(temp);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i+1<ans.size())cout<<'+';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}
