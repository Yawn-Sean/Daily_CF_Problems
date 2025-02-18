// https://codeforces.com/problemset/problem/464/A
#include <bits/stdc++.h>
using namespace std;

string larger(string inp, const int p, int chg)
{
    int n = inp.size();
    if (p <= 2 && n > 2)
        return "NO";
    for (int i = chg + 1, j = 0; i < n; i++, j++)
    {
        if (j == 3)
            j = 0;
        inp[i] = 'a' + j;
    }
    for (int i = chg; i >= 0; i--)
    {
        if (inp[i] == 'a' + p - 1)
        {
            inp[i] = 'a';
            continue;
        }
        inp[i] += 1;
        return inp;
    }
    return "NO";
}

int palindromes(string &s)
{
    int n = s.size();
    for (int i = n - 1; i >= 1; i--)
    {
        if (i > 0 && s[i - 1] == s[i + 1])
            return i + 1;
        if (s[i] == s[i - 1])
            return i;
    }
    return -1;
}

int main()
{
    int n, p, ans;
    cin >> n >> p;
    string s;
    cin >> s;
    ans = n - 1;
    while (true)
    {
        s = larger(s, p, ans);
        ans = palindromes(s);
        if (ans != -1)
            continue;
        break;
    }
    printf("%s\n", s.c_str());
    return 0;
}
