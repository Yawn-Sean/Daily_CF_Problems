int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;

	if (n == 2) {

		while (q --) {
			int x;
			cin >> x;
			cout << (quickPow(nums[0], nums[1], x) == 0 || quickPow(nums[1], nums[0], x) == 0 ? "Yes" : "No") << '\n';
		}
	}
	else if (n == 3) {

		while (q --) {
			int x;
			cin >> x;

			bool flg = false;
			sort(nums.begin(), nums.end());
	
			while (true) {
				int a = nums[0];
				int b = nums[1];
				int c = nums[2];

				int va = quickPow(a, min(20, b), x);
				int vb = quickPow(b, min(20, c), x);

				int pa = 1;
				for (int i = 0; i < min(b, 5); i ++)
					pa = min(pa * a, 20);
				
				int pb = 1;
				for (int i = 0; i < min(c, 5); i ++)
					pb = min(pb * b, 20);
				
				if (quickPow(va, pb, x) == 0 || quickPow(vb, pa, x) == 0)
					flg = true;

				if (!next_permutation(nums.begin(), nums.end())) break;
			}

			cout << (flg ? "Yes" : "No") << '\n';
		}
	}
	else {
		int cnt1 = 0;
		for (auto &v: nums)
			cnt1 += v == 1;
		
		if (cnt1 >= n - 1) {
			int val = *max_element(nums.begin(), nums.end());

			while (q --) {
				int x;
				cin >> x;
				cout << (val % x == 0 ? "Yes" : "No") << '\n';
			}
		}
		else {
			int M = 1e6;
			vector<int> prime_factor(M + 1);
			iota(prime_factor.begin(), prime_factor.end(), 0);

			for (int i = 2; i <= M; i ++) {
				if (prime_factor[i] == i) {
					for (int j = i; j <= M; j += i) {
						prime_factor[j] = i;
					}
				}
			}

			vector<int> notes(M + 1, 0);

			for (auto &x: nums) notes[x] = 1;

			for (int i = 1; i <= M; i ++) {
				for (int j = i; j <= M; j += i) {
					notes[i] |= notes[j];
				}
			}

			for (int i = 1; i <= M; i ++) {
				int cur = i, val = 1;
				while (cur > 1) {
					int p = prime_factor[cur];
					val *= p;
					while (cur % p == 0) cur /= p;
				}

				if (notes[val]) notes[i] = 1;
			}

			while (q --) {
				int x;
				cin >> x;
				cout << (notes[x] ? "Yes" : "No") << '\n';
			}
		}
	}

	return 0;
}
