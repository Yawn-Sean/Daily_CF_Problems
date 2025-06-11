constexpr ll MOD = 1E9 + 7; 
ll fapow(ll x, ll t){
    ll ans = 1;
    while(t){
        if(t & 1){
            ans = (ans * x) % MOD;
        }
        t >>= 1;
        x = (x * x) % MOD;
    }
    return ans;
}


int main(void){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, g;
    cin >> n >> m >> g;
    vector<ll> fac(n + 1 + m, 1LL), rev(n + 1 + m, 1LL);
    for(int i = 1; i <= n + m; i++){
        fac[i] = (fac[i - 1] * ll(i)) % MOD;
    }
    rev[n + m] = fapow(fac[n + m], MOD - 2);
    for(int i = n  + m - 1; i > 0; i--){
        rev[i] = (rev[i + 1] * ll(i + 1)) % MOD;
        
    }

    ll ans = 0;
    auto c = [&](ll u, ll d){
        ll res = ((fac[d] * rev[d - u]) % MOD * rev[u]) % MOD;
        return res;
    };
    
    
    //偶数个0变成1，奇数个变成0
    
    for(int i = (g ? 1 : 0); i <= min(n, (n + m - 2)) && m; i += 2){//i表示有多少个0， 保证1后还有数字？            
        //cout << i << "\n";
        ans = (ans + c(m - 1, n + m - i - 1)) % MOD;
    }
    if(m == 1){
        ans += (g ? (n % 2 == 0) : (n % 2 == 1));
    }
    else if(!m){
        ans = (ans + (g ? n % 2 == 0 : n % 2 == 1)) % MOD;
    }
    cout << ans % MOD<< "\n";
}
