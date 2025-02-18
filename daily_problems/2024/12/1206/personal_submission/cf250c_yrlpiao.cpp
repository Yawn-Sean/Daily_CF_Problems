#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a, cnt(k, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        --x;
        if (a.empty() || a.back() != x) a.push_back(x);
    }
    for (int i = 0; i < a.size(); i++) {
        if (!i) cnt[a[i]] += a[i] != a[i + 1];
        else if (i == a.size() - 1) {
            cnt[a[i]] += a[i] != a[i - 1];
        } else {
            cnt[a[i]] += (a[i] != a[i - 1]) + (a[i] != a[i + 1]) - (a[i - 1] != a[i + 1]);
        }
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    int ans = find(cnt.begin(), cnt.end(), mx) - cnt.begin();
    cout << ++ans;
    return 0;
}
