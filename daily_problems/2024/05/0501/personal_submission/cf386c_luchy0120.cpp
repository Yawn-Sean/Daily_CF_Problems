#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
using namespace std;

vector<array<int,2>> vs;

int main() {
	string s;cin >> s;

	vector<int> ct(26);
	for (char c : s) {
		ct[c - 'a']++;
	}
	int num = 0;
	for (int i = 0;i < 26;++i) {
		num += ct[i] > 0;
	}
	cout << num << endl;
	for (int i = 1;i <= num;++i) {
		vector<int> cnt1(26);
		int st1 = 0;
		int r1 = 0;
		vector<int> cnt2(26);
		int st2 = 0;
		int r2 = 0;
		long long tot = 0;
		for (int j = 0;j < s.size();++j) {
			if (++cnt1[s[j] - 'a'] == 1){
				r1++;
			}
			while (r1 > i) {
				if (--cnt1[s[st1++] - 'a'] == 0) {
					r1--;
				}
			}

			if (++cnt2[s[j] - 'a'] == 1) {
				r2++;
			}
			while (r2 >= i) {
				if (--cnt2[s[st2++] - 'a'] == 0) {
					r2--;
				}
			}
			if (r1 == i && r2 == i - 1) {
				tot += st2 - st1;
			}
		}
		cout << tot << endl;

	}

	


	
	return 0;
}