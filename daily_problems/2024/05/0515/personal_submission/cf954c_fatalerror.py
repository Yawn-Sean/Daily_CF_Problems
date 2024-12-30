import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n = ii()
    arr = [x-1 for x in lii()]
    y = -1
    for i in range(1, n):
        diff = abs(arr[i] - arr[i-1])
        if diff == 0:
            print('NO')
            return
        elif diff != 1:
            y = diff
            break
    if y == -1:
        print('YES')
        print(10**9, 1)
        return 
    for i in range(1, n):
        r1, c1 = divmod(arr[i], y)
        r2, c2 = divmod(arr[i-1], y)
        if abs(r1-r2) + abs(c1-c2) != 1:
            print('NO')
            return
    print('YES')
    print(10**9, y)

solve()