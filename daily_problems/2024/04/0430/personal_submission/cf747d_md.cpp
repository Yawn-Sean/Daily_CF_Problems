// 0430
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    vector<int> t(n);
    copy_n(istream_iterator<int>(cin), n, begin(t));

    vector<int> weather;
    weather.push_back(t[0] >= 0 ? 1 : -1);
    int winter = t[0] < 0;
    for (int i = 1; i < n; ++i) {
        winter += t[i] < 0;
        if (weather.back() >= 0 && t[i] >= 0) {
            weather.back() += 1;
        } else if (weather.back() < 0 && t[i] < 0) {
            weather.back() -= 1;
        } else {
            weather.push_back(t[i] >= 0 ? 1 : -1);
        }
    }

    int resid = k - winter;
    if (resid < 0) {
        cout << -1 << endl;
        return 0;
    }

    priority_queue<int, vector<int>, greater<>> summers;
    int change_cnt = 0;
    int cur_state = 1;
    int last_days = -1;
    for (auto i = 0; i < size(weather); ++i) {
        auto w = weather[i];
        if (w > 0) {
            if (i == size(weather) - 1) {
                last_days = w;
            } else if (i > 0) {
                summers.push(w);
            }
        } 
 
        if ((cur_state > 0) != (w > 0)) {
            change_cnt++;
            cur_state = w;
        }
    }

    while (!empty(summers)) {
        auto cur = summers.top();
        summers.pop();
        if (cur <= resid) {
            resid -= cur;
            change_cnt -= 2;
        } else {
            break;
        }
    }

    if (last_days > 0 && resid >= last_days) {
        change_cnt--;
    }

    cout << max(change_cnt, 0) << endl;
    return 0;
}