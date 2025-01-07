/*
先看看需要加几个数和减几个数，假设分别是 cnt1 和 cnt2 个
由于 ? 只能填 [1, n] 之间的数，等号右边是 n，所以不一定有解
表达式值域是多少？加的全取 n，减的全取 1，得到最大值为 n * cnt1 - cnt2
加的全取 1，减的全取 n，得到最小值为 cnt1 - n * cnt2
所以 n \in [cnt1 - n * cnt2, n * cnt1 - cnt2] 时才有解
考虑先钦定所有的加的为 1，减的为 n，算一个数，然后调整
*/

void meibao() {
    string s;
    string cur;
    while (cin >> cur) {
        s += cur;
    }    
    LL cnt1 = 0, cnt2 = 0;
    int pos_equal = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '=') {
            pos_equal = i;
        }
    }
    LL n = 0;
    for (int i = pos_equal + 1; i < s.size(); i++) {
        n = 10 * n + s[i] - '0';
    }
    for (int i = 0; i < pos_equal; i++) {
        if (s[i] == '?') {
            if (i == 0 || s[i - 1] == '+') {
                cnt1++;
            } else {
                cnt2++;
            }
        }
    }
    // scout << cnt1 << " " << cnt2 << "\n";
    LL mn = cnt1 - n * cnt2, mx = n * cnt1 - cnt2;
    if (n < mn || n > mx) {
        cout << "Impossible\n";
        return;
    }
    cout << "Possible\n";
    LL delta = n - (cnt1 - n * cnt2);
    vector<LL> pos, neg;
    for (int i = 0; i < cnt1; i++) {
        pos.push_back(1);
    }
    for (int i = 0; i < cnt2; i++) {
        neg.push_back(n);
    }
    for (int i = 0; i < cnt1 && delta > 0; i++) {
        if (n - 1 > delta) {
            pos[i] += delta;
            delta = 0;
        } else {
            delta -= n - 1;
            pos[i] = n;
        }
    }
    for (int i = 0; i < cnt2 && delta > 0; i++) {
        if (n - 1 > delta) {
            neg[i] -= delta;
            delta = 0;
        } else {
            delta -= n - 1;
            neg[i] = 1;
        }
    }
    assert(delta == 0);
    int p1 = 1, p2 = 0;
    cout << pos[0];
    LL res = 0;
    for (int i = 0; i < cnt1; i++) {
        res += pos[i];
    }
    for (int i = 0; i < cnt2; i++) {
        res -= neg[i];
    }
    assert(res == n);
    for (int i = 1; i < pos_equal; i += 2) {
        cout << " ";
        cout << s[i];
        cout << " ";
        if (s[i] == '+') {
            cout << pos[p1++];
        } else {
            cout << neg[p2++];
        }
    }
    assert(p1 == cnt1 && p2 == cnt2);
    cout << " = ";
    cout << n << "\n";
}
