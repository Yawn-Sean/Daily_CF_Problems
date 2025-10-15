void solve(){
    int n, k, p;
    cin >> n >> k >> p;
    vector <int> A(n), odds, evens;
    vector<vector<int>> ans;

    int sz1 = p, sz2 = k-p;
    for (auto &x : A){
        cin >> x;
        if (x%2) odds.push_back(x);
        else evens.push_back(x);
    }

    int m = odds.size();
    if (m < sz2 || (m-sz2)%2 || n-m + (m-sz2)/2 < sz1){
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < sz2; ++ i){
        ans.push_back({odds.back()});
        odds.pop_back();
    }
    for (int i = 0; i < sz1; ++ i){
        if (evens.size()){
            ans.push_back({evens.back()});
            evens.pop_back();
        } else {
            ans.push_back({odds[odds.size()-1], odds[odds.size()-2]});
            odds.pop_back(), odds.pop_back();
        }
    }

    ans[0].insert(ans[0].end(), odds.begin(), odds.end());
    ans[0].insert(ans[0].end(), evens.begin(), evens.end());

    cout << "YES\n";
    for (auto &vec : ans){
        cout << vec.size();
        for (auto &x : vec){
            cout << " " << x;
        }
        cout << "\n";
    }
}
