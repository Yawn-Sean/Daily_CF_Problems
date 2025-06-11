import sys
input = sys.stdin.readline
n, q = map(int,input().split())
all_q = []
move = 0
first = 0
for _ in range(q):
    i = list(map(int,input().split()))
    if i[0] == 1:
        move -= i[1]
    else:
        if move % 2 == first % 2:
            first += 1
            
        else:
            first -= 1

ans = [0] * n
for i in range(n):
    if i % 2 == 0:
        ans[(i + first) % n] = i + 1
    else:
        ans[(i - first) % n] = i + 1

ans1 = [0] * n
for i in range(n):
    ans1[i] = ans[(i + move) % n]
print(*ans1)
