
void solve() {
    string str;
    int n = read(), t = read();
    cin >> str;
    int loc = str.find('.');
    if (loc == string::npos) {
        cout << str << '\n';
        return ;
    }
    int pos = loc + 1;
    while (pos < str.size() && str[pos] < '5') {
        pos++;
    }
    if (pos == str.size()) {
        cout << str << '\n';
        return ;
    }
    while (t-- && pos > loc) {
        if (str[pos] >= '5') {
            str = str.substr(0, pos);
            while (--pos >= 0) {
                if (pos == loc) {
                    continue;
                }
                if (str[pos] == '9') {
                    str[pos] = '0';
                    if (!pos) {
                        str.insert(str.begin(), '1');
                    }
                } else {
                    str[pos]++;
                    break;
                }
            }
        } else {
            break;
        }
    }
    while (!str.empty() && str.back() == '0') {
        str.pop_back();
    }
    if (str.back() == '.') {
        str.pop_back();
    }
    cout << str << '\n';
}

