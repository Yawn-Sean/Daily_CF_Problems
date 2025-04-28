void solve(){
    string nums[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    vector <int> g(10);
    for (int i = 0; i < 10; ++ i){
        int cur = 0;
        for (int j = 0; j < 7; ++ j){
            if (nums[i][j] == '1'){
                cur += 1 << j;
            }
        }
        g[i] = cur;
    }

    int n, k;
    cin >> n >> k;
    vector<vector<int>> f(n+2, vector<int>(k+1, -inf_int)), last(n+2, vector<int>(k+1, -inf_int));
    vector <int> A(n+1);

    for (int i = 1; i <= n; ++ i){
        string s;
        cin >> s;
        int cur = 0;
        for (int j = 0; j < 7; ++ j){
            if (s[j] == '1') cur += 1 << j;
        }
        A[i] = cur;
    }
    f[n+1][0] = 0;
    for (int i = n+1; i > 1; -- i){
        for (int j = 0; j <= k; ++ j){
            if (f[i][j] == -inf_int) continue;
            int x = A[i-1];
            for (int u = 0; u < 10; ++ u){
                if ((x|g[u]) == g[u]){
                    int c = __builtin_popcount(g[u]) - __builtin_popcount(x);
                    if (j+c <= k){
                        if (u > f[i-1][j+c]){
                            f[i-1][j+c] = u;
                            last[i-1][j+c] = j;
                        }
                    }
                }
            }
        }
    }

    if (f[1][k] == -inf_int) return void(cout << -1 << "\n");


    vector <int> ans;
    int x = 1, y = k;
    while (x <= n){
        ans.push_back(f[x][y]);
        y = last[x][y];
        x += 1;
    }
    for (auto &x : ans){
        cout << x;
    }
    cout << "\n";
}
