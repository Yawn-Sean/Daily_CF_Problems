int k;
vector<int> a;

bool check(int ans) {
    int len = 0, cnt = 1;
    for (int i = 0; i < a.size(); i++) {
        if (len + a[i] <= ans) {
            len += a[i];
        } else {
            if (a[i] > ans) {
                return false;
            }
            cnt++;
            len = a[i];
        }
    }
    return cnt <= k;
}

void meibao() {
    cin >> k;
    string s, t;
    while (cin >> t) {
        s += t;
        s += " ";
    } 
    int n = s.size() - 1;
    int len = 0;
    for (int i = 0; i < n; i++) {
        len++;
        if (s[i] == ' ' || s[i] == '-') {
            a.push_back(len);
            len = 0;
        }
    }
    a.push_back(len);
    int l = 0, r = n, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << l << "\n";
    } else {
        cout << r << "\n";
    }
}   
