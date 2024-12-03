import math
def main():
    n,m = map(int,input().split())
    cnt = [0] * (n + 1)
    for _ in range(m):
        u, v = map(int,input().split())
        cnt[u] += 1
        cnt[v] += 1

    a = 0
    for i in range(1, n + 1):
        a += cnt[i] * (n - 1 - cnt[i])

    print(math.comb(n, 3) - a // 2)
main()