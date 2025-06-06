int n, cnt[N];

void print() {
    bool highest = true;
    for (int i = 9; i >= 0; i--) {
        if (cnt[i] > 0) {
            if (i > 0) {
                highest = false;
                for (int j = 0; j < cnt[i]; j++) {
                    cout << i;
                }
            } else {
                if (highest) {
                    cout << "0\n";
                } else {
                    for (int j = 0; j < cnt[i]; j++) {
                        cout << i;
                    }
                }
            }
        }
    }
}

void meibao() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        sum += x;
    }
    sum %= 3;
    if (cnt[0] == 0) {
        cout << "-1\n";
    } else {
        if (sum == 0) {
            print();
        } else {
            for (int i = 0; i < 10; i++) {
                if (cnt[i] > 0 && i % 3 == sum) {
                    cnt[i]--;
                    print();
                    return;
                }
            }

            for (int i = 1; i < 10; i++) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    for (int j = 1; j < 10; j++) {
                        if (cnt[j] > 0) {
                            cnt[j]--;
                            if ((sum - i - j) % 3 == 0) {
                                print();
                                return;
                            }
                            cnt[j]++;
                        }
                    }
                    cnt[i]++;
                }
            }
        }
    }
}
