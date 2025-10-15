#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n;cin>>n;int sum=0,dp[210];//dp代表当前厚度下所有宽度总宽的大小
    for(int i=0;i<=209;i++)dp[i]=-1e9;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int l,w;cin>>l>>w;
        sum+=w;
        for(int j=209;j>=l;j--)
        {
            dp[j]=max(dp[j],dp[j-l]+w);
        }
    }
    int i;
    for(i=0;i<=209;i++)
    {
        if(sum-dp[i]<=i)
        {cout<<i<<endl;break;}
    }
        
    }
    
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
