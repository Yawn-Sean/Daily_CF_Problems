using namespace std;
int sizetoint(string s)// 编号
{
	if (s == "S") return 0;
	if (s == "M")return 1;
	if (s == "L")return 2;
	if (s == "XL")return 3;
	if (s == "XXL")return 4;
	if (s == "XXXL")return 5;
	if (s == "S,M") return 6;
	if (s == "M,L")return 7;
	if (s == "L,XL")return 8;
	if (s == "XL,XXL")return 9;
	if (s == "XXL,XXXL")return 10;
	return -1;
}
string intosize(int i)
{
	
	vector<string> v = { "S","M","L","XL","XXL","XXXL" };
	return v[i];
}
ostream& operator<<(ostream& output, vector<string> ans)
{
	for (auto s : ans)
	{
		output << s << '\n';
	}
	return output;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> nums(6);
	for (int& x : nums)
	{
		cin >> x;
	}
	int n;
	cin >> n;
	vector<vector<int>> dou(5);// 记录可以穿双号的人
	vector<string> ans(n);//先用来储存所有的人穿的号数
	bool end = false;
	for (int i =0;i<n;i++)
	{	
		if (end)break;
		string& s = ans[i];
		cin >> s;
		int x = sizetoint(s);
		//cout << x;//测试
		if (x > 5)
		{
			dou[x - 6].push_back(i);
		}
		else
		{
			nums[x]--;
			if (nums[x] < 0)
			{
				end = true;
				//cout << "NO";
			}
		}
	}
	if (!end)//单号的都可以分配好
	{
		for (int i = 0; i < 5 && !end; i++)//处理双号
		{
			//先穿小号，再穿大号
			for (int pos : dou[i])
			{
				if (nums[i] > 0)
				{
					nums[i]--;
					ans[pos] = intosize(i);
				}
				else if (nums[i + 1] > 0)
				{
					nums[i + 1]--;
					ans[pos] = intosize(i + 1);
				}
				else end = true;
			}

		}
	}
	if (!end)//输出
	{
		cout << "YES"<<'\n';
		cout << ans;
	}
	else cout << "NO";
	return 0;
}
