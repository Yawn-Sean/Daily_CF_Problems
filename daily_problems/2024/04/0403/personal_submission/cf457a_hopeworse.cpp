// link https://codeforces.com/problemset/problem/457/A


string s1, s2;
    cin >> s1 >> s2;
    int maxs = max(s1.size(), s2.size()) + 10;
    auto count = [&](string &s) {
        reverse(s.begin(), s.end());
        s.resize(maxs, '0');
        int k = maxs - 2;
        while (k >= 0) {
            debug(k < maxs - 1, s[k] == '1', s[k - 1] == '1', k, s, s[k], s[k - 1]);
            while (k < maxs - 1 && s[k] == '1' && s[k - 1] == '1') {
                s[k + 1] = '1';
                s[k] = s[k - 1] = '0';
                k += 2;
            }
            k--;
        }
        reverse(s.begin(), s.end());
    };

    count(s1);
    count(s2);
    debug(s1, s2);
    if (s1 > s2)cout << ">" << endl;
    else if (s1 < s2)cout << "<" << endl;
    else cout << "=" << endl;
