int n;
int ask(int x) {
    cout << "? " << x << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}
void answer(int x) {
    cout << "! " << x << endl;
    cout.flush();
}
void solve() {
    cin >> n;
    if (n % 4) {
        answer(-1);
        return;
    }
    // 1 - n/2+1
    vector<int> f(n / 2 + 2);
    f[1] = ask(1) - ask(n / 2 + 1);
    f[n / 2 + 1] = -f[1];
    if (f[1] == 0) {
        answer(1);
        return;
    }
    int l = 2, r = n / 2;
    while (l < r) {
        auto mid = (l + r) >> 1;
        f[mid] = ask(mid) - ask(mid + n / 2);
        if (f[mid] == 0) {
            answer(mid);
            return;
        }
        if ((f[mid] > 0) == (f[1] > 0)) l = mid + 1;
        else r = mid;
    }
    f[l] = ask(l) - ask(l + n / 2);
    answer(f[l] == 0 ? l : -1);
}