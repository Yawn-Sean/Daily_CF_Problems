// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i64 long long
#define db long double
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ull unsigned long long
#define vi vector<int>
using i128 = __int128;
//#define endl '\n'
#define vpii vector<pii>
#define vvpii vector<vector<pii>>
#define vvi vector<vector<int>>
#define pqpii priority_queue<pii, vector<pii>, greater<pii>>
#define pqi priority_queue<int,vector<int>, greater<int>>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define INF 1e18
#define exp 1e-12
const int N=1e6+5;
priority_queue<pii> q[26];
void slove(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi dp(n+1),pre(n+1);
    dp[0]=0;
    for(int i=0;i<26;i++)q[i].push({-N,0});
    for(int i=1;i<=n;i++){
        int now=s[i-1]-'a';
        dp[i]=q[now].top().f+1;
        pre[i]=q[now].top().s;
        q[now].push({dp[i-1],i-1});
    }
    if(dp[n]<0){
        cout<<-1<<endl;
        return;
    }
    vi ans;
    // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    while(n){
        ans.pb(n-pre[n]);
        n=pre[n];
    }
    reverse(all(ans));
    cout<<sz(ans)<<endl;
    for(auto i:ans)cout<<i<<" ";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //cout<<fixed<<setprecision(10);
    int t=1;
    //cin>>t;
    while (t--) slove();
    return 0;
}
