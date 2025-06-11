from collections import Counter
def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = Counter(a)
    ans = 0
    vis = [False] * (n + 1)
    for x in c:
        if c[x] > 1:
            for i in range(n):
                if not vis[i] and a[i] & x == a[i]:
                    ans += b[i]
                    vis[i] = True
    print(ans)
main()