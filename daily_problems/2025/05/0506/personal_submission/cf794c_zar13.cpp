#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int cnt1[30], cnt2[30];
string s1, s2;
int main() {
	cin >> s1 >> s2;
	int n = s1.size();
	for (int i = 0; i < n; i++) {
		cnt1[s1[i] - 'a']++;
		cnt2[s2[i] - 'a']++;
	}
	string s = string(n, ' '); //
	int l1 = 0, r1 = 25, l2 = 0, r2 = 25;
	int  idx = 0, t, add = 1;
	while (!cnt1[l1]) l1++;
	while (!cnt2[r2]) r2--;
	t = n / 2;
	while (t) {
		if (cnt1[r1]) {
			cnt1[r1]--;
			t--;
		}
		while (!cnt1[r1]) r1--;//while
	}
	t = (n + 1) / 2;
	while (t) {
		if (cnt2[l2]) {
			cnt2[l2]--;
			t--;
		}
		while (!cnt2[l2]) l2++;
	}

	t = n;
	bool fg = 1;
	while (t) {
		if (fg) {
			if (l1 >= r2) {
				fg = 0;
				idx = n - 1;
				continue;
			}
			s[idx] = 'a' + l1;
			cnt1[l1]--;
			while (!cnt1[l1]) l1++;
			t--;
			idx++;
			if (t) {
				if (l1 >= r2) {
					fg = 0;
					idx = n - 1;
					s[idx] = 'a' + l2;
					cnt2[l2]--;
					idx--;
					t--;
					continue;//把当前这一步走了再切换，以免顺序出错 
				}
				s[idx] = 'a' + r2;
				cnt2[r2]--;
				while (!cnt2[r2]) r2--;
				idx ++;
				t--;
			}
		} else {
			while (!cnt2[l2]) l2++;
			while (!cnt1[r1]) r1--;
			s[idx] = 'a' + r1;
			cnt1[r1]--;
			t--;
			idx--;
			if (t) {
				s[idx] = 'a' + l2;
				cnt2[l2]--;
				idx--;
				t--;
			}
		}
	}
	cout << s;
	return 0;
}
