#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string s1, s2;
    fin >> s1 >> s2;

    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (auto &c: s1) cnt1[c - 'A'] ++;
    for (auto &c: s2) cnt2[c - 'A'] ++;

    int n = s1.size(), ans = 0;
    vector<int> v1(26, 0), v2(26, 0);
    for (int i = 0; i < 26; i ++) {
        int v = abs(cnt1[i] - cnt2[i]);
        if (cnt1[i] > cnt2[i]) v1[i] = v;
        else v2[i] = v;
        ans += v;
    }

    for (int i = 0; i < n; i ++) {
        cnt1[s1[i] - 'A'] --;

        if (v1[s1[i] - 'A']) {
            for (int j = 0; j < 26; j ++) {
                if (j >= s1[i] - 'A' && cnt1[s1[i] - 'A'] >= v1[s1[i] - 'A']) break;
                if (v2[j]) {
                    v1[s1[i] - 'A'] --;
                    v2[j] --;
                    s1[i] = 'A' + j;
                    break;
                }
            }
        }
    }

    fout << ans / 2 << '\n';
    fout << s1;

    return 0;
}