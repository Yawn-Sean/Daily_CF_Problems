#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct KMP{ //1_idx
	T a;
	std::vector<int> ne;

	KMP(){}
	KMP(const T&v){ init(v); }

	void init(const T&v){
		a = v;
		ne.assign(a.size(),{});
		for(int i = 2,j = 0;i < a.size();i++){
			while(j > 0 && a[i] != a[j+1]) j = ne[j];
			if(a[i] == a[j+1]) j++;
			ne[i] = j;
		}
	}

	std::vector<int> kmp(const T&b){
		std::vector<int>ans;
		for(int i = 1,j = 0;i < b.size();i++){
			while(j > 0 && b[i] != a[j+1]) j = ne[j];
			if(b[i] == a[j+1]) j++;
			//f[i] = j;
			ans.emplace_back(j);
			if(j == a.size()-1) j = ne[j];
		}
		return ans;
	}
};

void soviet() {
	int n; std::cin >> n;
	std::string s; std::cin >> s;
	std::string t = s;
	for (int i = 0; i < t.size(); i++) t[i] ^= 1;
	KMP<std::string> f(' ' + s);
	for (auto x :f.kmp(' ' + t)) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
