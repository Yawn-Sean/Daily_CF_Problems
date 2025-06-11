void solve(){
    const int N = 16000000, det = 8000000;

    int n, k;
    cin >> k >> n;
    vector <int> A(k), B(n);
    vector<vector<int>> gs(N);

    for (auto &x : A){
        cin >> x;
    }
    for (auto &x : B){
        cin >> x;
    }

    for (int i = 0, cur = 0; i < k; ++ i){
        cur += A[i];
        for (int j = 0; j < n; ++ j){
            gs[B[j]-cur+det].push_back(j);
        }
    }

    int res = 0;
    vector <int> vis(n);
    for (int i = 0; i < N; ++ i){
        auto &vec = gs[i];
        if (vec.size() < n) continue;

        int cnt = 0;
        for (auto &x : vec){
            if (!vis[x]){
                cnt += 1;
                vis[x] = 1;
            }
        }
        for (auto &x : vec){
            vis[x] = 0;
        }
        if (cnt == n){
            res += 1;
        }
    }

    cout << res << "\n";
}

