int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x1, x2;
	cin >> n >> x1 >> x2;
	vector<pair<int,int>>nums(n); //编号，值
	for (int i=0;i<n;i++)
	{
		int value;
		cin >> value;
		nums[i] = make_pair(i, value);
	}
	sort(nums.begin(), nums.end(), [&](pair<int, int>a, pair<int, int>b) {return a.second < b.second; });

	//一项服务所用的服务器容量值一定是连续的（贪心）。 所以可以先排序 然后采用类似滑动窗口的方法遍历
	// 先排x1 遍历所用的服务器的最小值  然后让后继可以达到的最大值与x2比较。(定1动1）
	
	for (int i = 0; i < n; i++)
	{
		int k1 = (x1 - 1) / nums[i].second + 1;//向上取整
		if (n - (k1 + i)>0)
		{
			int sur = (n  - (k1+i)) * nums[k1 + i].second;
			if (sur >= x2)
			{
				//x1: i~ i+k1-1
				//x2:i+k1~n-1;
				cout << "Yes\n";
				cout << k1 << ' ' << n - (i + k1)<<'\n';
				for (int idx = i; idx < i + k1; idx++) cout << nums[idx].first + 1 << ' ';
				cout << '\n';
				for (int idx = i + k1; idx <= n - 1; idx++)cout << nums[idx].first + 1 << ' ';
				cout << '\n';
				return 0;
			}
		}
		
	}
	//先排x2
	for (int i = 0; i < n; i++)
	{
		int k2 = (x2 - 1) / nums[i].second + 1;//向上取整
		if (n - (k2 + i) > 0)
		{
			int sur = (n - (k2 + i)) * nums[k2 + i].second;
			if (sur >= x1)
			{
				//x2: i~ i+k2-1
				//x1:i+k2~n-1;
				cout << "Yes\n";
				cout << n - (i + k2) << ' ' << k2<<'\n';
				for (int idx = i + k2; idx <= n - 1; idx++)cout << nums[idx].first+1 << ' ';
				cout << '\n';
				for (int idx = i; idx < i + k2; idx++) cout << nums[idx].first+1 << ' ';
				cout << '\n';

				return 0;
			}
		}
	}
	cout << "No\n";
	return 0;
}
