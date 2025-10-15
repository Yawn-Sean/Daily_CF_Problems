void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> A(n);
    vector<vector<int>> locs, pos(m);
    for (int i = 0; i < n; ++ i){
        cin >> A[i];
        A[i] -= 1;
        pos[A[i]].push_back(i);
    }
    for (auto &vec : pos){
        if (!vec.empty()){
            locs.push_back(vec);
        }
    }

    int res = 0;
    for (auto &vec : locs){
        int len = vec.size();
        // using two-pointer to calutate how long with maximum impurity.
        for (int i = 0, j = -1, cur = 0; i < len; ++ i){
            if (j < i){
                j = i, cur = 0;
            }
            while (j+1 < len && cur+vec[j+1]-vec[j]-1 <= k){
                cur += vec[j+1]-vec[j]-1;
                j += 1;
            }
            fmax(res, j-i+1);
            if (i < j){
                cur -= vec[i+1]-vec[i]-1;
            }
        }
    }
    cout << res << "\n";
}
