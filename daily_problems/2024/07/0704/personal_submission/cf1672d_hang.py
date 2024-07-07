def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    s = [0] * ( n + 1 )
    p = 0
    for x in a:
        if x == b[p]: p += 1
        else: s[x] += 1
        while p > 0 and p < n and b[p] == b[p-1] and s[b[p]]:
            s[b[p]] -= 1
            p += 1
    print('Yes' if p == n else 'No')

t = int(input())
for _ in range(t):
    main()
