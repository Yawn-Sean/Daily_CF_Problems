
void solve(){
    auto query = [&](string s)->pair<int,int>{
        cout << s << "\n" << flush;
        int x, y;
        cin >> x >> y;
        return {x, y};
    };

    vector <int> ans;
    for (int i = 0, x, y; i < 10; ++ i){
        string s(4, char(i+'0'));
        tie(x, y) = query(s);
        if (x == 1 && y == 0) ans.push_back(i);
        if (ans.size() == 4) break;
    }

    assert(ans.size() == 4);
    do {
        string s;
        int x, y;
        for (auto &u : ans){
            s += char(u+'0');
        }
        tie(x, y) = query(s);
        if (x == 4 && y == 0) break;
    } while (next_permutation(ans.begin(), ans.end()));
}
