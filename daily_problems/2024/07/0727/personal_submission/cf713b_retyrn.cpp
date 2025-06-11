using ai4 = array<int, 4>;
int n;

int ask(int x1, int x2, int y1, int y2) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

ai4 cal(int x1, int x2, int y1, int y2) {
    int l = x1, r = x2;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (ask(x1, mid, y1, y2) >= 1) r = mid;
        else l = mid + 1;
    }
    int X2 = l;
    l = x1, r = X2;
    while (l < r) {
        auto mid = (l + r + 1) >> 1;
        if (ask(mid, X2, y1, y2) >= 1) l = mid;
        else r = mid - 1;
    }
    int X1 = l;
    
    l = y1, r = y2;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (ask(X1, X2, y1, mid) >= 1) r = mid;
        else l = mid + 1;
    }
    int Y2 = l;
    
    l = y1, r = Y2;
    while (l < r) {
        auto mid = (l + r + 1) >> 1;
        if (ask(X1, X2, mid, Y2) >= 1) l = mid;
        else r = mid - 1;
    }
    int Y1 = l;
    
    return {X1, Y1, X2, Y2};
}

void answer(ai4 a, ai4 b) {
    cout << '!';
    for (auto x : a) {
        cout << ' ' << x;
    }
    for (auto x : b) {
        cout << ' ' << x;
    }
    cout << endl;
    cout.flush();
}

void solve() {
    cin >> n;
    // 先找到分界线
    int l = 1, r = n;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (ask(1, mid, 1, n) > 0) r = mid;
        else l = mid + 1;
    }
    
    if (l + 1 <= n and ask(1, l, 1, n) == 1 and ask(l + 1, n, 1, n) == 1) {
        auto A = cal(1, l, 1, n);
        auto B = cal(l + 1, n, 1, n);
        answer(A, B);
        return;
    }
    
    l = 1, r = n;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (ask(1, n, 1, mid) > 0) r = mid;
        else l = mid + 1;
    }
    auto A = cal(1, n, 1, l);
    auto B = cal(1, n, l + 1, n);
    answer(A, B);
}