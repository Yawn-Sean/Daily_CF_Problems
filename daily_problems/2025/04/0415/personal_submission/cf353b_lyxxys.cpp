void solve(){
    int n;
    cin >> n;
    set <int> st1, st2;
    vector <int> ans(2*n), vis(100);
    vector<vector<int>> whos(100);

    for (int i = 0, x; i < 2*n; ++ i){
        cin >> x;
        whos[x].push_back(i);
    }
    for (int i = 10; i <= 99; ++ i){
        auto &vec = whos[i];
        while (vec.size() >= 2){
            vis[i] = 1;

            int u = vec.back();
            vec.pop_back();
            int v = vec.back();
            vec.pop_back();

            ans[u] = 1, ans[v] = 2;
            st1.insert(i), st2.insert(i);
        }
    }

    bool flg = 1;
    for (int i = 10; i <= 99; ++ i){
        auto &vec = whos[i];
        if (vec.size() && !vis[i]){
            int u = vec.back();
            vec.pop_back();
            if (flg){
                ans[u] = 1;
                st1.insert(i);
            } else {
                ans[u] = 2;
                st2.insert(i);
            }
            flg = !flg;
        }
    }
    for (int i = 10; i <= 99; ++ i){
        auto &vec = whos[i];
        if (vec.size() && vis[i]){
            int u = vec.back();
            vec.pop_back();
            if (flg){
                ans[u] = 1;
                st1.insert(i);
            } else {
                ans[u] = 2;
                st2.insert(i);
            }
            flg = !flg;
        }
    }

    cout << st1.size()*st2.size() << "\n";
    int c1 = 0, c2 = 0;
    for (int i = 0; i < 2*n; ++ i){
        if (ans[i] == 1) c1 += 1;
        else c2 += 1;
    }
    assert(c1 == c2);
    print(ans);
}
