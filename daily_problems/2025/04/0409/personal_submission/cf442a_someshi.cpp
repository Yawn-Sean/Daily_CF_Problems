using namespace std;
void initmap(unordered_map<char, int>& map)
{
	map['R'] = 1;
	map['G'] = 2;
	map['B'] = 3;
	map['Y'] = 4;
	map['W'] = 5;
}
int popcount(int num) {
	int count = 0;
	while (num) {
		count += num & 1;
		num >>= 1;
	}
	return count;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	vector<int> nums(n);
	unordered_map<char, int> ctoi ;
	initmap(ctoi);
	unordered_set<int>card;//储存不同的卡片
	for (int& i : nums)
	{
		//因为情况个数非常的少 所以可以将每个卡牌编码为一个数
		//为了方便访问 我们用10进制的两位数表示一个卡牌
		//num %10为个位 表示value  
		//num /10为十位 表示color
		string s;
		cin >> s;
		i = 10 * ctoi[s[0]] + (s[1] - '0');
		card.insert(i);
	}
	int ans = 11;//最大为10
	//同理 我们给Borya的所有提示也可以用二进制的5位编码
	for (int mask1 = 0; mask1 < 32; mask1++)// 遍历：在颜色上给了哪几个hint  0代表第一种颜色（如果之前储存card的时候从0开始就可以省很多事，但也不一定）
	{
		
		for (int mask2 = 0; mask2 < 32; mask2++)
		{
			unordered_set<int> marked;// 储存现在可以辨识多少种卡牌 如果颜色已知 值不可知 则一种颜色算作一种 ；颜色未知 值未知 则同一算作一种
			//如果颜色和值都已知 则单独算一种。
			for(int i : card)
			{
				int ct = 0;
				if (mask1 >> (i / 10 - 1) & 1) ct += (i / 10) * 10;
				if (mask2 >> (i % 10 - 1) & 1)ct += i % 10;
				marked.insert(ct);
			}
			if (marked.size() == card.size())
			{
				ans = min(ans, popcount(mask1) + popcount(mask2));
			}
		}
	}
	cout << ans;

	return 0;
}
