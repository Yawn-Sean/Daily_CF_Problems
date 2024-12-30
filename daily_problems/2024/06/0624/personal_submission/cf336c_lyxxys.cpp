
void solve(){   
    int n;
    cin >> n;
    vector <int> a(n+1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];

    for (int v = 30; v >= 0; -- v){
        vector <int> ans;
        int x = (1<<v)-1;
        for (int j = 1; j <= n; ++ j){
            if (a[j]>>v&1){
                ans.push_back(a[j]), x &= a[j];
            }
        }
        if (x%(1<<v)==0){
            cout << ans.size() << "\n";
            for (auto &y : ans) cout << y << " ";
            cout << "\n";
            return;
        }
    }
}
