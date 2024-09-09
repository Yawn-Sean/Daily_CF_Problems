// 不开o2, 3921ms勾过
void solve(){
    int n;
    cin >> n;
    vector <string> s(n);
    map <string, int> mps;
    for (auto &it : s){
        cin >> it;
        assert(it.size() == 9);
        set <string> st;
        for (int i = 0; i < 9; ++ i){
            for (int j = 1; j <= 9-i; ++ j){
                st.insert(it.substr(i, j));
            }
        }
        for (auto &chs : st){
            ++ mps[chs];
        }
    }

    for (auto &it : s){
        bool jg = 1;
        for (int len = 1; len <= 9 && jg; ++ len){
            for (int i = 0; i+len-1 < 9 && jg; ++ i){
                if (mps[it.substr(i, len)] == 1){
                    cout << it.substr(i, len) << "\n";
                    jg = 0;
                }
            }
        }
        assert(jg == 0);
    }
}
