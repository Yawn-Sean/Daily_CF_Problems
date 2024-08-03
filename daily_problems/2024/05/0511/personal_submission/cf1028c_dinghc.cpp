#include <bits/stdc++.h>

using namespace std;
constexpr int MXP = 1'000'000'000;
constexpr int MNP = -1'000'000'000;
constexpr int MXN = 132674;
array<int, 4> rects[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> rects[i][0] >> rects[i][1] >> rects[i][2] >> rects[i][3];
    }
    vector<array<int, 4>> pref_itsx(n + 1);
    pref_itsx[0] = {MNP, MNP, MXP, MXP};
    for (int i = 1; i <= n; i++) {
        auto& [x1, y1, x2, y2] = rects[i - 1];
        auto& [x1_, y1_, x2_, y2_] = pref_itsx[i - 1];
        pref_itsx[i][0] = max(x1, x1_);
        pref_itsx[i][1] = max(y1, y1_);
        pref_itsx[i][2] = min(x2, x2_);
        pref_itsx[i][3] = min(y2, y2_);
    }
    vector<array<int, 4>> suff_itsx(n + 1);
    suff_itsx[n] = {MNP, MNP, MXP, MXP};
    for (int i = n - 1; i >= 0; i--) {
        auto& [x1, y1, x2, y2] = rects[i];
        auto& [x1_, y1_, x2_, y2_] = suff_itsx[i + 1];
        suff_itsx[i][0] = max(x1, x1_);
        suff_itsx[i][1] = max(y1, y1_);
        suff_itsx[i][2] = min(x2, x2_);
        suff_itsx[i][3] = min(y2, y2_);
    }
    int x, y;
    for (int i = 0; i < n; i++) {
        auto& [x1, y1, x2, y2] = pref_itsx[i];
        auto& [x1_, y1_, x2_, y2_] = suff_itsx[i + 1];
        int x_bl = max(x1, x1_);
        int y_bl = max(y1, y1_);
        int x_ur = min(x2, x2_);
        int y_ur = min(y2, y2_);
        if (x_bl <= x_ur && y_bl <= y_ur) {
            x = x_bl;
            y = y_bl;
            break;
        }
    }
    cout << x << " " << y << "\n";
    return 0;
}

