#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n, k;cin >> n >> k;
	int lst = -1;
	int change = 0;
	vector<int> part;
	for (int i = 0;i < n;++i) {
		int t;cin >> t;
		if (t < 0) {
			k--;
			if(lst!=-1 && i -lst >1){
				part.push_back(i - lst-1);
				change += 2;	
			}
			lst = i;
		}
	}

	if (k < 0) {
		cout << -1; return 0;
	}
	if (part.size() == 0) {
		if (lst == -1) {
			cout << 0;
		}
		else if (n-lst-1>k) {
			cout << 2 << endl;
		}
		else {
			cout << 1 << endl;
		}
		return 0;
	}
	change++;
	int nd = n - lst - 1;
	if (nd > 0) {
		change++;
	}
	sort(part.begin(), part.end());
		
	for (int i = 0;i < part.size();++i) {
		if (k >= part[i]) {
			change -= 2;
			k -= part[i];
		}
		else {
			break;
		}
	}
		
	if (nd > 0 && k >= nd) {
		change--;
	}
	cout << change;







	
	return 0;
}