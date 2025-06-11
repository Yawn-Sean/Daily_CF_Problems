// https://codeforces.com/contest/962/submission/262693787
int n, m;
LL a[MAXN];
priority_queue<LL, vector<LL>, greater<LL>> mh;
unordered_map<int, int> v2c;
map<LL, set<LL>> v2i;
int del[MAXN];
void sol()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v2c[a[i]]++;
        v2i[a[i]].insert(i);
    }
    for (auto &[v, c] : v2c) {
        if (c > 1) {
            mh.push(v);
        }
    }
    int sub = 0;
    while (!mh.empty()) {
        auto v = mh.top();
        mh.pop();
        int old = v2i[2 * v].size();
        auto &vec = v2i[v];
        auto l = vec.begin(), r = next(l);
        while (vec.end() != r && vec.end() != l) {
            del[*l] = 1;
            sub++;
            a[*r] = 2 * v;
            v2i[2 * v].insert(*r);
            l = next(next(l));
            r = next(next(r));
        } 
        if (old <= 1 && v2i[2 * v].size() > 1) {
            mh.push(2 * v);
        }
    }
    cout << n - sub << '\n';
    for (int i = 0; i < n; i++) {
        if (!del[i])
            cout << a[i] << " ";
    }
    cout << '\n'; 
}
