def main(ac=FastIO()):
    """
    question:   https://codeforces.com/problemset/problem/1575/K
    submission: https://codeforces.com/contest/1575/submission/264711630
    """
    n, m, k, r, c = ac.read_list_ints()
    x0, y0, x1, y1 = ac.read_list_ints()
    ac.st(pow(k, n * m - r * c * (x0 != x1 or y0 != y1), ac.MOD1))
