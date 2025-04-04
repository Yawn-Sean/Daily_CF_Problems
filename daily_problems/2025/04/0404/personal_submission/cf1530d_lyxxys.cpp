void solve(){
    int n;
    cin >> n;
    vector <int> A(n), cnts(n);
    for (int i = 0; i < n; ++ i){
        cin >> A[i];
        A[i] -= 1;
        cnts[A[i]] += 1;
    }

    set <int> tars;

    for (int i = 0; i < n; ++ i){
        if (!cnts[i]){
            tars.insert(i);
        }
    }

    int res = n - tars.size();
    for (int i = 0; i < n; ++ i){
        int x = A[i];
        if (cnts[x] > 1){
            int u = -1;
            for (auto &y : tars){
                if (y != i){
                    u = y;
                    break;
                }
            }
            if (u != -1){
                cnts[x] -= 1;
                A[i] = u;
                cnts[u] += 1;
                tars.erase(u);
            }
        }
    }

    cout << res << "\n";
    print(A, 1);
}
