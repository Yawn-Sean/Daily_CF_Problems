import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n = II()
p_read = LII()
parent = [-1]*(n + 1)
for i in range(2, n + 1):
    parent[i] = p_read[i - 2]
ans = [1]*(n + 1)
for i in range(2, n + 1):
    ans[parent[i]] = 0
for i in range(n, 1, -1):
    ans[parent[i]]+=ans[i]
print(' '.join(map(str, sorted(ans[1:]))))