n = int(input())
b = list(map(int, input().split()))

two = [0] * 60
for x in b:
    now = (x & -x).bit_length() - 1
    two[now] += 1

ans_1 = max(two)
k = two.index(max(two))
t = 1 << k
ans = []
for x in b:
    if (x & -x) != t:
        ans.append(x)
print(n - ans_1)
print(*ans)
