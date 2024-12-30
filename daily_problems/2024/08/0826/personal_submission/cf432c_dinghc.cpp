#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
vector<int> lpf(N + 1, 0);
vector<int> pr;

int init = [] () -> int {
    for (int i = 2; i <= N; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lpf[i * pr[j]] = pr[j];
            if (pr[j] == lpf[i]) break;
        }
    }
    return 0;
}();

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> pos(n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        pos[--x] = i;
        a[i] = x;
    }
    vector<int> pts(n + 2, 0);
    for (int i = 4; i <= n + 1; i += 2) {
        for (auto& p : pr) if (lpf[i - p] == i - p) {
            pts[i] = p;
            break;
        }
    }
    auto do_swap = [&] (int i, int j) {
        int x = a[i], y = a[j];
        a[i] = a[j];
        a[j] = x;
        pos[x] = j;
        pos[y] = i;
    };
    vector<pair<int, int>> swps;
    for (int i = 0; i < n; i++) {
        if (pos[i] == i) continue;
        int d = pos[i] - i + 1;
        if (lpf[d] == d) {
            swps.push_back(make_pair(i, pos[i]));
            do_swap(i, pos[i]);
        } else {
            if (d % 2 == 0) {
                swps.push_back(make_pair(pos[i] - 1, pos[i]));
                do_swap(pos[i] - 1, pos[i]);
                d -= 1;
            }
            if (lpf[d] == d) {
                swps.push_back(make_pair(i, pos[i]));
                do_swap(i, pos[i]);
            } else {
                int d1 = pts[d + 1];
                int d2 = d + 1 - d1;
                int j = pos[i] - d1 + 1;
                swps.push_back(make_pair(j, pos[i]));
                do_swap(j, pos[i]);
                swps.push_back(make_pair(j - d2 + 1, j));
                do_swap(j - d2 + 1, pos[i]);
            }
        }
    }
    printf("%d\n", swps.size());
    for (auto&[x, y] : swps) {
        printf("%d %d\n", x + 1, y + 1);
    }
    return 0;
}

