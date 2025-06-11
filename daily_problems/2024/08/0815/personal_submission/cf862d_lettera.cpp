void solve()
{
    int n;
    cin >> n;
    string s, t;
    s.resize(n);
    t.resize(n);
    fo(i, 0, n)
    {
        s[i] = '0';
        t[i] = '0';
    }
    t[n - 1] = '1';
    int d1, d2;
    cout << "? " << s << "\n";
    cout << flush;
    cin >> d1;
    cout << "? " << t << "\n";
    cout << flush;
    cin >> d2;
    int pos1, pos0;
    if (d1 > d2)
    {
        pos1 = n;

        int l = 1, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2; // midth char is 1
            // cerr<<mid<<"\n";fflush(stdout);
            string t = s;
            fill(begin(t), begin(t) + mid, '1'); // mid  chars become 1
            cout << "? " << t << "\n";
            cout << flush;
            int d;
            cin >> d;
            if (d1 - d == mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        pos0 = l;
    }
    else
    {
        pos0 = n;
        int l = 1, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2; // midth char is 1
            string t = s;
            fill(begin(t), begin(t) + mid, '1'); // mid  chars become 1
            cout << "? " << t << "\n";
            cout << flush;
            int d;
            cin >> d;
            if (d - d1 == mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        pos1 = l;
    }

    cout << "! " << pos0 << " " << pos1 << "\n";
    cout << flush;
}
