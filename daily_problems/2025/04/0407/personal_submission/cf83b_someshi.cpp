int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long k;//n动物数量 k目标检查次数
	cin >> n >> k;
	vector<int> times(n);
	long long total = 0;
	for (int& x : times)
	{
		cin >> x;
		total += x;
	}
	if (total < k) cout << -1;
	else
	{
		int l = 0;
		int r = 1e9;
		long long sm = 0;
		while (l < r)//求第k次处在第几轮 之后
		{
			sm = 0;
			int mid = (l + r - 1) / 2 + 1;
			for (int i : times)
			{
				sm += min(i, mid);
			}
			if (sm < k) l = mid;//最后使用的l 是k次走的完整的几轮
			else r = mid - 1;
		}
		vector<int>tmp;// 记录还留下来的动物
		for (int i = 0; i < n; i++)
		{
			if (times[i] > l) tmp.push_back(i);
			k -= min(times[i], r);//k减到最后 变为最后一轮中需要接待多少个动物
			times[i] -= min(times[i], r);
		}
		for (int i = 0; i < k; i++)//在最后一轮中接待的动物
		{
			times[tmp[i]]--;
		}
		for (int i = k; i < tmp.size(); i++)
		{
			if (times[tmp[i]])cout << tmp[i] + 1 << ' ';
		}
		for (int i = 0; i < k; i++)//在最后一轮接待过的动物 去到了队尾
		{
			if (times[tmp[i]])cout << tmp[i] + 1 << ' ';
		}
		

	}
	return 0;
}
