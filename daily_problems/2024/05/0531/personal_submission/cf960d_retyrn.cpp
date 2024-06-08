using pil = pair<int, ll>;
int n;

void solve() {
    // 最多60层
    cin >> n;
    const int m = 60;
    vector<ll> d(m + 1, 0); // 偏移量
    vector<ll> len(m + 1, 1); // 每一层的节点数
    
    for (int i = 2; i <= m; i ++) {
        len[i] = (len[i - 1] << 1);
    }
    
    auto cal = [&](ll val) {
        int layer = 1;
        while (val > len[layer]) {
            val -= len[layer];
            layer ++;
        }
        return mpr(layer, val - 1);
    };
    
    for (int i = 0; i < n; i ++) {
        int op;
        cin >> op;
        if (op == 1) {
            ll val, x;
            cin >> val >> x;
            auto [layer, pos] = cal(val);
            d[layer] = (d[layer] + x % len[layer] + len[layer]) % len[layer];
        }
        else if (op == 2) {
            ll val, x;
            cin >> val >> x;
            auto [layer, pos] = cal(val);
            for (int i = layer; i <= m; i ++) {
                x %= len[i];
                d[i] = (d[i] + x + len[i]) % len[i];
                x *= 2;
            }
        }
        else {
            ll val;
            cin >> val;
            pil t = cal(val);
            int layer = t.fi;
            ll pos = t.se;
            pos = (pos + d[layer]) % len[layer];
            vector<ll> res = {val};
            
            while (layer > 1) {
                layer --;
                pos /= 2;
                val = (1ll << layer) - len[layer] + (pos + len[layer] - d[layer]) % len[layer];
                res.push_back(val);
            }
            cout << res << endl;
        }
    }
}