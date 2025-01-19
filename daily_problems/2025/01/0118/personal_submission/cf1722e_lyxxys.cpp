const int N = 1001;
static i64 f[N][N];

void solve(){
    for (int i = 1; i < N; ++ i){
        for (int j = 1; j < N; ++ j){
            f[i][j] = 0;
        }
    }

    int n, q;
    cin >> n >> q;
    for (int i = 0,h,w; i < n; ++ i){
        cin >> h >> w;
        f[h][w] += h*w;
    }

    for (int i = 1; i < N; ++ i){
        for (int j = 1; j < N; ++ j){
            f[i][j] += f[i][j-1] + f[i-1][j] - f[i-1][j-1];
        }
    }
    
    while (q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (c == a+1 || d == b+1){
            cout << 0 << "\n";
        } else {
            cout << f[c-1][d-1]-f[c-1][b]-f[a][d-1]+f[a][b] << "\n";
        }
    }
}
