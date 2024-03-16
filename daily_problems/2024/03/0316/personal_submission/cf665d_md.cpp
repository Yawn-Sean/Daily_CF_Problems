#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int PCnt = 2e6 + 1;
    std::vector<bool> isPrime(PCnt, true);
    auto __init__ = [&]() -> int {
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < PCnt; i++) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < PCnt; j += i) {
                isPrime[j] = false;
            }
        }
        return 0;
    } ();

    int n;
    cin >> n;

    vector<int> a(n);
    copy_n(istream_iterator<int>(cin), n, begin(a));
    
    auto no_ones = [&]() -> vector<int> {
        for (int i = 0; i < n; ++i) {        
            for (int j = i + 1; j < n; ++j) {
                if (isPrime[a[i] + a[j]]) {
                    return { a[i], a[j] };
                }
            }
        }
        return { a[0] };
    };

    auto has_ones = [&]() -> vector<int> {
        int ones = count(begin(a), end(a), 1);
        vector<int> ret(ones, 1);
        for (int i = 0; i < n; ++i) {
            if (a[i] != 1 && isPrime[a[i] + 1]) {
                ret.push_back(a[i]);
                break;
            }
        }
        return ret;
    };

    auto ret1 = no_ones();
    auto ret2 = has_ones();

    if (size(ret1) > size(ret2)) {
        cout << size(ret1) << endl;
        copy(begin(ret1), end(ret1), ostream_iterator<int>(cout, " "));
    } else {
        cout << size(ret2) << endl;
        copy(begin(ret2), end(ret2), ostream_iterator<int>(cout, " "));
    }

    return 0;
}