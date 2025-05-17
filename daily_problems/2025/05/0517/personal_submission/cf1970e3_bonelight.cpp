// 动态规划 + 矩阵快速幂优化
void solve(){
    int n,k; cin >> n >> k;
    int mod = 1e9 + 7;
    VC a(n), b(n);
    For(i,0,n-1) cin >> a[i];
    For(i,0,n-1) cin >> b[i];
    MAT g(2, VC(2));
    
    For(i,0,n-1){
        g[0][0] = (g[0][0] + (a[i]+b[i])*a[i]) % mod; // (可长短)/短 -> 长/短
        g[0][1] = (g[0][1] + (a[i]+b[i])*b[i]) % mod; 
        g[1][0] = (g[1][0] + a[i]*a[i]) % mod; 
        g[1][1] = (g[1][1] + a[i]*b[i]) % mod; 
    }
    
    auto mulM = [&](MAT x, MAT y) -> MAT {
        int sz = y.size();
        MAT res = MAT(sz,VC(sz));

        For(i,0,x.size()-1)
        For(j,0,y[0].size()-1)
        For(k,0,sz-1){
            res[i][j] = (res[i][j] + x[i][k]*y[k][j]) % mod;
        }
        return res;
    };

    auto qmulM = [&](MAT x, int y){
        MAT res(2,VC(2));
        For(i,0,1) res[i][i] = 1;
        while(y > 0){
            if(y & 1) res = mulM(res,x);
            x = mulM(x,x); 
            y >>= 1;
        }
        return res;
    };

    g = qmulM(g,k-1);

    int s = accumulate(all(a), 0ll) % mod;
    int l = accumulate(all(b), 0ll) % mod;

    int ans = (a[0]*g[0][0] + b[0]*g[1][0]) % mod * (s+l) % mod;
    ans = (ans + (a[0]*g[0][1]+ b[0]*g[1][1]) % mod * s) % mod;
    cout << ans << endl;
}
