#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> t(n);
    for (auto& i : t) {
        cin >> i;
    }
    
    vector<int> freq(101, 0);
    auto f = [&] (int sum, int target) -> int {
        int res = 0;
        int ti = 100;
        while (sum > target) {
            while (ti > 0 && freq[ti] == 0) ti--;
            if (ti <= 0) break;
            int k = (sum - target + ti - 1) / ti;
            sum -= ti * min(k, freq[ti]);
            res += min(k, freq[ti]);
            ti--;
        }
        return res;
    };
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cout << f(sum, m - t[i]) << " ";
        sum += t[i];
        freq[t[i]]++;
    }
    cout << endl;

    return 0;
}
