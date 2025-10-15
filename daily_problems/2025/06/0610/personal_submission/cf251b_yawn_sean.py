# Submission link: https://codeforces.com/contest/251/submission/323695666
def main():
    n, k = MII()
    p = LGMI()
    target = LGMI()

    q = [0] * n
    for i in range(n):
        q[p[i]] = i

    flg = False
    for i in range(n):
        if target[i] != i:
            flg = True

    if not flg: exit(print('NO'))

    cur = list(range(n))
    for i in range(1, k + 1):
        cur = [p[i] for i in cur]
        if cur == target:
            if (k - i) % 2 == 0 and (i > 1 or k == 1 or q != target):
                exit(print('YES'))
            break

    cur = list(range(n))
    for i in range(1, k + 1):
        cur = [q[i] for i in cur]
        if cur == target:
            if (k - i) % 2 == 0 and (i > 1 or k == 1 or p != target):
                exit(print('YES'))
            break

    print('NO')