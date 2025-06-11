void solve(){
    int n, m, p;
    cin >> n >> m >> p;
    vector <int> A(n), B(m), w;
    for (auto &x : A){
        cin >> x;
        w.push_back(x);
    }
    for (auto &x : B){
        cin >> x;
        w.push_back(x);
    }
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    const int tot = w.size();
    vector <int> tars(tot), cnts(tot);

    for (int i = 0; i < n; ++ i){
        A[i] = lower_bound(w.begin(), w.end(), A[i]) - w.begin();
    }
    for (int i = 0; i < m; ++ i){
        B[i] = lower_bound(w.begin(), w.end(), B[i]) - w.begin();
        tars[B[i]] += 1;
    }

    vector <int> ans;
    int march = 0;
    for (int i = 0; i < p; ++ i){
        int j = i-p, l = 0;
        
        while (j+p < n){
            while (l+1 <= m && j+p < n){
                j += p;
                cnts[A[j]] += 1;
                march += cnts[A[j]] <= tars[A[j]];

                l += 1;
            }

            if (l != m) break;

            int lst = j - (m-1)*p;
            if (march == m) ans.push_back(lst);

            l -= 1;
            march -= cnts[A[lst]] <= tars[A[lst]];
            cnts[A[lst]] -= 1;
        }

        while (l){
            cnts[A[j]] -= 1;
            l -= 1;
            j -= p;
        }
        march = 0;
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    print(ans, 1);
}
