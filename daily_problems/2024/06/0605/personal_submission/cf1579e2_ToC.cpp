// https://codeforces.com/contest/1579/submission/264909026
void sol()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> back(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    int siz = arr.size();
    Fenwick fen(siz);
    LL res = 0;
    for (int i = 0; i < n; i++) {
        int cur = back[i];
        int less = lower_bound(arr.begin(), arr.end(), cur) - arr.begin();
        int more = upper_bound(arr.begin(), arr.end(), cur) - arr.begin();
        LL delta = min(fen.query(siz) - fen.query(more), fen.query(less));
        res += delta;
        fen.add(1, less + 1);
    }
    cout << res << '\n';
}
