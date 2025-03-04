'''
https://codeforces.com/problemset/submission/923/308903653
'''
# 01字典树
class Trie01Tree:
    def __init__(self, n = 30):
        self.n = n
        self.a = [[0] * 10000000 for _ in range(3)]
        self.lp = 0
    def add(self, num):
        ti = 0
        self.a[2][ti] += 1
        for i in range(self.n - 1, -1, -1):
            c = num >> i & 1
            if self.a[c][ti] == 0:
                self.lp += 1
                self.a[c][ti] = self.lp
            ti = self.a[c][ti]
            self.a[2][ti] += 1
    def popmin(self, num):
        ans, ti = 0, 0
        self.a[2][ti] -= 1
        for i in range(self.n - 1, -1, -1):
            c = num >> i & 1
            flip = 0
            if self.a[c][ti] and self.a[2][self.a[c][ti]]:
                pass # flip = 0
            else:
                flip = 1
            ti = self.a[c ^ flip][ti]
            self.a[2][ti] -= 1
            ans = ans << 1 | (c ^ flip)
        return ans

def solve(n: int, a: list[int], pa: list[int]):
    tt = Trie01Tree()
    for p in pa:
        tt.add(p)
    ans = []
    for x in a:
        ans.append(x ^ tt.popmin(x))
    return ans

