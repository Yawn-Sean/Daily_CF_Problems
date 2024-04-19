#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<int> a(n), t(n);
    copy_n(istream_iterator<int>(cin), n, begin(a));
    copy_n(istream_iterator<int>(cin), n, begin(t));

    vector<int> ids(n);
    iota(begin(ids), end(ids), 0);
    sort(begin(ids), end(ids), [&](auto i, auto j) { return a[i] < a[j]; });
    
    int last_val = 0;
    i64 ret = 0;
    i64 tot = 0;
    priority_queue<int> larger_nums;
    for (auto id : ids) {
        int gap = a[id] - last_val;
        while (gap-- && !empty(larger_nums)) {
            tot -= larger_nums.top();
            larger_nums.pop();
            ret += tot;
        }

        larger_nums.push(t[id]);
        tot += t[id];
        last_val = a[id];
    }

    while (!empty(larger_nums)) {
        tot -= larger_nums.top();
        larger_nums.pop();
        ret += tot;
    }

    cout << ret << endl;

    return 0;
}