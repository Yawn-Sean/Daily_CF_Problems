int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s[a[i]].insert(i);
    }
    sort(a + 1, a + n + 1);
    long long ans = n; // 最好情况下（非递减），每个元素都要移动一次
    int pos = 1;
    for (int i = 1; i <= n; ++i)
    {
        auto it = s[a[i]].lower_bound(pos); // 找到第一个大于等于pos的元素
        if (it == s[a[i]].end())
        {
            ans += n - i + 1; // 移动到对应的位置i
            pos = 1;
            it = s[a[i]].lower_bound(pos);
        }
        pos = *it;
        s[a[i]].erase(it);
    }
    cout << ans << endl;
    return 0;
}
