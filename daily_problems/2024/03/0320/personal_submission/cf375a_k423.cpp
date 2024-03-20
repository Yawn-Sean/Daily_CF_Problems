/**
 * Created by 5cm/s on 2024/03/20 09:37:00.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

int A[] = {1869, 6198, 1896, 1689, 1986, 1968, 1698};

void elysia() {
    string s;
    cin >> s;
    vector<int> cnt(10);
    cnt[1] = cnt[6] = cnt[8] = cnt[9] = -1;
    for (char x: s) cnt[x - '0']++;
    int rem = 0;
    for (int x = 1; x <= 9; ++x) {
        while (cnt[x]--) {
            rem = (rem * 10 + x) % 7;
            cout << x;
        }
    }
    cout << A[rem] << string(cnt[0], '0') << endl;
}

int main() {
#ifdef MEGURINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    clock_t start = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
