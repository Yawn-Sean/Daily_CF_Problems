void solve(){
    int n;
    cin >> n;
    vector <int> A(n+1);
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
    }

    vector <int> f(n+1), prev(n+1, -1);
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < i; ++ j){
            int v = f[j] + (i-j)*(i-j);
            if (v > f[i]){
                f[i] = v;
                prev[i] = j;
            }
        }
        int v = f[i-1]+A[i];
        if (v > f[i]){
            f[i] = v;
            prev[i] = i-1;
        }
    }
    auto mex = [&](int l, int r)->int{
        set <int> st;
        for (int i = l; i <= r; ++ i) st.insert(A[i]);
        for (int i = 0; i <= n+1; ++ i){
            if (!st.count(i)) return i;
        }
        return -1;
    };

    vector<array<int,2>> ans;
    auto operate = [&](int l, int r)->int{
        ans.push_back({l, r});
        int v = mex(l, r);
        for (int i = l; i <= r; ++ i){
            A[i] = v;
        }
        return v;
    };
    auto set_zero = [&](int l, int r)->void{
        bool jg = 1;
        for (int i = l; i <= r; ++ i){
            if (A[i]) jg = 0;
        }
        if (jg) return;

        if (operate(l, r)){
            int _ = operate(l, r);
        }
    };
    auto mid_process = [&](auto &&self, int l, int r)->void{
        if (l == r){
            set_zero(l, r);
            return;
        }
        self(self, l, r-1);
        int _ = operate(l, r);
        self(self, l, r-1);
    };
    auto process = [&](int l, int r)->void{
        set_zero(l, r);
        mid_process(mid_process, l, r);
        int _ = operate(l, r);
    };

    int cur = n;
    while (cur > 0){
        int lst = prev[cur];
        if (lst < cur-1 || A[lst+1] <= 1){
            process(lst+1, cur);
        }
        cur = lst;
    }

    cout << f[n] << " " << ans.size() << "\n";
    for (auto &[x, y] : ans){
        cout << x << " " << y << "\n";
    }
}
