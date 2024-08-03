// submission: https://codeforces.com/contest/1031/submission/257499332
void show(vector<int> &v){
    cout << v.size() << endl;
    for (auto x: v){
	cout << x << " ";
    }
    cout << endl;
}
int main()
{
    LL a, b; cin >> a >> b;
    LL sum = a + b;
    vector<int> ret1;
    set<int> st;
    int i = 1;
    LL tot = 0;
    while(true){
	tot += i;
	if (tot > sum)break;
	st.insert(i);
	i++;
    }
    for (; a > 0; ++i){
	auto it = st.upper_bound(a);
	if (it == st.begin())break;
	--it;
	a -= *it;
	ret1.push_back(*it);
	st.erase(it);
    }
    vector<int>ret2(st.begin(), st.end());
    show(ret1);
    show(ret2);
    return 0;
}
