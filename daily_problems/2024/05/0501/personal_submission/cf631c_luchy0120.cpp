#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
using namespace std;

vector<array<int,2>> vs;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0;i < n;++i) {
		cin >> a[i];
	}
	vector<array<int, 2>> stk;
	for (int i = 0;i < m;++i) {
		int tp, r; cin >> tp >> r;
		while (stk.size() && stk.back()[0] <= r) {
			stk.pop_back();
		}
		if(stk.empty() || stk.back()[1] != tp) {
			stk.push_back({r, tp});
		}
	}
	int r = stk[0][0];
	vector<int> b(a.begin(), a.begin() + r);
	sort(b.begin(), b.end());
	
	
	int at = r - 1;
	int ed = r - 1;
	int st = 0;
	for (int i = 0;i < stk.size();++i) {
		int tp = stk[i][1];
		int d = stk[i][0] - ((i+1<stk.size()) ? stk[i + 1][0]:0);
		if (tp == 1) {
			while (d--) {
				a[at--] = b[ed--];
			}
		}
		else {
			while (d--) {
				a[at--] = b[st++];
			}
		}
	}

	for (int i = 0;i < n;++i) {
		cout << a[i] << " ";
	}
	


	
	return 0;
}