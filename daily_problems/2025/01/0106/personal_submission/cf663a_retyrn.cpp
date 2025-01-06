int n;
string s;

vector<string> split(const string &s, char delim) {
    vector<string> ret;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        ret.push_back(item);
    }
    return ret;
}

void solve() {
    getline(cin, s);
    vector<string> v = split(s, ' ');
    n = stoi(v.back());
    
    int pos = 1, neg = 0;
    
    for (const auto& ss : v) {
        if (ss[0] == '+') pos ++;
        else if (ss[0] == '-') neg ++;
    }
    
    int mx = pos * n - neg;
    int mn = pos * 1 - neg * n;
    
    if (mn > n or mx < n) {
        cout << "Impossible" << endl;
        return;
    }
    
    cout << "Possible" << endl;
    
    vector<int> v_pos;
    vector<int> v_neg;
    
    // dbg(pos, neg, n);
    
    if (pos >= neg) {
        int sum1 = max(n + neg, pos), sum2 = sum1;
        for (int i = 0; i < neg; i ++) {
            int t = (sum1 - n) / (neg - i) + ((sum1 - n) % (neg - i) > 0);
            v_neg.push_back(t);
            sum1 -= t;
        }
        for (int i = 0; i < pos; i ++) {
            int t = sum2 / (pos - i) + (sum2 % (pos - i) > 0);
            v_pos.push_back(t);
            sum2 -= t;
        }
    }
    else {
        int sum = n * (pos - 1);
        while (pos --) {
            v_pos.push_back(n);
        }
        for (int i = 0; i < neg; i ++) {
            int t = sum / (neg - i) + (sum % (neg - i) > 0);
            v_neg.push_back(t);
            sum -= t;
        }
    }
    
    // out
    
    cout << v_pos.back();
    v_pos.pop_back();
    
    for (const auto &ss : v) {
        if (ss == "+") {
            cout << " + ";
            cout << v_pos.back();
            v_pos.pop_back();
        }
        if (ss == "-") {
            cout << " - ";
            cout << v_neg.back();
            v_neg.pop_back();
        }
        if (ss == "=") {
            cout << " = ";
        }
    }
    
    cout << n << endl;
    
}