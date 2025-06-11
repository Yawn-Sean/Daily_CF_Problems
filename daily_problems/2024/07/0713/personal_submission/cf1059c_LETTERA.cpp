void solve()
{
    int n;
    cin >> n;
    auto ask = [&](auto self, int n, int x) -> void
    {
        if (n <= 3)
        {
            fo(i, 0, n - 1)
            {
                cout << x << " ";
            }

            cout << n * x << " ";
            return;
        }
        fo(i, 0, n - n / 2)
        {
            cout << x << " ";
        }
        self(self, n / 2, x * 2);
    };
    ask(ask, n, 1);
}
