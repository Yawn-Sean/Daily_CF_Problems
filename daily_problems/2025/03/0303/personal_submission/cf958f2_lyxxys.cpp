void solve(){
    int n, m, all = 0;
    cin >> n >> m;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
        x -= 1;
    }
    int k = 0;
    vector <int> need(m);
    for (auto &x : need){
        cin >> x;
        if (x) k += 1;
        all += x;
    }

    int cnt = 0, mi = inf_int;
    vector <int> cnts(m);
    for (int i = 0, j = -1; i < n; ++ i){
        while (j+1 < n && cnt < k){
            ++ j;
            cnts[A[j]] += 1;
            if (cnts[A[j]] == need[A[j]]) cnt += 1;
        }
        if (cnt == k && j-i+1-all < mi){
            mi = j-i+1-all;
        }
        if (cnts[A[i]] == need[A[i]]) cnt -= 1;
        cnts[A[i]] -= 1;
    }

    if (mi == inf_int) cout << -1 << "\n";
    else cout << mi << "\n";
}

