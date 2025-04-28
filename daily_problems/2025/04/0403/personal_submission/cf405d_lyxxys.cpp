void solve(){
    const int N = 1e6, half = 5e5;

    int n;
    cin >> n;
    vector <int> ans, vis(N+1), A(n);
    for (auto &x : A){
        cin >> x;
        vis[x] = 1;
    }

    int cnt = 0;
    for (auto &x : A){
        int minor = N - x + 1;
        if (!vis[minor]) ans.push_back(minor);
        else cnt += 1;
    }

    assert(cnt%2 == 0);
    cnt /= 2;
    for (int i = 1; i <= half && cnt; ++ i){
        int minor = N - i + 1;
        if (!vis[i] && !vis[minor]){
            ans.push_back(i);
            ans.push_back(minor);
            cnt -= 1;
        }
    }

    cout << ans.size() << "\n";
    print(ans);
}
