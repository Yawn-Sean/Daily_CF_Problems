from math import inf
def main():
    n = int(input())
    k = n.bit_length()
    t0 = [[0] * k for _ in range(n)]
    t1 = [[0] * k for _ in range(n)]
    for bit in range(k):
        tmp = [i for i in range(1, n + 1) if i >> bit & 1 == 0]
        print(len(tmp))
        print(*tmp, flush=True)
        w = list(map(int, input().split()))
        for j in range(n):
            t0[j][bit] = w[j]
        
        tmp = [i for i in range(1, n + 1) if i >> bit & 1 == 1]
        print(len(tmp))
        print(*tmp, flush=True)
        w = list(map(int, input().split()))
        for j in range(n):
            t1[j][bit] = w[j]
    ans = [inf] * n
    for i in range(n):
        for bit in range(k):
            if (i + 1) >> bit & 1:
                ans[i] = min(ans[i], t0[i][bit])
            else:
                ans[i] = min(ans[i], t1[i][bit])
    print(-1)
    print(*ans, flush=True)
main()