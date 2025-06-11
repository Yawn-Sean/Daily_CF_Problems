// 0523
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> perm(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(perm));
    std::transform(begin(perm), end(perm), begin(perm), [](int x) { return x - 1; });

    std::vector<int> cnt_after_removed_at(n);
    int max1 = -1;
    int max2 = -1;
    
    for (auto num : perm) {
        if (num > max1) {
            --cnt_after_removed_at[num];
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            ++cnt_after_removed_at[max1];
            max2 = num;
        }
    }

    cout << std::max_element(begin(cnt_after_removed_at), end(cnt_after_removed_at)) - begin(cnt_after_removed_at) + 1 << endl;

    return 0;
}