void solve(){
    int n, w, h;
    cin >> n >> w >> h;
    vector <int> idx1, idx2;
    vector <array<int,3>> g(n);
    for (int i = 0; i < n; ++ i){
        cin >> g[i][0] >> g[i][1] >> g[i][2];
        if (g[i][0] == 1) idx1.push_back(i);
        else idx2.push_back(i);
    }
    vector<deque<int>> Qs;
    auto W = [&](int u)->int{
        return g[u][1] - g[u][2];
    };
    sort(idx2.begin(), idx2.end(), [&](auto &u, auto &v){
        return W(u) == W(v) ? g[u][1] < g[v][1] : W(u) < W(v);
    });
    sort(idx1.begin(), idx1.end(), [&](auto &u, auto &v){
        return W(u) == W(v) ? g[u][1] < g[v][1] : W(u) < W(v);
    });
    // print(idx2);
    vector<int> who(idx2.size(), -1), f(idx1.begin(), idx1.end());
    for (int i = 0; i < idx2.size(); ++ i){
        int j = i;
        deque <int> Q = {idx2[j]};
        while (j+1 < idx2.size() && (W(idx2[j]) == W(idx2[j+1]))){
            j += 1;
            Q.push_back(idx2[j]);
        }
        who[i] = Qs.size();
        Qs.push_back(Q);
        i = j;
    }

    if (idx2.size()){
        for (int i = 0, j = -1; i < idx1.size(); ++ i){
            while (j == -1 || j+1 < idx2.size() && W(idx1[i]) > W(idx2[j])){
                j += 1;
            }
            if (W(idx1[i]) == W(idx2[j])){
                assert(who[j] != -1);
                auto &Q = Qs[who[j]];
                int x = f[i];
                f[i] = Q.back();
                assert(W(x) == W(Q.back()));
                Q.pop_back();
                Q.push_front(x);
            }
        }
    }

    vector<array<int,2>> ans(n);
    auto H = [&](int i)->array<int,2>{
        return g[i][0] == 1 ? array<int,2>{g[i][1], h} : array<int,2>{w, g[i][1]};
    };
    for (int i = 0; i < idx2.size(); ++ i){
        int j = i-1;
        while (i > j || j+1 < idx2.size() && (W(idx2[j]) == W(idx2[j+1]))){
            j += 1;
            ans[Qs[who[i]][j-i]] = H(idx2[j]);
        }
        i = j;
    }
    for (int i = 0; i < idx1.size(); ++ i){
        ans[f[i]] = H(idx1[i]);
    }
    for (auto &it : ans){
        cout << it[0] << " " << it[1] << "\n";
    }
}
