/*
利用好数作为中转，可以 3 次操作交换任意两个数
虽然没有要求最小化操作次数，但是给了操作次数上限，上面的保底策略可能会超上限
想到了另一种方法，假设有至少 1 个好数，我们直接将其与第一个数交换
然后再用真正该放在第一个位置的数和好数交换
接下来，不把好数归回原位，而是直接和第二个交换...
当遇到某个位置就是填好数时，应该怎么办？先跳过不管它
等最后一个数也归位时，那个好数在哪儿呢？其实它也归位了
*/

int n, a[N], b[N];

void meibao() {
    cin >> n;
    map<int, set<int>> pos; 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        pos[a[i]].insert(i);
    }
    sort(b + 1, b + n + 1);
    
    auto good = [&] (int val) -> bool {
        while (val) {
            if (val % 10 != 4 && val % 10 != 7) {
                return false;
            }
            val /= 10;
        }
        return true;
    };

    int good_pos = -1;
    for (int i = 1; i <= n; i++) {
        if (good(a[i])) {
            good_pos = i;
            break;
        }
    }

    if (good_pos == -1) {
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) {
                cout << "-1\n";
                return;
            }
        }
        cout << "0\n";
        return;
    }

    int deleted_p = *pos[a[good_pos]].begin();
    pos[a[good_pos]].erase(deleted_p);

    bool first_meet = false;
    vector<PII> swaps;
    for (int i = 1; i <= n; i++) {
        if (b[i] == a[good_pos]) {
            if (!first_meet) {
                first_meet = true;
                continue;
            }
        }
        
        if (i != good_pos) {
            swaps.push_back({i, good_pos});
            pos[a[i]].erase(i);
            pos[a[i]].insert(good_pos);
            swap(a[i], a[good_pos]);
            good_pos = i;
        }   

        int p = *pos[b[i]].begin();
        pos[b[i]].erase(p);

        if (p != good_pos) {
            swaps.push_back({good_pos, p});
            pos[a[p]].erase(p);
            swap(a[good_pos], a[p]);
            good_pos = p;
        } else {
            pos[b[i]].insert(p);
        }
    }

    if (a[good_pos] != b[good_pos]) {
        bool another_pos = -1;
        for (int i = 1; i <= n; i++) {
            if (i != good_pos && a[i] != b[i]) {
                another_pos = i;
                break;
            }
        }
        assert(another_pos != -1);
        swaps.push_back({good_pos, another_pos});
        swap(a[good_pos], a[another_pos]);
    }

    cout << swaps.size() << "\n";
    for (auto &p : swaps) {
        cout << p.x << " " << p.y << "\n";
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
}   
