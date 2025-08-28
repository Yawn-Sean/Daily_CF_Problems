// #pragma GCC optimize("O2,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i64 long long
#define double long double
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define ull unsigned long long
#define vi vector<int>
using i128 = __int128;
#define vpii  vector<pii>
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
const int N=1e5+5;
int dp[N][2],dp1[N];
void slove(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=1;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]>=2)dp[i][0]=dp[i-1][0]+a[i]/2*2;
        if(a[i]>=1)dp[i][1]=max(dp[i-1][1],dp[i-1][0])+(a[i]-1)/2*2+1;
    }
    for(int i=n-2;i>=0;i--){
        int x=a[i+1];
        if(x>=2)dp1[i]=dp1[i+1]+x/2*2;
    }
    int ans=0;
    for(int i=0;i<n;i++){
       ans=max(ans,max(dp[i][0],dp[i][1])+dp1[i]);
    }
    cout<<ans<<'\n';
}
signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("test.in", "w", stdout);
    // cout<<fixed<<setprecision(3);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)slove();
    return 0;
}
