#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// submission:https://codeforces.com/contest/869/submission/262986407

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    vector<int> a(3);
    for (int i = 0; i < 3; ++i) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());

    mint c = 1;

    for (int i = 0; i < 3; ++i) {
    	for (int j = i + 1; j < 3; ++j) {
    		mint cur = 0;
    		for (int k = 0; k <= a[i]; ++k) {
    			cur += comb.C(a[i], k) * comb.C(a[j], k) * comb.fact(k);
    		}
    		c *= cur;
    	}
    }

    cout << c << "\n";

    return 0;
}
