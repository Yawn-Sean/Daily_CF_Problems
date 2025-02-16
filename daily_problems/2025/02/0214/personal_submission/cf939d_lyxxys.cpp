void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<array<int,2>> ans;
    vector <int> p(26);
    iota(p.begin(), p.end(), 0);

    auto find = [&](int x)->int{
        int y = x;
        while (p[y] != y){
            y = p[y];
        }
        while (p[x] != x){
            int &j = p[x];
            x = p[x], j = y;
        }
        return y;
    };
    auto merge = [&](int x, int y)->void{
        x = find(x), y = find(y);
        if (x == y) return;
        p[y] = x;
    };

    for (int i = 0; i < n; ++ i){
        int x = s1[i]-'a', y = s2[i]-'a';
        merge(x, y);
    }

    vector<vector<int>> chuks(26);
    for (int i = 0; i < 26; ++ i){
        chuks[find(i)].push_back(i);
    }
    for (int i = 0; i < 26; ++ i){
        if (chuks[i].size() > 1){
            auto &vec = chuks[i];
            for (int j = 1; j < vec.size(); ++ j){
                ans.push_back({vec[j-1], vec[j]});
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &[u, v] : ans){
        cout << char(u+'a') << " " << char(v+'a') << "\n";
    }
}
