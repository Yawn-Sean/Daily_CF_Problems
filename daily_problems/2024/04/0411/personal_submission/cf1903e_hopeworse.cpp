// link : https://codeforces.com/contest/1903/submission/235311984
void solve() {
    int n, x, y;
    set<int> j;
    set<int> o;
    cin >> n >> x >> y;
    int x1, x2;
    for (int i = 1; i <= n; i++) {
        cin >> x1 >> x2;
        if ((x + y + x1 + x2) & 1) j.insert(i);
        else o.insert(i);
    }
    if (j.size() <= o.size()) {
        cout << "First" << endl;
        for (int i = 0; i < (n) / 2; i++) {
            if (!j.empty()) {
                cout << (*j.begin()) << endl;
                j.erase(j.begin());
            } else {
                cout << (*o.begin()) << endl;
                o.erase(o.begin());
            }
            int xa;
            cin >> xa;
            j.erase(xa);
            o.erase(xa);
        }
        if (!j.empty())cout << *j.begin() << endl;
        if (!o.empty())cout << *o.begin() << endl;
    } else {
        cout << "Second" << endl;
        for (int i = 0; i < (n) / 2; i++) {
            int xa;
            cin >> xa;
            j.erase(xa);
            o.erase(xa);
            if (!o.empty()) {
                cout << (*o.begin()) << endl;
                o.erase(o.begin());
            } else {
                cout << (*j.begin()) << endl;
                j.erase(j.begin());
            }
        }
        if (!j.empty())cin >> n;
        if (!o.empty())cin >> n;
 
    }
}
