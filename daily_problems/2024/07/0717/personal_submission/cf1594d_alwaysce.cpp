#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

struct DSU {
    //......
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        // 后面一半是虚点 大小=0
        for (int i = n / 2; i < n; i++) {
        	siz[i] = 0;
        }
    }
    //......
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        siz[y] = 0;
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[x];
    }
};


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	while (t--) {
		int n, m;
		std::cin >> n >> m;
		
		// 0-n-1 对应imposter
		// n-2n-1 对应非imposter
		DSU d(2 * n);
		/*
			If one call another an "imposter", 
			they are just of different types; 
			otherwise, they are of the same type.
		*/
		
		for (int x = 0; x < m; x++) {
			int i, j;
			std::string c;
			std::cin >> i >> j >> c;
			--i; --j;
			
			if (c == "imposter") {
				d.merge(i, j + n);
				d.merge(j, i + n);
			} else {
				d.merge(i, j); // of-same-type
				d.merge(i + n, j + n); // of-same-type
			}
		}
		
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (d.find(i) == d.find(i + n)) {
				std::cout << -1 << '\n';
				ok = false;
				break;
			}
		}
		
		if (ok) {
			int ans = 0;
			std::vector<int> vis(2 * n, 0);
			for (int i = 0; i < n; i++) {
				int x1 = d.find(i), x2 = d.find(i + n);
				
				if(!vis[x1] and !vis[x2]) {
					ans += std::max(d.size(x1), d.size(x2));
					vis[x1] = vis[x2] = 1;
				}
			}
			std::cout << ans << '\n';			
		}
	}

	return 0;
}
