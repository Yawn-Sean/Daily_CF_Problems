void solve(){
    i64 n, k, all = 0;
    cin >> n >> k;
    vector <i64> A(n);
    for (auto &x : A){
        cin >> x;
        all += x;
    }

    if (k > all) return void(cout << -1 << "\n");

    auto chk = [&](i64 mid)->bool{
        i64 res = 0;
        for (auto &x : A){
            res += min(x, mid);
        }
        return res >= k;
    };
    i64 lo = 1, hi = k;
    while (lo < hi){
        i64 mid = (lo + hi) >> 1;
        if (chk(mid)) hi = mid;
        else lo = mid+1;
    }

    i64 cur = 0;
    for (int i = 0; i < n; ++ i){
        i64 x = min(A[i], lo-1);
        cur += x;
        A[i] -= x;
    }

    int mark = -1;
    if (k > 0){
        for (int i = 0; i < n; ++ i){
            if (A[i]){
                A[i] -= 1;
                cur += 1;
            }
            if (cur == k){
                mark = i;
                break;
            }
        }
    }


    vector <int> ans;
    for (int i = mark+1; i < n; ++ i){
        if (A[i]){
            ans.push_back(i+1);
        }
    }
    for (int i = 0; i <= mark; ++ i){
        if (A[i]){
            ans.push_back(i+1);
        }
    }

    print(ans);
}
