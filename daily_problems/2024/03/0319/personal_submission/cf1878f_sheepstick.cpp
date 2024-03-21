#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;
using i64 = long long;

constexpr int N = 1E6;
int mp[N + 1];
vector<int> primes;
 
void init(){
    for (int i = 2; i <= N; i++) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > N) break;
            mp[i * p] = p;
            if (i % p == 0) break;
        }
    }
}
 
void solve() {
    int n, q; cin >> n >> q;
 
    i64 oldD = 1;
    map<int,int> oldCoeff;
    for (int i = n; i > 1; i = i / mp[i]){
        oldCoeff[mp[i]]++;
    }
 
    for (auto &[k, v] : oldCoeff){
        oldD = oldD * (1 + v);
    }
 
    i64 curD = oldD;
    auto curCoeff = oldCoeff;
    while(q--){
        int k; cin >> k;
        if (k == 2){
            curD = oldD;
            curCoeff = oldCoeff;
        }
        else {
            i64 x; cin >> x;
            map<int,int> tmp;
            for (int i = x; i > 1; i = i / mp[i]){
                tmp[mp[i]]++;
            }
            for (auto &[k, v] : tmp){
                if (curCoeff.count(k)){
                    curD /= (1 + curCoeff[k]);
                }
                curCoeff[k] += v;
                curD = curD * (1 + curCoeff[k]);
            }
            i64 y = curD;
            for (auto [k, v] : curCoeff){
                while(y % k == 0 && v){
                    y /= k;
                    v--;
                }
            }
            if (y == 1){
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
    cout << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    cin >> t;
    init();
    while(t--){
        solve();
    }
}
