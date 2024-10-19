import io, os, sys
input = lambda: sys.stdin.readline().strip()
def main():
    n = int(input())
    ans = 0
    for i in range(n):
        g = list(map(int, input().split()))
        ans ^= g[i]
    q = int(input())
    res = []
    for _ in range(q):
        op = input()
        if op[0] == '3':
            res.append(ans)
        else:
            ans ^= 1
    print(''.join(str(x) for x in res))

main()