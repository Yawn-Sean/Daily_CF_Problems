void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> stk;
    for (int i = 0; i < n; ++ i){
        int x;
        f64 y;
        cin >> x >> y;
        auto it = upper_bound(stk.begin(), stk.end(), x);
        if (it == stk.end()) stk.push_back(x);
        else *it = x;
    }

    cout << n-stk.size() << "\n";
}
