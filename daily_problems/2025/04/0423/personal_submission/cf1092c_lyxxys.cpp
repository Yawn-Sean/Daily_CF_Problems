void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector <string> strs;
    for (int i = 0; i < 2*n-2; ++ i){
        string s;
        cin >> s;
        g[(int)s.size()].push_back(i);
        strs.push_back(s);
    }

    vector <int> ans(2*n-2);
    auto march_pre = [&](string s, string t)->bool{
        for (int i = 0; i < min(s.size(), t.size()); ++ i){
            if (s[i] != t[i]){
                return false;
            }
        }
        return true;
    };
    auto march_suf = [&](string s, string t)->bool{
        int j1 = s.size()-1, j2 = t.size()-1;
        while (j1 >= 0 && j2 >= 0){
            if (s[j1] != t[j2]){
                return false;
            }
            j1 -= 1, j2 -= 1;
        }
        return true;
    };
    auto chk = [&](string s)->bool{
        fill(ans.begin(), ans.end(), 0);

        for (int i = 1; i < n; ++ i){
            int c1 = 0, c2 = 0;
            for (auto &id : g[i]){
                if (c1 == 0 && march_pre(s, strs[id])){
                    ans[id] = 1;
                    c1 += 1;
                } else if (march_suf(s, strs[id])){
                    ans[id] = 2;
                    c2 += 1;
                }
            }
            if (c1 != 1 || c2 != 1) return false;
        }

        return true;
    };
    string s1 = strs[g[n-1][0]], s2 = strs[g[n-1][1]];

    auto fout = [&]()->void{
        for (auto &x : ans){
            if (x == 1) cout << "P";
            else cout << "S";
        }
        cout << "\n";
    };


    if (chk(s1+s2.back())){
        fout();
        return;
    }
    if (chk(s2+s1.back())){
        fout();
        return;
    }
}
