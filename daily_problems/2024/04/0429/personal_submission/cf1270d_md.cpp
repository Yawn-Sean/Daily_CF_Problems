// 0429
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    map<int, int> freq;
    int max_m = -1;
    for (int i = 1; i <= k + 1; ++i) {
        string request = "?";
        for (int j = 1; j <= k + 1; ++j) {
            if (i == j) {
                continue;
            }
            request += " " + to_string(j);
        }
        int pos, m;
        cout << request << endl;
        cin >> pos >> m;
        max_m = max(max_m, m);
        freq[m]++;
    }
    cout << "! " << freq[max_m] << endl;

    return 0;
}