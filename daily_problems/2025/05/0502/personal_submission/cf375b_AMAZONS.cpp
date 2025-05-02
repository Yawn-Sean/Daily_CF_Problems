#include<bits/stdc++.h>
using namespace std;
const int N =5010;
const int mod=1e9+7;
typedef long long ll;
vector<string> grp(N);
void solve(){
	int n,m,ans=0;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {string s;cin>>s;grp[i]=" "+s;}
    vector<int> cur(n+7);
    
    for(int j=1;j<=m;j++)
    {
        int cnt[N]={0};
        for(int i=1;i<=n;i++)
        {
            cur[i]=(grp[i][j]=='1'?cur[i]+1:0);
            cnt[cur[i]]++;
        }
        int tmp=0;
        // cout<<cnt[1];
        for(int i=m;i>=0;i--)
        {
            tmp+=cnt[i];
            ans=max(ans,tmp*i);
        }
        // for(auto &x:cur) cnt[x]--;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
