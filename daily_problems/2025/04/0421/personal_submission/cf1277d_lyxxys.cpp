void solve(){
    auto fout = [&]()->void{
        cout << -1 << "\n";
    };

    int n;
    cin >> n;
    vector<set<string>> st(4);
    vector<string> chs;
    vector<vector<int>> A(4);
    // 该字符串的分组
    auto ID = [&](string s)->int{
        int id = 0;
        if (s[0] == '1') id += 2;
        if (s.back() == '1') id += 1;
        return id;
    };

    for (int i = 0; i < n; ++ i){
        string s;
        cin >> s;
        int id = ID(s);
        st[id].insert(s);
        A[id].push_back(i);
        chs.push_back(s);
    }

    if (st[0].size() && st[3].size() && st[1].empty() && st[2].empty()) return fout();

    int chose = st[1].size() > st[2].size() ? 1 : 2;
    vector <int> ans;
    int c1 = max((int)st[1].size(), (int)st[2].size());
    int c2 = min((int)st[1].size(), (int)st[2].size());

    // 对于更多的 01组 或者 10组，总是可以消减就消减，直到两者之差小于等于1
    // 可以消减就消减的情况最优，如果可以消减却不消减，可以找到另一个或者甚至找不到，但都不会优于该方案
    for (auto &i : A[chose]){
        if (c1-c2 <= 1) break;
        string cur = chs[i];
        reverse(cur.begin(), cur.end());
        
        auto k = cur;
        if (!st[3-chose].count(k)){
            st[3-chose].insert(k);
            c1 -= 1, c2 += 1;
            ans.push_back(i);
        }
    }

    if (c1-c2 <= 1){
        cout << ans.size() << "\n";
        print(ans, 1);
    } else {
        cout << -1 << "\n";
    }
}
