// https://codeforces.com/contest/1031/submission/257427981
int n, t, m;
LL a, b;
void show(vector<int> &v) {
    cout << v.size() << '\n';
    for (auto &a : v) cout << a << " ";
    if (!v.empty()) cout << '\n';
}
void sol()
{
    cin >> a >> b;
    LL sum = 0, i;
    for (i = 1; ; i++) {
        sum += i;
        if (sum > a + b) break;
    }
    i--; // sigma(1, i) <= a + b
    set<int> se;
    for (int j = 1; j <= i; j++) se.insert(j);

    vector<int> va;
    while (a) {
        auto it = se.upper_bound(a);
        if (it == se.begin()) break;
        --it;
        a -= *it;
        va.push_back(*it);
        se.erase(it);
    }
    vector<int> vb(se.begin(), se.end());
    show(va), show(vb);
}
