// 只考虑前 n 行，i + n 行的情况(数量数a)是一致的，方案数为v=i方案 ^ a
/* 在考虑每一行时，枚举该行放几个(x)， dp[i-1][x-j] * v 为此次枚举方案数，
累加 x 得到的结果，即为该行以及之前行的方案数 */
// 结果为 dp[n][k];
void solve(){
    int mod = 1e9+7;
    int n,m,k; cin >> n >> m >> k;
    MAT combs(n+1, VC(n+1));
    
    For(i,0,n){
        combs[i][0] = 1;
        For(j,1,i) {
            combs[i][j] = (combs[i-1][j] + combs[i-1][j-1]) % mod;
        }   
    }
    
    auto qpow = [&](int x, int y){
        int res = 1;
        while(y > 0){
            if(y & 1) res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    };

    int a = m/n, b = m%n;
    VC dp(k+1), ndp(k+1);
    dp[0] = 1;

    For(i,1,n){
        For(j,0,n){
            int v = qpow(combs[n][j], (i<=b?a+1:a));
            for(int cur = 0; cur + j <= k; cur ++){
                ndp[cur + j] = (ndp[cur + j] + (dp[cur] * v % mod)) % mod;
            }
        }
        For(j,0,k){
            dp[j] = ndp[j];
            ndp[j] = 0;
        }
    }
    cout << dp[k] << endl;
}
