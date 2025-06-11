#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
#include <queue>
using namespace std;


int main() {
	
	int n;cin >> n;

	vector<int> a(n);
	for (int i = 0;i < n;++i) {
		cin >> a[i];
	}
    vector<int> stk;

    vector<int> mk(n);
    vector<int> ne(n);
    vector<int> sz(n);
    for (int i = n-1;i >=0;--i) {
        while (stk.size() > 0 && a[stk.back()] <= a[i]) {
            stk.pop_back();
        }
        stk.push_back(i);
    }
    reverse(stk.begin(), stk.end());
    for (int i = stk.size()-1;i  > 0;--i) {
        mk[stk[i]] = 1;
        ne[stk[i]] = stk[i - 1];
        sz[stk[i]] = i + 1;
    }
    mk[stk[0]] = 1;
    ne[stk[0]] = -1;
    sz[stk[0]] = 1;

    int bk = stk.size();
    int v = n+1;

    stk.clear();

   

    int r = 0;
    int rm = n+1;

    for (int i = n - 1;i >= 0;--i) {
        if (!mk[i]) {
            while (stk.size() > 0 && a[stk.back()] <= a[i]) {
                stk.pop_back();
            }
            stk.push_back(i);
            v = min(v, a[i]);
        }
        else {
            int bf = ne[i];
            if (bf != -1) {
                while (stk.size() > 0 && a[stk.back()] <= a[bf]) {
                    stk.pop_back();
                }
                int tp = sz[bf] + stk.size();
                if (tp > r || tp==r && rm > a[i]) {
                    rm = a[i];
                    r = tp;
                }
            }
            else {
                int tp = stk.size();
                if (tp > r || tp == r && rm > a[i]) {
                    rm = a[i];
                    r = tp;
                }
            }
            while (stk.size() > 0 && a[stk.back()] <= a[i]) {
                stk.pop_back();
            }
            stk.push_back(i);
        }
    }
    if (v <= n && (bk > r || bk == r && v < rm)) {
        cout << v;
    }
    else {
        cout << rm;
    }








	return 0;
}