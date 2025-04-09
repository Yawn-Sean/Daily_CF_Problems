void solve(){
    int n;
    cin >> n;
    map <char,int> mps;
    mps['R'] = 0;
    mps['G'] = 1;
    mps['B'] = 2;
    mps['Y'] = 3;
    mps['W'] = 4;

    set <array<char,2>> st;
    for (int i = 0; i < n; ++ i){
        char ch1, ch2;
        cin >> ch1 >> ch2;
        st.insert({ch1, ch2});
    }

    auto w = [&](int x)->int{
        if (x == 0) return 0;
        else return __builtin_popcount(x);
    };
    int res = inf_int;
    for (int msk1 = 0; msk1 < 32; ++ msk1){
        for (int msk2 = 0; msk2 < 32; ++ msk2){
            set <int> vis;
            for (auto &it : st){
                int cur = 0;
                char ch1 = it[0], ch2 = it[1];
                int d1 = mps[ch1], d2 = it[1]-'1';
                if (msk1>>d1 & 1) cur += (d1+1) * 6;
                if (msk2>>d2 & 1) cur += d2+1;
                vis.insert(cur);
            }
            if (vis.size() == st.size()) fmin(res, w(msk1)+w(msk2));
        }
    }

    cout << res << "\n";
}
