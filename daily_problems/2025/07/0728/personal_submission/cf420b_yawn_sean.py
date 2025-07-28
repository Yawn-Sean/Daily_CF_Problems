# Submission link: https://codeforces.com/contest/420/submission/331302665
def main():
    n, q = MII()

    ops = [[] for _ in range(n + 1)]

    for i in range(1, q + 1):
        c, idx = LI()
        idx = int(idx)
        
        if c == '+':
            ops[idx].append(i)
        else:
            if len(ops[idx]) == 0: ops[idx].append(0)
            ops[idx].append(-i)

    diff = [0] * (q + 2)

    for i in range(n + 1):
        if len(ops[i]) % 2:
            ops[i].append(-(q + 1))
        
        for j in range(0, len(ops[i]), 2):
            diff[ops[i][j]] += 1
            diff[-ops[i][j + 1]] -= 1

    l = 0
    for i in range(q + 1):
        if diff[i]: l += 1
        diff[i + 1] += diff[i]

    ans = []
    for i in range(1, n + 1):
        if len(ops[i]) == 0 or sum(ops[i]) + l == 0:
            ans.append(i)

    print(len(ans))
    if ans: print(' '.join(map(str, ans)))