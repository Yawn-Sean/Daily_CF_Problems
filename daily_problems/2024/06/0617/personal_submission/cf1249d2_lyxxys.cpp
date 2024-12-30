void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> lseg(2e5+1), rseg(2e5+1);
    vector <int> rto(1);
    for (int i = 1; i <= n; ++ i){
        int l, r;
        cin >> l >> r;
        rto.push_back(r);
        lseg[l].push_back(i), rseg[r].push_back(i);
    }

    set <pair<int,int>> st;
    vector <int> ans;
    // 用扫描线思想去维护当前的整个区间
    for (int i = 0; i <= 2e5; ++ i){
        for (auto &x : lseg[i]) st.insert({rto[x], x});
        while (st.size() > k){
            auto rbing = st.rbegin();
            ans.push_back(rbing->second);
            st.erase(*rbing);
        }
        // 删除将要过了右端点之后的区间
        for (auto &x : rseg[i]){
            set<pair<int,int>>::iterator it;
            if ((it=st.find({i, x})) != st.end())
                st.erase(it);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++ i)
        cout << ans[i] << "\n "[i < ans.size()-1];
}
