void solve(){
    map <string,int> mps = {{"S", 0}, {"M", 1}, {"L", 2}, {"XL", 3}, {"XXL", 4}, {"XXXL", 5}};
    string s_ans[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
    vector <int> cnts(6);
    for (auto &x : cnts){
        cin >> x;
    }
    
    int n;
    cin >> n;
    Graph G(n+8);
    const int sr = n+6, sk = n+7;
    G.set(sr, sk);

    for (int i = 0; i < n; ++ i){
        string s;
        cin >> s;
        int j = s.size();
        for (int u = 0; u < s.size(); ++ u){
            if (s[u] == ','){
                j = u;
            }
        }
        int to = mps[s.substr(0, j)];
        G.add(sr, i, 1);

        G.add(i, n+to, 1);
        if (j < s.size()){
            to = mps[s.substr(j+1)];
            G.add(i, n+to, 1);
        }
    }
    for (int i = 0; i < 6; ++ i){
        G.add(n+i, sk, cnts[i]);
    }

    // return;

    int res = G.dinic();
    if (res == n){
        cout << "YES\n";
        for (int i = 0; i < n; ++ i){
            for (auto &it : G.g[i]){
                int to = it.to, dis = it.dis;
                if (to >= n && to < n+6 && !dis){
                    cout << s_ans[to-n] << "\n";
                    break;
                }
            }
        }
    } else {
        cout << "NO\n";
    }
}
