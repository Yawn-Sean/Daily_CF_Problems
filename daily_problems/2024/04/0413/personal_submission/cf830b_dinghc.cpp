// Submission link: https://codeforces.com/contest/830/submission/256469656

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    stable_sort(indices.begin(), indices.end(), [&] (int x, int y) {
        return a[x] < a[y];
    });

    fenwick_tree<int> fw(n);
    for (int i = 0; i < n; i++) {
        fw.add(i, 1);
    }

    long long ans = 0LL;
    for (int i = 0, last = 0; i < n; ) {
        int j = i;
        int curr = -1;
        int mn_idx = indices[i], mx_idx = indices[i];
        while (j < n && a[indices[j]] == a[indices[i]]) {
            mx_idx = indices[j];
            if (indices[j] < last) {
                curr = indices[j];
            }
            j++;
        }

        if (mn_idx >= last) {
            ans += fw.range_sum(last, mx_idx);
            last = mx_idx + 1;
        } else {
            ans += fw.range_sum(last, n - 1) + fw.sum(curr);
            last = curr + 1;
        }

        for (int k = i; k < j; k++) {
            fw.add(indices[k], -1);
        }

        i = j;
    }

    cout << ans << "\n";

    return 0;
}

