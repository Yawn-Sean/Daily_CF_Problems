#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	int n;cin>>n;
    vector<int> v(n+1);
    vector<pair<int,int>> vp;
    for(int i=1;i<=n;i++)cin>>v[i],vp.push_back({v[i],i});;
    sort(vp.begin(),vp.end());
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    while(!vp.empty()){
        int x=vp.back().first;
        int idx=vp.back().second;
        vp.pop_back();
        for(int j=idx%x;j<=n;j+=x){
            if(v[j]>x&&dp[j]==0){
                dp[idx]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i]==1){
            cout<<'A';
        }
        else{
            cout<<'B';
        }
    }
    cout<<endl;
    return ;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
