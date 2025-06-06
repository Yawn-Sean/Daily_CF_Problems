void solve(){
    int n, m;
    cin >> n >> m;
    int tar = 1;

    vector <int> stk = {n+1}, ans;
    for (int i = 1,x; i <= m; ++ i){
        cin >> x;
        ans.push_back(x);
        stk.push_back(x);
        while (!stk.empty() && tar == stk.back()){
            tar += 1;
            stk.pop_back();
        }
    }

    stk.push_back(tar-1);
    for (int i = stk.size()-1; i > 0; -- i){
        int u = stk[i-1], v = stk[i];
        if (u < v) return void(cout << -1 << "\n");
        for (int j = u-1; j > v; -- j){
            ans.push_back(j);
        }
    }

    print(ans);
}
