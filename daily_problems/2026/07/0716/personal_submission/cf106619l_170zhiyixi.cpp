int n, k;
		cin >> n >> k;
		vector<int>a(n + 5);
		for (int  i = 1; i <= n; i++) {
			cin >> a[i];
		}
		vector<int>q(n + 5, -1e10);
		int sum = 0;
		vector<int>ans;
		int len = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i];
			int l = 0, r = len;
			int ansmid = 0;
			while (l <= r) {
				int mid = l + r >> 1;
				if (q[mid] >= a[i]) {
					r = mid - 1; 
				} else {
					l = mid + 1;
					ansmid = mid;
				} 
			}
			len = max(len, ansmid + 1);
			q[ansmid + 1] = a[i];
			//cout << ansmid << ' ' << len << ' ' << q[len] << endl;
			if (q[len] < len) {
				ans.push_back(sum + (len + (len + k - 1)) * k / 2);
			} else {
				ans.push_back(sum + len * k);
			}
			
		} 
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << endl;c
