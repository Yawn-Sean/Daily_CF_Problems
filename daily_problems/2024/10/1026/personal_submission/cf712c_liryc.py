'''
https://codeforces.com/problemset/submission/712/288142142
712C
2024/10/26 Y1
1600
'''
# ref
x, y = map(int, input().split())

a, b = y, y
cnt = 0

while a < x:
    a, b = a + b - 1, a
    cnt += 1

print(cnt + 2)