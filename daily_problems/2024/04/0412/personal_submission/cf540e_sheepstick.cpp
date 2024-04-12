#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

template<typename T>
struct Fenwick{
	int n;
	std::vector<T> a;
	Fenwick(T n): n(n), a(n){}

	void add(int x, T v){
		for (int i = x; i < n; i += i & -i){
			a[i] += v;
		}
	}
    
    T sum(int x){
        T res = 0;
        for (; x; x-= x &(-x)){
            res += a[x];
        }
        return res;
    }
};

void solve() {
	int n; cin >> n;
	map<int,int> pos, idx;
	while(n--){
		int a, b; cin >> a >> b;
		if (!pos.count(a)) pos[a] = a;
		if (!pos.count(b)) pos[b] = b;
		int oldA = pos[a], oldB = pos[b];
		pos[a] = oldB;
		pos[b] = oldA;
	}
	//idx
	for (auto &[k, v] : pos){
		idx[v] = k;
	}
	vector<array<int,3>> state; //[starting number, pos, weight]
	if (!idx.count(1)) {
		auto it = pos.begin();
		int w = it -> first - 1;
		state.push_back({1, 1, w});
	}
	//cerr << "aaa\n";
	for (auto it = idx.begin(); it != idx.end(); it++){
		auto [position, value] = *it;
		//cerr << position <<" "<< value << "---\n";
		state.push_back({value, position, 1});
		auto itt = next(it);
		if (itt != idx.end()){
			auto nxt = itt -> first;
			if (nxt != position + 1) state.push_back({position + 1, position + 1, nxt - position - 1});
		}
	}
	sort(state.begin(), state.end());
	
	//compress value
	vector<int> number;
	for (auto &[x, y, z] : state){
		number.push_back(y);
	}
	sort(number.begin(), number.end());
	number.erase(unique(number.begin(), number.end()), number.end());
	int sz = number.size();
	Fenwick<i64> fen(sz + 1);
	i64 res = 0;
	for (auto &[num, pos, w] : state){
		auto lb = lower_bound(number.begin(), number.end(), pos) - number.begin() + 1;
		res += 1LL * w * (pos - 1 - fen.sum(lb));
		fen.add(lb, w);
	}
	cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}