void solve(){
    string bufs, chs;
    vector <string> s;
    vector <int> w;

    cin >> bufs;
    for (int i = 0, x = 0, jug = 1; i < bufs.size(); ++ i){
        if (i == bufs.size()-1){
            s.push_back(chs), w.push_back(x);
        } else if (bufs[i] == ','){
            jug = !jug;
            if (jug){
                s.push_back(chs), w.push_back(x);
                chs.clear(), x = 0;
            }
        } else if (jug){
            chs += bufs[i];
        } else {
            x = x*10 + (bufs[i]-'0');
        }
    }

    int n = w.size();
    vector<vector<string>> store(n);
    auto dfs = [&](auto &&self, int u, int dep)->int{
        store[dep].push_back(s[u]);
        int ret = 1;

        for (int i = 0; i < w[u]; ++ i){
            ret += self(self, u+ret, dep+1);
        }

        return ret;
    };
    int i = 0;
    while (i < n){
        int cnt = dfs(dfs, i, 0);
        i += cnt;
    }

    int tot;
    for (int i = n-1; i >= 0; -- i){
        if (store[i].size() > 0){
            tot = i;
            break;
        }
    }
    cout << tot+1 << "\n";
    for (int i = 0; i <= tot; ++ i){
        for (int j = 0; j < store[i].size(); ++ j){
            if (j) cout << " ";
            cout << store[i][j];
        }
        cout << "\n";
    }
}
