// problem link: https://codeforces.com/contest/540/problem/E
//submission link: https://codeforces.com/contest/540/submission/256197106
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
class FenwickTreeOneBasedIndexing {
public:
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
	this->n = n + 1;
	bit.assign(n + 1, 0);
    }

    long long sum(int idx) {
	long long ret = 0;
	for (++idx; idx > 0; idx -= idx & -idx)
	    ret += (long long)bit[idx];
	return ret;
    }

    void add(int idx, int delta) {
	for (++idx; idx < n; idx += idx & -idx)
	    bit[idx] += delta;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> a;
    int l, r;
    vector<PII> swaps;
    for (int i = 0; i < n; i++) {
	cin >> l >> r;
	swaps.emplace_back(l, r);
	a.push_back(l);
	a.push_back(r);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<PII> x_len;
    int curr_num = 1;
    int len = 0;
    int j = 0;
    while (j < a.size()){
	if (a[j] > curr_num){
	    len = a[j] - curr_num;
	    x_len.emplace_back(curr_num, len);
	}
	x_len.emplace_back(a[j], 1);
	curr_num = a[j] + 1;
	j ++;
    }
    vector<int> xs;
    for (auto [x, len]: x_len){
	xs.push_back(x);
    }
    for (auto [l, r]: swaps){
	int l_idx = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
	int r_idx = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
	swap(x_len[l_idx], x_len[r_idx]);
    }
    FenwickTreeOneBasedIndexing ft(x_len.size() + 1);
    long long ret = 0;
    reverse(x_len.begin(), x_len.end());
    for (auto [x, len]: x_len){
	int idx = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
	ret += ft.sum(idx-1)*(LL)len;
	ft.add(idx, len);
    }
    cout << ret << endl;
    return 0;
}


