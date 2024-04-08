//link: https://codeforces.com/contest/226/submission/255559558

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin() + 1, arr.end(), greater<>());
    for (int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }
    debug(arr);
    map<int, int> ans;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        if (ans.count(x)) {
            cout << ans[x] << " ";
            continue;
        }
        int from = 1, len = 1, depth = 0;
        int anss = 0;
        while (from <= n) {
            int to = min(n, from + len - 1);
            int sum = arr[to] - arr[from - 1];
            anss += sum * depth;
            depth++;
            from = to + 1;
            len *= x;
        }
        ans[x] = anss;
        cout << anss << " ";
    }

}
