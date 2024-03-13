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
    int n, m; cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n, 0));
    vector<int> rowSum(m, 0), colSum(n, 0);
    vector<int> rowFlip(m, 0), colFlip(n, 0);
    for (int i = 0; i < m; i++){
    	for (int j = 0; j < n; j++){
    		cin >> a[i][j];
    		rowSum[i] += a[i][j];
    		colSum[j] += a[i][j];
    	}
    }


    while(*min_element(rowSum.begin(), rowSum.end()) < 0 || *min_element(colSum.begin(), colSum.end()) < 0) {
    	for (int i = 0; i < m; i++){
    		if (rowSum[i] < 0){
    			rowSum[i] = -rowSum[i];
    			for (int j = 0; j < n; j++){
    				a[i][j] = -a[i][j];
    				colSum[j] += 2 * a[i][j];
    			}
    			rowFlip[i] ^= 1;
    		}
    	}
    	for (int j = 0; j < n; j++){
    		if (colSum[j] < 0){
    			colSum[j] = -colSum[j];
    			for (int i = 0; i < m; i++){
    				a[i][j] = -a[i][j];
    				rowSum[i] += 2 * a[i][j];
    			}
    			colFlip[j] ^= 1;
    		}
    	}
    }
    int rowTotFlip = accumulate(rowFlip.begin(), rowFlip.end(), 0);
    int colTotFlip = accumulate(colFlip.begin(), colFlip.end(), 0); 

    cout << rowTotFlip <<" ";
    for (int i = 0; i < m; i++) if (rowFlip[i]){
    	cout << i + 1 << " ";
    }
    cout << "\n";


    cout << colTotFlip <<" ";
    for (int i = 0; i < n; i++) if (colFlip[i]){
    	cout << i + 1 << " ";
    }
    cout << "\n";

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
