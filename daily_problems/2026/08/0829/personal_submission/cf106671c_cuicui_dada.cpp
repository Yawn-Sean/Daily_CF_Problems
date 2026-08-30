#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    deque<int> a;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        int val = x % MOD;
        a.push_back(val);
        sum = (sum + val) % MOD;
    }

    int q;
    cin >> q;
    int total_q = q;
    int rev = 0;

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            ll x;
            cin >> x;
            int val = x % MOD;
            if (rev == 0) a.push_back(val);
            else a.push_front(val);
            sum = (sum + val) % MOD;
        }


        else if (op == 2) {
            if (rev == 0) {
                sum = (sum - a.back() + MOD) % MOD;
                a.pop_back();
            } else {
                sum = (sum - a.front() + MOD) % MOD;
                a.pop_front();
            }
        }
        else if (op == 3) {
            rev ^= 1;
        }
        else if (op == 4) {
            sum = (sum * 2) % MOD;
            if ((int)a.size() <= total_q) {
                vector<int> tmp(a.begin(), a.end());
                a.insert(a.end(), tmp.begin(), tmp.end());
            }
        }
        else if (op == 5) {
            cout << sum <<endl;
        }
    }

    return 0;
}