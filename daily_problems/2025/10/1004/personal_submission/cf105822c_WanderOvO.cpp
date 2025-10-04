/*
想要奇数的，必须分到一个奇数盘子和一个偶数盘子
如果奇数盘子根本不够奇数个数，就无解了
如果够，但是分完之后剩下的是奇数个，则必然还会出现一个奇数的，也无解了
不妨把奇数的盘子和偶数的盘子用两个堆维护一下
第 i 个盘子的值恰好是 i，不用堆维护了
遇到需要奇数的，显然是拿最小奇数和偶数的
遇到需要偶数的，我们看到底是拿两个奇数还是拿两个偶数，显然是拿更小的
这会导致奇数不够用吗？
*/

int n;
string s;

void meibao() {
    cin >> n >> s;
    int cnt_odd = 0;
    for (auto ch : s) {
        if (ch == 'O') {
            cnt_odd++;
        }
    }

    if (n % 2 != cnt_odd % 2) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int odd = 1, even = 2;
    for (auto ch : s) {
        if (ch == 'E') {
            if (odd < even) {
                assert(odd + 2 <= 2 * n);
                cout << odd << " " << odd + 2 << "\n";
                odd += 4;
            } else {
                assert(even + 2 <= 2 * n);
                cout << even << " " << even + 2 << "\n";
                even += 4;
            }
        } else {
            assert(odd <= 2 * n && even <= 2 * n);
            cout << odd << " " << even << "\n";
            odd += 2;
            even += 2;
        }
    }
}  
