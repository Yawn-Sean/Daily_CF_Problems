/*
好像只能填 1-n，那么只要满足是个排列就好了，1-n 的数都被使用恰好一次
*/

int leader[N], n, m, res[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> leader[i];
        leader[i]--;
    }

    set<int> left;
    for (int i = 1; i <= n; i++) {
        left.insert(i);
    }
    for (int i = 1; i + 1 <= m; i++) {
        int step = leader[i + 1] - leader[i];
        if (step <= 0) {
            step += n;
        }
        if (res[leader[i] + 1] != 0) {
            if (step != res[leader[i] + 1]) {
                cout << "-1\n";
                return;
            }
        } else if (left.count(step)) {
            res[leader[i] + 1] = step;
            left.erase(step);
        } else {
            cout << "-1\n";
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (res[i] > 0) {
            cout << res[i] << " ";
        } else {
            cout << *left.begin() << " ";
            int val = *left.begin();
            left.erase(val);
        }
    }
}     
