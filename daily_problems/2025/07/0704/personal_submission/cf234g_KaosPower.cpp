//  G. Practice

#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    int k = 32 - __builtin_clz(n - 1);
    fout << k << '\n';

    for (int i = 0; i < k; i ++) {
        vector<int> tmp;
        for (int j = 0; j < n; j ++) {
            if (j >> i & 1) tmp.emplace_back(j);
        }
        fout << tmp.size() << ' ';
        for (auto &x: tmp) fout << x << ' ';
        fout << '\n';
    }

    return 0;
}
