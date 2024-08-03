import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    m, n = lii()
    arr1 = lii()
    arr1.sort()
    arr2 = lii()
    arr2.sort(reverse=True)
    return sum(max(y-x, 0) for x, y in zip(arr1, arr2))

print(solve())