import sys
sys.stdin = open('in.txt', 'r')

n, k = map(int, input().split())

s = input()
t = input()

L = R = res = 0

for i in range(n):
    L = L << 1 | (1 if s[i] == 'b' else 0)
    R = R << 1 | (1 if t[i] == 'b' else 0)
    res += min(R - L + 1, k)

print(res)