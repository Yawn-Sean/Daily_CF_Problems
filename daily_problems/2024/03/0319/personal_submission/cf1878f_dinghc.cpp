#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1000001;
int lpf[N];

void sieve_lpf() {
    lpf[0] = lpf[1] = 1;

    for (int i = 2; i < N; i++) {
        if (lpf[i] == 0) {
            if (N / i > i) {
                for (int j = i * i; j < N; j += i) {
                    if (lpf[j] == 0) lpf[j] = i;
                }
            }
            lpf[i] = i;
        }
    }
}

int prime_factor(int k, unordered_map<int, int>& powers) {
    int d = 1;
    while (lpf[k] > 1) {
        int p = lpf[k], pow = 0;
        while (k % p == 0) {
            k /= p;
            pow++;
        }
        powers[p] = pow;
        d *= pow + 1;
    }
    return d;
}

int main() {
    // prepare least prime factors
    sieve_lpf();

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        
        unordered_map<int, int> powers, npowers;
        int dn, ndn;
        ndn = dn = prime_factor(n, powers);
        npowers = powers;

        vector<int> queries;
        while (q--) {
            int type, x;
            cin >> type;
            if (type == 1) {
                cin >> x;
                queries.push_back(x);

                unordered_map<int, int> xpowers;
                int dx = prime_factor(x, xpowers);

                for (auto&[p, pow] : xpowers) {
                    ndn /= npowers[p] + 1;
                    npowers[p] += pow;
                    ndn *= npowers[p] + 1;
                }

                long long nx = n;
                for (auto qx : queries) {
                    nx = nx * qx % ndn;
                }

                if (nx == 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                queries.clear();
                ndn = dn;
                npowers = powers;
            }
        }
        cout << endl;
    }

    return 0;
}

