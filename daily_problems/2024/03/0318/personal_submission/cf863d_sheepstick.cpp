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

void solve(){
    int n, q, m; cin >> n >> q >> m;
    vector<int> a(n);
    for (auto &ai : a){
    	cin >> ai;
    }

    vector<array<int,3>> ask(q);
    for (int i = 0; i < q; i++){
    	cin >> ask[i][0] >> ask[i][1] >> ask[i][2];
    	ask[i][1]--;
    	ask[i][2]--;
    }

    for (int i = 0; i < m; i++){
    	int x; cin >> x;
    	x--;
    	for (int j = q - 1; j >= 0; j--){
    		if (x >= ask[j][1] && x <= ask[j][2]){
    			if (ask[j][0] == 1){
    				x = (x == ask[j][1] ? ask[j][2] : x - 1);
    			}
    			else {
    				x = ask[j][1] + ask[j][2] - x;
    			}
    		}
    	}
    	cout << a[x] << " \n"[i == m - 1];
    }
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
