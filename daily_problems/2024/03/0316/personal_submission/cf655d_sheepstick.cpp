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

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for (auto &ai : a){
    	cin >> ai;
    }


    //with 1
    int oneCnt = 0, extra = -1;
    for (auto &ai : a){
    	if (ai == 1) oneCnt++;
    	else if (extra == -1){
    		if (minp[1 + ai] == 1 + ai){
    			extra = ai;
    		}
    	}
    }
    int sz = oneCnt + (extra != -1);
    if (sz >= 2){
    	cout << sz << "\n";
    	for (int j = 0; j < oneCnt; j++){
    		cout << 1 <<" ";
    	}
    	if (extra != -1) cout << extra;
    	cout << "\n";
    	return;
    }


    //without 1, at most 2
    for (int i = 0; i < n; i++){
    	for (int j = i + 1; j < n; j++){
    		if (minp[a[i] + a[j]] == a[i] + a[j]){
    			cout << 2 << "\n";
    			cout << a[i] <<" "<< a[j] << "\n";
    			return;
    		}
    	}
    }
    cout << 1 << "\n";
    cout << a[0] << "\n";



}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    sieve(2E6 + 5);
    while(t--){
        solve();
    }
}
