#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> b(n);
    copy_n(istream_iterator<long long>(cin), n, begin(b));

    map<long long, int> counter;
    int max_freq = 0;
    int max_mask = 0;
    for (auto val : b) {
        long long mask = __builtin_ctzll(val);
        ++counter[mask];
        if (max_freq < counter[mask]) {
            max_freq = counter[mask];
            max_mask = mask;
        }
    }

    vector<long long> ret;
    for (auto val : b) {
        long long mask = __builtin_ctzll(val);
        if (mask != max_mask) {
            ret.push_back(val);
        }
    }

    cout << size(ret) << endl;
    for (int i = 0; i < size(ret); ++i) {
        cout << ret[i] << " \n"[i == size(ret) - 1];
    }

    return 0;
}