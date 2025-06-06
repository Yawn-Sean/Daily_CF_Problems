void solve(){
    int n, m;
    cin >> n >> m;
    const int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};
    vector <int> mis(4, inf_int);
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            char ch;
            cin >> ch;
            if (ch == 'B'){
                for (int k = 0; k < 4; ++ k){
                    mis[k] = min(mis[k], i*dx[k] + j*dy[k]);                    
                }
            }
        }
    }
    int res = inf_int, res_x, res_y;

    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            int ans = -inf_int;
            for (int k = 0; k < 4; ++ k){
                int x = i*dx[k], y = j*dy[k];
                fmax(ans, x+y-mis[k]);
            }
            if (res > ans){
                res = ans;
                res_x = i, res_y = j;
            }
        }
    }

    cout << res_x << " " << res_y << "\n";
}
