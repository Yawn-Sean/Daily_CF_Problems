# Submission link: https://codeforces.com/contest/360/submission/300217887
def main():
    n, m = MII()
    inf = 10 ** 9

    ops = []
    for _ in range(m):
        ops.append(tuple(MII()))

    cur_diff = [0] * n
    ans = [inf] * n

    for i in range(m):
        if ops[i][0] == 1:
            for j in range(ops[i][1] - 1, ops[i][2]):
                cur_diff[j] += ops[i][3]
        else:
            for j in range(ops[i][1] - 1, ops[i][2]):
                ans[j] = fmin(ans[j], ops[i][3] - cur_diff[j])

    tmp = ans[:]
    for i in range(m):
        if ops[i][0] == 1:
            for j in range(ops[i][1] - 1, ops[i][2]):
                tmp[j] += ops[i][3]
        else:
            v = -inf
            for j in range(ops[i][1] - 1, ops[i][2]):
                v = fmax(v, tmp[j])
            if v != ops[i][3]:
                exit(print('NO'))

    print('YES')
    print(' '.join(map(str, ans)))