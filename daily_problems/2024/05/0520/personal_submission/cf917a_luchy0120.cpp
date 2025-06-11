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
	string s;cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n,vector<int>(n));

	int r = 0;
	for (int i = 0;i < n;++i) {
		int le = 0;
		int x = 0;
		for (int j = i;j < n;++j) {
			if (s[j] == '(') {
				le++;
			}
			else if (s[j] == '?') {
				x++;
			}
			else if(le>0){
				le--;
			}
			else if (x > 0) {
				x--;
			}
			else {
				break;
			}
			if ((j - i + 1) % 2 == 0) {
				dp[i][j] = 1;
			}
		}
	}
	for (int i = n-1;i >= 0 ;--i) {
		int le = 0;
		int x = 0;
		for (int j = i;j >= 0;--j) {
			if (s[j] == ')') {
				le++;
			}
			else if (s[j] == '?') {
				x++;
			}
			else if (le > 0) {
				le--;
			}
			else if (x > 0) {
				x--;
			}
			else {
				break;
			}
			if (( i - j + 1) % 2 == 0 && dp[j][i]) {
				r++;
			}
		}
	}
	cout << r;

	
	
	
	return 0;
}