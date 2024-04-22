void solve() {
    int a, b;
    cin >> a >> b;
    int sums = a + b;
    int sums1 = 0;
    int i = 1;
    while (1) {
        if (sums1 + i > sums) break;
        sums1 += i;
        i++;
    }
    i;
    int left = a;
    int z = 0;
    vector<int> arr(i);
    for (int k = i - 1; k; k--) {
        if (k <= left) {
            arr[k] = 1;
            left -= k;
            z++;
        }
    }
    cout << z << endl;
    for (int k = 1; k < i; k++) {
        if (arr[k]) {
            cout << k << " ";
        }
    }
    cout << endl;
    cout << i - 1 - z << endl;
    for (int k = 1; k < i; k++) {
        if (!arr[k]) {
            cout << k << " ";
        }
    }
}
