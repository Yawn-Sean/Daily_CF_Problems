#include<bits/stdc++.h>
#define endl '\n'
using i64 =long long;
void solve(){
    std::string s;
    std::cin>>s;
    int n=s.size();
    if(n>=26*99+1){
        std::vector<int> cnt(26);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]>=100){
                for(int j=0;j<100;j++){
                    std::cout<<char(i+'a');
                }
                return;
            }
        }
    }
    std::vector<std::vector<int>> dp(n,std::vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            if(s[i]==s[i+len-1]){
                dp[i][i+len-1]=dp[i+1][i+len-2]+2;
            }
            else{
                dp[i][i+len-1]=std::max(dp[i+1][i+len-1],dp[i][i+len-2]);
            }
        }
    }
    std::vector<char> ans;
    int l=0;
    int r=n-1;
    while(l<r){
        if(s[l]==s[r]){
            ans.push_back(s[l]);
            l++;
            r--;
        }
        else{
            if(dp[l+1][r]==dp[l][r]){
                l++;
            }
            else{
                r--;
            }
        }
    }
    if(ans.size()>=50){
        for(int i=0;i<50;i++){
            std::cout<<ans[i];
        }
        for(int i=49;i>=0;i--){
            std::cout<<ans[i];
        }
    }
    else{
        for(auto x:ans){
            std::cout<<x;
        }
        if(l==r){
            std::cout<<s[l];
        }
        for(int i=(int)ans.size()-1;i>=0;i--){
            std::cout<<ans[i];
        }
    }
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    solve();
}
