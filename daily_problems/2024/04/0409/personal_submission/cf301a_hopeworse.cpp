//link : https://codeforces.com/contest/301/submission/255827666

void solve() {
    int n;
    cin >> n;
    vector<int> arr(2 * n - 1);
    for (auto &i: arr) {
        cin >> i;
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        sum1 += arr[i];
    }
    int absmax = inf;
    for (int i = 0; i < 2 * n - 1; i++) {
        sum2 += abs(arr[i]);
        absmax = min(absmax, abs(arr[i]));

    }
    if (n % 2 == 0) {
        sum2 -= absmax * 2;
    }
    int sums3 = 0;
    sums3 = sum1;
    ranges::sort(arr);
    for (int i = 0; i < 2 * n - 1; i += 2) {
        sums3 = max(sums3, sums3 - 2 * (arr[i] + arr[i + 1]));
    }
    debug(sum1, sum2, absmax, sums3);
    cout << max({sum1, sum2, sums3}) << endl;
}
