import sys
sys.stdin = open('in.txt', 'r')

n, k = map(int, input().split())

s = input()
t = input()

res = 0
diff = 0
for i in range(n):
    diff = diff * 2 + (ord(t[i]) - ord(s[i]))
    res += min(diff + 1, k)
    if diff + 1 >= k:
        res += (n - i - 1) * k
        break
print(res)
