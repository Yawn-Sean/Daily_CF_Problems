def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n, x = MII()
a = [0] + LII()
next_node = [0] * (n + 1)
for i in range(1, n + 1):
    if a[i] != 0:
        next_node[a[i]] = i
curr = x
while a[curr] != 0:
    curr = a[curr]
head_x = curr
k = 0
curr = head_x
while curr != x:
    k += 1
    curr = next_node[curr]
is_next = [False] * (n + 1)
for i in range(1, n + 1):
    if next_node[i] != 0:
        is_next[next_node[i]] = True

other_sizes = []
for u in range(1, n + 1):
    if not is_next[u]:
        if u == head_x:
            continue
        size = 0
        curr = u
        while curr != 0:
            size += 1
            curr = next_node[curr]
        other_sizes.append(size)
dp = 1
for size in other_sizes:
    dp |= dp << size
for j in range(n):
    if (dp >> j) & 1:
        print(k + 1 + j)

