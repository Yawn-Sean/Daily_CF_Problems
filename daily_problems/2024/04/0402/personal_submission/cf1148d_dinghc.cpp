#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> seq1, seq2;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        if (l < r) {
            seq1.push_back({l, r, i});
        } else {
            seq2.push_back({l, r, i});
        }
    }

    if (seq1.size() > seq2.size()) {
        ranges::sort(seq1, greater<>());
    } else {
        ranges::sort(seq2);
        swap(seq1, seq2);
    }

    cout << seq1.size() << "\n";
    for (auto& [k, v, i] : seq1) {
        cout << i << " ";
    }

    return 0;
}

