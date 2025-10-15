void solve(){
    int n, s, k;
    string rgb;
    cin >> n >> s >> k;
    vector <int> A(n+1), ids(n+1);
    vector<vector<int>> f(n+1, vector<int>(k+1, inf_int));
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
        ids[i] = i;
    }
    cin >> rgb;
    rgb = " " + rgb;

    sort(ids.begin()+1, ids.end(), [&](int &u, int &v){
        return A[u] < A[v];
    });

    // only movement denotes the cost
    f[0][0] = 0;
    for (int i = 0; i < n; ++ i){
        if (i == 0){
            for (int u = 1; u <= n; ++ u){
                int nxt = ids[u];
                fmin(f[u][min(A[nxt], k)], abs(s-nxt));
            }
        } else {
            for (int j = 0; j < k; ++ j){
                if (f[i][j] == inf_int) continue;

                int lst = ids[i];
                for (int u = i+1; u <= n; ++ u){
                    int nxt = ids[u];
                    if (A[lst] == A[nxt] || rgb[lst] == rgb[nxt]) continue;

                    assert(A[nxt] > A[lst]);
                    fmin(f[u][min(j+A[nxt], k)], f[i][j] + abs(lst-nxt));
                }
            }
        }
    }

    int res = inf_int;
    for (int i = 1; i <= n; ++ i){
        fmin(res, f[i][k]);
    }

    cout << (res == inf_int ? -1 : res) << "\n";
}
