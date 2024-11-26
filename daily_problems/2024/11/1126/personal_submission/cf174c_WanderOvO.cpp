/*
考虑差分数组
1 1 -1 0 3 -3
先正负配对，多余的正的和最后面配
*/

int a[N], n, b[N];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += (b[i] > 0 ? b[i] : 0);
    }
    cout << res << "\n";
    vector<int> pos, neg;
    for (int i = 1; i <= n; i++) {
        if (b[i] > 0) {
            for (int j = 0; j < b[i]; j++) {
                pos.push_back(i);
            }
        } else if (b[i] < 0) {
            for (int j = 0; j < -b[i]; j++) {
                neg.push_back(i);
            }
        }
    }
    assert(pos.size() >= neg.size());
    for (int i = 0; i < neg.size(); i++) {
        cout << pos[i] << " " << neg[i] - 1 << "\n";
    }
    for (int i = neg.size(); i < pos.size(); i++) {
        cout << pos[i] << " " << n << "\n";
    }
}
