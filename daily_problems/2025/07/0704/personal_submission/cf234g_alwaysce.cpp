#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    int k = 32 - __builtin_clz(n - 1);
    output << k << '\n';

    for (int i = 0; i < k; ++i) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            if (j >> i & 1) {
                tmp.push_back(j);
            }            
        }
        output << tmp.size() << ' ';
        for (auto& x : tmp) {
            output << x << ' ';
        }
        output << '\n';
    }
    return 0;
}
