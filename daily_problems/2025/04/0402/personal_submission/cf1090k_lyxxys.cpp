void solve(){

    const int seed = 131;

    int n;
    cin >> n;
    map <array<u64,2>, vector<int>> mps;
    for (int i = 0; i < n; ++ i){
        string s, t;
        cin >> s >> t;
        int msk = 0;
        for (int j = 0; j < t.size(); ++ j){
            msk |= 1 << (t[j]-'a');
        }
        while (!s.empty()  && ((msk|(1<<(s.back()-'a'))) == msk)) s.pop_back();
        
        u64 cur = 0;
        for (int j = 0; j < s.size(); ++ j){
            cur = cur*seed + (s[j]-'a'+1);
        }
        mps[{cur, (u64)msk}].push_back(i+1);
    }

    cout << mps.size() << "\n";
    for (auto &U : mps){
        auto &vec = U.second;
        cout << vec.size();
        for (auto &id : vec){
            cout << " " << id;
        }
        cout << "\n";
    }

}
