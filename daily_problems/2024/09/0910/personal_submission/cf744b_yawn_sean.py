# Submission link: https://codeforces.com/contest/744/submission/280512527
def main():
    n = II()
    k = n.bit_length()

    saved0 = [[0] * k for _ in range(n)]
    saved1 = [[0] * k for _ in range(n)]

    for bit in range(k):
        tmp = [i for i in range(1, n + 1) if i >> bit & 1 == 0]
        print(len(tmp))
        print(*tmp, flush=True)
        res = LII()
        for j in range(n):
            saved0[j][bit] = res[j]
        
        tmp = [i for i in range(1, n + 1) if i >> bit & 1]
        print(len(tmp))
        print(*tmp, flush=True)
        res = LII()
        for j in range(n):
            saved1[j][bit] = res[j]

    ans = [10 ** 9] * n
    for i in range(n):
        for bit in range(k):
            if (i + 1) >> bit & 1: ans[i] = fmin(ans[i], saved0[i][bit])
            else: ans[i] = fmin(ans[i], saved1[i][bit])

    print(-1)
    print(*ans)