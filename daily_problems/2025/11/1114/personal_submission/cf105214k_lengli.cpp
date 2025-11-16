#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, vector<string>> d;
    d[1] = { "." };

    d[2] = {
        "#.",
        "#."
    };

    d[3] = {
        "#.#",
        "#.#",
        "..."
    };

    d[4] = {
        "#.##",
        "#...",
        "...#",
        "##.#"
    };

    d[5] = {
        "##.##",
        ".....",
        "##.##",
        ".....",
        "##.##"
    };

    d[6] = {
        "##.#.#",
        "...#.#",
        "##....",
        "....##",
        "#.#...",
        "#.#.##"
    };

    int t;
    if (!(cin >> t)) return 0;
    vector<string> outputs;
    outputs.reserve(t);

    while (t--) {
        int n;
        cin >> n;
        int v = (n - 1) % 6 + 1;
        vector<string> ans(n, string(n, '.'));
        for (int i = n - v; i < n; ++i) {
            for (int j = n - v; j < n; ++j) {
                ans[i][j] = d[v][i - (n - v)][j - (n - v)];
            }
        }

        if (n % 2 == 1) {
            for (int i = 0; i < n - v; i += 3) {
                for (int j = 0; j < n; j += 2) {
                    ans[i][j] = '#';
                    if (i + 1 < n) ans[i + 1][j] = '#';
                }
            }
        } else {
            for (int i = 0; i < n - v; i += 2) {
                ans[i][0] = '#';
                if (1 < n) ans[i][1] = '#';
            }

            for (int i = 0; i < n - v; i += 3) {
                for (int j = 3; j < n; j += 2) {
                    ans[i][j] = '#';
                    if (i + 1 < n) ans[i + 1][j] = '#';
                }
            }
        }

        if (v % 2 == 1) {
            for (int i = n - v; i < n; i += 2) {
                for (int j = 0; j < n - v; j += 3) {
                    ans[i][j] = '#';
                    if (j + 1 < n) ans[i][j + 1] = '#';
                }
            }
        } else {
            for (int j = 0; j < n - v; j += 2) {
                ans[n - v][j] = '#';
                if (n - v + 1 < n) ans[n - v + 1][j] = '#';
            }

            for (int i = n - v + 3; i < n; i += 2) {
                for (int j = 0; j < n - v; j += 3) {
                    ans[i][j] = '#';
                    if (j + 1 < n) ans[i][j + 1] = '#';
                }
            }
        }

        string block;
        for (int i = 0; i < n; ++i) {
            block += ans[i];
            if (i + 1 < n) block += '\n';
        }
        outputs.push_back(block);
    }

    for (size_t i = 0; i < outputs.size(); ++i) {
        cout << outputs[i];
        if (i + 1 < outputs.size()) cout << "\n\n";
    }

    return 0;
}
