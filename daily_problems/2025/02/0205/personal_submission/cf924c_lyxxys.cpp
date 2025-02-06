

void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    vector <int> stk;
    i64 res = 0;
    int dep = 0;
    for (int i = 0; i < n; ++ i){
        int x = A[i];
        if (x < dep){
            res += dep-x-1;
            stk.push_back(i);
        } else {
            int y = x-dep;
            bool jg = y;

            while (y--){
                auto j = stk.back();
                stk.pop_back();
                res += i-j;
            }

            // if (jg) stk.push_back(i);
            dep = x+1;
        }
    }

    cout << res << "\n";
}

