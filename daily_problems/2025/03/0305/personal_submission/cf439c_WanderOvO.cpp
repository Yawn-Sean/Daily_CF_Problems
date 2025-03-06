/*
需要看看有多少奇数和偶数
分成 k 个部分，其中有恰好 p 个部分的和为偶数，则恰好 k - p 个部分的和为奇数
a[i] 如果是偶数，则可以随便分给哪个部分都可以，这并不关键，关键在于奇数怎么分
k - p 个部分先每个部分分得一个奇数
看还剩下多少奇数，如果剩下奇数个奇数，考虑剩下 1 个和剩下 3 个的情况，咋分都无法解决问题
所以只能剩下偶数个奇数，然后一对一对分给这 k 个部分
最后用偶数把空的部分再填满
*/

int n, k, p; 

void meibao() {
    cin >> n >> k >> p;
    vector<int> evens, odds;
    vector<vector<int>> parts(k);
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (val % 2) {
            odds.push_back(val);
        } else {
            evens.push_back(val);
        }
    }

    if (odds.size() < k - p) {
        cout << "NO\n";
        return;
    }

    for (int i = p; i < k; i++) {
        parts[i].push_back(odds.back());
        odds.pop_back();
    }

    if (odds.size() % 2 != 0) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < p; i++) {
        if (odds.size() == 0) {
            break;
        }
        parts[i].push_back(odds.back());
        odds.pop_back();
        parts[i].push_back(odds.back());
        odds.pop_back();
    }

    while (odds.size() > 0) {
        parts[0].push_back(odds.back());
        odds.pop_back();
    }

    for (int i = p - 1; i >= 0; i--) {
        if (evens.size() == 0) {
            break;
        }
        parts[i].push_back(evens.back());
        evens.pop_back();
    }

    while (evens.size() > 0) {
        parts[0].push_back(evens.back());
        evens.pop_back();
    }

    for (int i = 0; i < k; i++) {
        if (parts[i].size() == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < k; i++) {
        cout << parts[i].size() << " ";
        for (auto val : parts[i]) {
            cout << val << " ";
        }
        cout << "\n";
    }
}   
