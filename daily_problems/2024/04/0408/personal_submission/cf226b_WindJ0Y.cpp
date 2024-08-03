#include <bits/stdc++.h>
using namespace std;

void work() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());
    vector<long long> v_sum(n);
    long long ans_of_1{};

    v_sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        v_sum[i] = v_sum[i - 1] + v[i];
        ans_of_1 += 1ll * v[i] * i;
    }

    int q;
    cin >> q;

    while (q--) {
        int mx_son;
        cin >> mx_son;

        if (mx_son == 1) {
            cout << ans_of_1 << "\n";
            continue;
        }

        long long ans = 0;
        long long pos = 0;
        int dvh = 0;
        long long div_sz = 1;

        while (pos < n) {
            long long tail = v_sum[min(pos + div_sz - 1, static_cast<long long>(n - 1))];
            long long head = (pos > 0 ? v_sum[min(pos - 1, static_cast<long long>(n - 1))] : 0);

            long long dv_tot = tail - head;
            ans += dv_tot * dvh;

            dvh ++;
            pos += div_sz;
            div_sz *= mx_son;
        }

        cout << ans << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T{1};
    // cin >> T;

    while (T--) {
        work();
    }
}