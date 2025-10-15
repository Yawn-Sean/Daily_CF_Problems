#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define endl "\n"
#define MOD 1000000007
#define mod 998244353
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>> 
#define pi pair<int, int>
#define fr(i, l, r) for(int i=l; i<=r; i++)
#define rep(i, l, r) for(int i=(int)l; i>=(int)r; i--)

#define sz(x) (int)x.size()
 
const int INF = 2e18;
const int N = 1e6+5;


int power(int a, int p){
    if(p==0) return 1;
    if(a==0){
        return 0;
    }
    int res = 1;
    a %= MOD;
    while(p>0){
        if(p&1)
            res = (res*a)%MOD;
        p >>= 1;
        a = (a*a)%MOD;
    }
    return res%MOD;
}

int fact[N];
int inv[N];
void pre(){
    fact[0] = 1;
    int i;
    fr(i,1,N-1)
        fact[i] = fact[i-1]*1ll*i%MOD;
    inv[N-1] = power(fact[N-1], MOD-2);    
    rep(i, N-2, 0)
        inv[i] = inv[i+1]*1ll*(i+1)%MOD;
}

int nCr(int n, int r)
{
    if(n < 0 || r < 0 || n < r)
        return 0;
    int ans = fact[n]*1ll*inv[r]%MOD;
    ans = ans*1ll*inv[n-r]%MOD;
    return ans;    
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    if(m==1){
        cout << power(k, n) << endl;
        return;
    }
    
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    fr(i, 1, n){
        fr(j, 1, i){
            dp[i][j] = (dp[i-1][j-1] + (dp[i-1][j]*j)%MOD)%MOD;
        }
    }

    int ans = 0;
    fr(y, 0, n){
        int rest = power(y, n*(m-2));
        // cout << rest << endl;
        fr(x, y, n){
            if(2*x-y>k) continue;

            int temp = nCr(k, 2*x-y);
            temp = (temp * nCr(2*x-y, x-y))%MOD;
            temp = (temp * nCr(x, x-y))%MOD;
            temp = (temp * power(dp[n][x], 2))%MOD;
            temp = (temp * power(fact[x], 2))%MOD;
            temp = (temp * rest)%MOD;
            ans = (ans + temp)%MOD;
            // cout << ans << endl;
        }
    }

    cout << ans << endl;
}   

 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    pre();
    while (t--)
    {
        solve();
    }
}
  	   		 	 		 	 		 	   	 	  			
