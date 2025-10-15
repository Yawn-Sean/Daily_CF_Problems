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
const int N=5e5+5;
int dp[N];
void slove(){
    int a,b,k;
    cin>>b>>a>>k;
    int c=1;
    for(int i=1;i<=k;i++)c=lcm(c,i);
    int A=a,B=b;
    if(a/c==b/c){
        fill(dp,dp+N,INF);
        a=a%c;
        b=b%c;
        dp[b]=0;
        //cout<<a<<" "<<b<<" "<<c<<" "<<dp[b]<<"\n";
        for(int i=b;i>a;i--){
            dp[i-1]=min(dp[i-1],dp[i]+1);
            for(int j=k;j>1;j--){
                dp[i-i%j]=min(dp[i-i%j],dp[i]+1);
            }
        }
        cout<<dp[a]<<'\n';
    }else{
        
        fill(dp,dp+N,INF);
        int ans=0;
        a=a%c;
        b=b%c;
        dp[b]=0;
        for(int i=b;i>=1;i--){
            dp[i-1]=min(dp[i-1],dp[i]+1);
            for(int j=k;j>1;j--){
                dp[i-i%j]=min(dp[i-i%j],dp[i]+1);
            }
        }
        ans=dp[0];
        fill(dp,dp+N,INF);
        dp[c]=0;
        for(int i=c;i>=1;i--){
            dp[i-1]=min(dp[i-1],dp[i]+1);
            for(int j=k;j>1;j--){
                dp[i-i%j]=min(dp[i-i%j],dp[i]+1);
            }
        }
        ans+=dp[0]*(B/c-A/c-1);
        fill(dp,dp+N,INF);
        dp[c]=0;
        for(int i=c;i>a;i--){
            dp[i-1]=min(dp[i-1],dp[i]+1);
            for(int j=k;j>1;j--){
                dp[i-i%j]=min(dp[i-i%j],dp[i]+1);
            }
        }
        ans+=dp[a];
        cout<<ans<<'\n';
    }
}
signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("test.in", "w", stdout);
    // cout<<fixed<<setprecision(3);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)slove();
    return 0;
}
