# https://codeforces.com/contest/331/submission/296865950
class BIT:
    def __init__(self, n):
        self.tree = [0]*(n + 1)

    def add(self, i, v):
        while i < len(self.tree):
            self.tree[i] += v
            i += i & -i

    def query(self, i):
        ans = 0
        while i:
            ans += self.tree[i]
            i &= i - 1
        return ans


n = RI()
a = [0] + RILIST()
m = RI()
# pos = {e: i for i, e in enumerate(a[1:], 1)}
# 用dict会tle
pos = [0]*(n + 1)
for i in range(1, n + 1):
    pos[a[i]] = i

tree = BIT(n)

# tree.query(x) 表示的是[1, x]包含的转折点数量，也就是删除[1,x]需要的次数 - 1
for i in range(1, n):
    if pos[i] > pos[i + 1]:
        tree.add(i + 1, 1)
ans = []

for _ in range(m):
    t, l, r = RII()
    if t == 1:
        ans.append(tree.query(r) - tree.query(l) + 1)
    else:
        if a[l] > a[r]:
            l, r = r, l
        if a[l] > 1 and pos[a[l] - 1] > pos[a[l]]:
            tree.add(a[l], -1)
        if a[l] < n and pos[a[l]] > pos[a[l] + 1]:
            tree.add(a[l] + 1, -1)

        if a[l] + 1 < a[r] and pos[a[r] - 1] > pos[a[r]]:
            tree.add(a[r], -1)
        if a[r] < n and pos[a[r]] > pos[a[r] + 1]:
            tree.add(a[r] + 1, -1)
        pos[a[l]], pos[a[r]] = pos[a[r]], pos[a[l]]
        a[l], a[r] = a[r], a[l]
        l, r = r, l
        if a[l] > 1 and pos[a[l] - 1] > pos[a[l]]:
            tree.add(a[l], 1)
        if a[l] < n and pos[a[l]] > pos[a[l] + 1]:
            tree.add(a[l] + 1, 1)

        if a[l] + 1 < a[r] and pos[a[r] - 1] > pos[a[r]]:
            tree.add(a[r], 1)
        if a[r] < n and pos[a[r]] > pos[a[r] + 1]:
            tree.add(a[r] + 1, 1)

print('\n'.join(map(str, ans)))
