#include <iostream>
#include <string>
#include <vector>
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
    
	auto ask = [&](i64 i, i64 j) -> i64 {
		cout << "? "<< i <<" "<< j << endl;
		i64 res; cin >> res;
		return res;
	};

	i64 d1 = ask(1, 1);
	i64 d2 = ask(1, 1E9);

	i64 mid = (1 + 1E9 + d1 - d2) / 2;

	i64 d3 = ask(1E9, 1);
	i64 d4 = ask(1, mid);

	cout << "! "<< int(1 + d4) <<" "<< int(1 + d1 - d4) <<" "<< int(1E9 + d1 - d4 - d3) <<" "<< int(1E9 - d2 + d4) << endl;
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
