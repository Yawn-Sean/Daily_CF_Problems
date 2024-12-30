#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;


using ll = long long;
int main() {
	int n;cin >> n;
	vector<int> cnt(1e5 + 1);

	map<int, int> freq;
	int r = -1;
	for (int i = 0;i < n;++i) {
		int c; cin >> c;
		cnt[c]++;
		if (freq.count(cnt[c] - 1)) {
			freq[cnt[c] - 1]--;
			if (freq[cnt[c] - 1] == 0) {
				freq.erase(cnt[c] - 1);
			}
		}
		freq[cnt[c]]++;
		if (freq.size() >= 3) {
			continue;
		}
		else if (freq.size() == 2) {
			if (freq.begin()->first == 1 && freq.begin()->second == 1) {
				r = i;
			}
			if (freq.rbegin()->first == freq.begin()->first + 1 && freq.rbegin()->second == 1) {
				r = i;
			}
		}
		else if (freq.size() == 1) {
			if (freq.begin()->first == 1 || freq.begin() ->second == 1) {
				r = i;
			}
		}


	}
	cout << (r + 1) << endl;






	return 0;
}