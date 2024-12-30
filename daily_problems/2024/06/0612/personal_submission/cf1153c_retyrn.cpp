int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    if (n & 1) {
        cout << ":(" << endl;
        return;
    }
    deque<int> q;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '?') {
            q.push_back(i);
        }
        else if (s[i] == '(') sum += 1;
        else sum -= 1;
    }
    // 尽可能先填(
    while (sum > 0 and !em(q)) {
        auto t = q.back();
        q.pop_back();
        s[t] = ')';
        sum -= 1;
    }
    
    while (sum < 0 and !em(q)) {
        auto t = q.front();
        q.pop_front();
        s[t] = '(';
        sum += 1;
    }
    
    if (sum != 0 or sz(q) % 2 == 1) {
        cout << ":(" << endl;
        return;
    }
    
    while (sz(q)) {
        auto t = q.front();
        q.pop_front();
        s[t] = '(';
        t = q.back();
        q.pop_back();
        s[t] = ')';
    }
    
    // check
    sum = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') sum ++;
        else sum --;
        if (sum < 0 or (sum == 0 and i < n - 1)) {
            cout << ":(" << endl;
            return;
        }
    }
    cout << (sum == 0 ? s : ":(") << endl;
}