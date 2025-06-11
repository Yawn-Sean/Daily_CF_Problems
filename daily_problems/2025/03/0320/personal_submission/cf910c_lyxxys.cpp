void solve(){
    int n;
    cin >> n;
    vector <int> pw10(8, 1);
    map <int, int> mps;
    set <int> st;
    for (int i = 1; i < 8; ++ i){
        pw10[i] = pw10[i-1] * 10;
    }

    for (int i = 0; i < n; ++ i){
        string s;
        cin >> s;
        int m = s.size();
        for (int j = m-1; j >= 0; -- j){
            mps[s[j]-'a'] += pw10[m-j-1];
        }
        st.insert(s[0]-'a');
    }
    vector<array<int,2>> curs;
    for (auto &[u, v] : mps){
        curs.push_back({v, u});
    }
    sort(curs.begin(), curs.end(), [&](auto &u, auto &v){
        return u[0] > v[0];
    });

    i64 res = 0;
    bool jug = 1;
    for (int i = 0, cnt = 0; i < curs.size(); ++ i){
        if (jug && !st.count(curs[i][1])){
            jug = 0;
            continue;
        }
        res += (++ cnt) * curs[i][0];
    }
    cout << res << "\n";
}
