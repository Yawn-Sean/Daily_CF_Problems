from sys import *
input = stdin.readline

n = int(input())
arr = list(map(int, input().split()))
t = 0
for x in arr:
    if x < 0:
        t += 1
arr = list(map(abs, arr))
arr.sort()
if t % 2 == 0:
    print(sum(arr))
    exit(0)
elif t % 2 == 1 and n % 2 == 1:
    print(sum(arr))
    exit(0)
else:
    print(sum(arr) - 2 * arr[0])

