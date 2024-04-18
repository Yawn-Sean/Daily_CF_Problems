#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<pii> segs;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        segs.emplace_back(l, r);
        nums.push_back(l);
        nums.push_back(l - 1);
        nums.push_back(r);
        nums.push_back(r + 1);    
    }
    
    sort(begin(nums), end(nums));
    nums.erase(unique(begin(nums), end(nums)), end(nums));
    auto find = [&](int x) {
        return lower_bound(begin(nums), end(nums), x) - begin(nums) + 1;
    };

    vector<int> cnt(size(nums) + 1, 0);
    for (auto[l, r] : segs) {
        cnt[find(l)]++;
        cnt[find(r) + 1]--;
    }

    partial_sum(begin(cnt), end(cnt), begin(cnt));

    vector<int> prefix(size(nums), 0);
    for (int i = 1; i < size(nums); ++i) {
        prefix[i] = prefix[i-1] + (cnt[i] == 1);
    }

    for (int i = 0; i < size(segs); ++i) {
        auto[l, r] = segs[i];
        int check = prefix[find(r)] - prefix[find(l) - 1];
        if (check == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}