void solve(){
    string s;
    int k, n, m;
    cin >> s >> k;
    n = s.size();
    cin >> m;
    map <int,int> M;
    auto ID = [&](int i, int j)->int{
        return i*26 + j;
    };
    auto W = [&](int i, int j)->int{
        return M[ID(i, j)];
    };
    for (int i = 0; i < m; ++ i){
        string u, v;
        int w;
        cin >> u >> v >> w;
        M[ID(u[0]-'a', v[0]-'a')] = w;
    }

    vector<vector<int>> f1(26, vector<int>(k+1, -inf_int)), f2(26, vector<int>(k+1, -inf_int));
    
    for (int i = 0; i < 26; ++ i){
        if (i == s[0]-'a'){
            f1[i][0] = 0;
        } else {
            if (k > 0){
                f1[i][1] = 0;
            }
        }
    }

    for (int i = 1; i < n; ++ i){

        for (int j = 0; j < 26; ++ j){
            for (int u = 0; u < 26; ++ u){
                int cost = W(u, j);
                for (int v = 0; v <= k; ++ v){
                    if (j == s[i]-'a'){
                        fmax(f2[j][v], f1[u][v] + cost);
                    } else {
                        if (v < k){
                            fmax(f2[j][v+1], f1[u][v] + cost);
                        }
                    }
                }
            }
        }
        for (int u = 0; u < 26; ++ u){
            for (int v = 0; v <= k; ++ v){
                f1[u][v] = f2[u][v];
                f2[u][v] = -inf_int;
            }
        }
    }

    int res = -inf_int;
    for (int i = 0; i < 26; ++ i){
        for (int j = 0; j <= k; ++ j){
            fmax(res, f1[i][j]);
        }
    }

    cout << res << "\n";
}
