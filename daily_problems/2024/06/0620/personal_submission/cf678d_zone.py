def main(ac=FastIO()):
    """
    problem:    https://codeforces.com/problemset/problem/678/D
    submission: https://codeforces.com/contest/678/submission/266511885
    """
    a, b, n, x = ac.read_list_ints()
    if a == 1: 
        ac.st((x + n * b) % ac.MOD1)
    else:
        ac.st((pow(a, n, ac.MOD1) * x % ac.MOD1 + 
              (pow(a, n, ac.MOD1) - 1 + ac.MOD1) % ac.MOD1 * pow(a - 1, -1, ac.MOD1) * b % ac.MOD1) % ac.MOD1)
