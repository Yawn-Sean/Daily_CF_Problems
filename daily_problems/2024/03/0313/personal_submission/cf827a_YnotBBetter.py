import collections
import sys
import traceback


def my_solution():
    """
    1091ms 251MB
    """
    n = int(input())
    pos_str = collections.defaultdict(str)
    ans_l = 0
    for _ in range(n):
        line = input().split()
        for idx in line[2:]:
            if len(line[0]) > len(pos_str[int(idx)-1]):
                pos_str[int(idx)-1] = line[0]
        ans_l = max(ans_l, int(line[-1]) + len(line[0]) - 1)

    ans = ["a"] * ans_l
    l, r = 0, -1
    while r < ans_l - 1:
        while l in pos_str and l + len(pos_str[l]) > r + 1:
            ans[r+1] = pos_str[l][r-l+1]
            r += 1

        l += 1
        r = max(l-1, r)
    print("".join(ans))


class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n
        self.max_v = list(range(n))

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return
        if self.size[px] > self.size[py]:
            px, py = py, px
        self.p[px] = py
        self.size[py] += self.size[px]
        self.max_v[py] = max(self.max_v[py], self.max_v[px])

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]


def yawn_solution1():
    """
    1559ms 243MB
    """
    try:
        n = int(input())
        pos_str = collections.defaultdict(str)
        ans_l = 0
        for _ in range(n):
            line = input().split()
            for idx in line[2:]:
                if len(line[0]) > len(pos_str[int(idx) - 1]):
                    pos_str[int(idx) - 1] = line[0]
            ans_l = max(ans_l, int(line[-1]) + len(line[0]) - 1)

        uf = UnionFind(ans_l + 1)
        ans = ["a"] * ans_l
        for i, s in pos_str.items():
            j = uf.max_v[uf.find(i)]
            while j - i < len(s):
                ans[j] = s[j - i]
                uf.union(j, j + 1)
                j = uf.max_v[uf.find(j)]
        print("".join(ans))
    except Exception as e:
        traceback.print_exc(file=sys.stdout)


def yawn_solution2():
    """
    1528ms 211MB
    """
    try:
        n = int(input())
        strs = []
        pos_str = dict()
        ans_l = 0
        for _ in range(n):
            line = input().split()
            si = len(strs)
            strs.append(line[0])

            for idx in line[2:]:
                idx = int(idx) - 1
                if idx not in pos_str or len(line[0]) > len(strs[pos_str[idx]]):
                    pos_str[idx] = si
            ans_l = max(ans_l, int(line[-1]) + len(line[0]) - 1)

        uf = UnionFind(ans_l + 1)
        ans = ["a"] * ans_l
        for i, si in pos_str.items():
            s = strs[si]
            j = uf.max_v[uf.find(i)]
            while j - i < len(s):
                ans[j] = s[j - i]
                uf.union(j, j + 1)
                j = uf.max_v[uf.find(j)]
        print("".join(ans))
    except Exception as e:
        traceback.print_exc(file=sys.stdout)


def yawn_solution3():
    """
    1543ms 192MB
    """
    try:
        n = int(input())
        strs = []
        indices = []
        ans_l = 0
        for _ in range(n):
            line = input().split()
            strs.append(line[0])
            indices.append([int(i)-1 for i in line[2:]])
            ans_l = max(ans_l, indices[-1][-1] + len(strs[-1]))

        uf = UnionFind(ans_l + 1)
        ans = ["a"] * ans_l
        for idx in range(n):
            s = strs[idx]
            for i in indices[idx]:
                j = uf.max_v[uf.find(i)]
                while j - i < len(s):
                    ans[j] = s[j - i]
                    uf.union(j, j + 1)
                    j = uf.max_v[uf.find(j)]
        print("".join(ans))
    except Exception as e:
        traceback.print_exc(file=sys.stdout)


# my_solution()
# yawn_solution1()
# yawn_solution2()
yawn_solution3()
