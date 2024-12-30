def main(ac=FastIO()):
    """
    question:   https://codeforces.com/problemset/problem/1056/B
    submission: https://codeforces.com/contest/1056/submission/264683700
    """
    n, m = ac.read_list_ints()
    ans = 0 
    for i in range(m):
        for j in range(m):
            if (i ** 2 + j ** 2) % m == 0: 
                ans += ((n - i + m * (i != 0)) // m) * ((n - j + m * (j != 0)) // m)
    ac.st(ans)
