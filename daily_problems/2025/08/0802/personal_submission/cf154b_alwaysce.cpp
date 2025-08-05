#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> factors[100001];
vector<int> is_prime(100001, 1);

void init() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= 100000; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= 100000; j += i) {
                is_prime[j] = 0;
                factors[j].push_back(i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init();
    
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1, 0);

    for (int i = 0; i < m; i++) {
        char op;
        cin >> op;
        if (op == '+') {
            int num;
            cin >> num;
            if (vis[num] > 0) {
                if (vis[num] == num) {
                    cout << "Already on\n";
                } else {
                    cout << "Conflict with " << vis[num] << '\n';
                }
            } else {
                bool ok = true;
                for (auto& f: factors[num]) {
                    if (vis[f]) {
                        cout << "Conflict with " << vis[f] << '\n';
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    vis[num] = num;
                    for (auto& f: factors[num]) {
                        vis[f] = num;
                    }
                    cout << "Success\n";
                }
            }
        } else {
            int num;
            cin >> num;
            if (vis[num] == 0 || vis[num] != num) {
                cout << "Already off\n";
            } else {
                vis[num] = 0;
                for (auto& f: factors[num]) {
                    vis[f] = 0;
                }
                cout << "Success\n";
            }
        }
    }
    return 0;
}
