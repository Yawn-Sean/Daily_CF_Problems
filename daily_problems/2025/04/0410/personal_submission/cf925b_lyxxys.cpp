void solve(){
    int n;
    i64 x1, x2;
    cin >> n >> x1 >> x2;
    vector <i64> A(n), idx(n);
    for (auto &x : A){
        cin >> x;
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
        return A[u] < A[v];
    });

    auto legal = [&](i64 k1, i64 k2, bool revse)->bool{
        vector <int> chose(n, -1);
        for (int i = n-1; i >= 0; -- i){
            i64 x = A[idx[i]];
            if (i < n-1 && chose[i+1] != -1){
                chose[i] = chose[i+1];
            } else if (x*(n-i) >= k2){
                chose[i] = i;
            }
        }

        for (int i = 0; i < n; ++ i){
            i64 x = A[idx[i]];
            i64 L = (k1+x-1) / x;
            if (i+L < n && chose[i+L] != -1){
                vector <int> ans1, ans2;
                for (int j = i; j < i+L; ++ j){
                    ans1.push_back(idx[j]);
                }
                for (int j = chose[i+L]; j < n; ++ j){
                    ans2.push_back(idx[j]);
                }
                cout << "Yes\n";
                if (revse) swap(ans1, ans2);
                cout << ans1.size() << " " << ans2.size() << "\n";
                print(ans1, 1), print(ans2, 1);
                return true;
            }
        }

        return false;
    };

    if (legal(x1, x2, 0)) return;
    if (legal(x2, x1, 1)) return;
    cout << "No\n";
}
