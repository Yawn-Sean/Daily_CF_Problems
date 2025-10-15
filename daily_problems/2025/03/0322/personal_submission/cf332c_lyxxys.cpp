void solve(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector <int> A(n), B(n), used(n), idx(n), ans;
    for (int i = 0; i < n; ++ i){
        cin >> A[i] >> B[i];
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int &i, int &j){
        return B[i] == B[j] ? A[i] < A[j] : B[i] > B[j];
    });
    

    map <int,vector<int>,greater<int>> mps;
    for (int i = 0; i < n-(k1-k2); ++ i){
        int id = idx[i];
        mps[A[id]].push_back(id);
    }
    int chose = 0;
    for (auto &[v, vec] : mps){
        for (auto &id : vec){
            if (chose < k2){
                chose += 1;
                used[id] = 1;
                ans.push_back(id+1);
            }
        }
    }
    int start = n;
    for (int i = n-1; i >= 0; -- i){
        if (used[idx[i]]){
            start = i+1;
            break;
        }
    }

    mps.clear();
    for (int i = start; i < n; ++ i){
        int id = idx[i];
        mps[B[id]].push_back(id);
    }
    chose = 0;
    for (auto &[v, vec] : mps){
        for (auto &id : vec){
            if (chose < k1-k2){
                chose += 1;
                used[id] = 1;
                ans.push_back(id+1);
            }
        }
    }

    assert(ans.size() == k1);
    print(ans);
}
