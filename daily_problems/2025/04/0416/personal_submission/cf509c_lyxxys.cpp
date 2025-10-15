void solve(){
    int n, q;
    cin >> q;
    vector <int> cur(400);
    auto roll = [&](vector <int> &f, int pos)->void{
        for (int i = pos; i >= 0; -- i){
            if (n && f[i] != 9){
                f[i] += 1, n -= 1;
                break;
            } else {
                n += f[i];
                f[i] = 0;
            }
        }
    };

    while (q--){
        cin >> n;

        vector <int> f(400);
        bool jug = false;
        for (int i = 0; i < 400; ++ i){
            if (n >= cur[i]){
                n -= cur[i];
                f[i] = cur[i];
            } else {
                roll(f, i-1);
                jug = true;
                break;
            }
        }
        // jug = b_i < b_{i-1}，分别讨论小于、等于、大于三种情况
        if (!jug){
            if (n){
                f.back() += 1;
                n -= 1;
            } else {
                roll(f, 399);
            }
        }

        for (int j = 399; j >= 0; -- j){
            int v = min(n, 9-f[j]);
            f[j] += v;
            n -= v;
        }

        cur = f;
        // cout << jug << "\n";
        for (int i = 0, jug = 0; i < 400; ++ i){
            if (cur[i]) jug = 1;
            if (jug) cout << cur[i];
        }
        cout << "\n";
    }
}
