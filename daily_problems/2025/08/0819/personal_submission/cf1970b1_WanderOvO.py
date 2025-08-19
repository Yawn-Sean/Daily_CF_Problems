"""
取对角线上所有点，必有两两之间距离是偶数
对于任何一个点，都能找到离自己距离为任何不超过 n 的偶数的点
"""

n = int(input())
a = [0] + list(map(int, input().split()))

print("YES")
for i in range(1, n + 1):
    print(i, i)

for i in range(1, n + 1):
    d = a[i] // 2
    if i > d:
        print(i - d, end=' ')
    else:
        print(i + d, end=' ')
