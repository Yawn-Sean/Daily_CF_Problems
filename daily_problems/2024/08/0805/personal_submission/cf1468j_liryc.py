'''
https://codeforces.com/contest/1468/submission/274508898
CF1468J
2024/8/5 Y1
1800
MST
'''

class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
    def check(self, index1: int, index2: int) -> bool:
        return self.find(index1) == self.find(index2)
    def union(self, index1: int,  index2: int):
        self.parent[self.find(index2)] = self.find(index1)
    def find(self, index: int) -> int:
        if self.parent[index] == index:
            return index
        else:
            ans = self.parent[index] = self.find(self.parent[index])
            return ans
        
def init():
    n, m, k = map(int, input().split())
    a = []
    for _ in range(m):
        x, y, s = map(int, input().split())
        a.append((s, x, y))
    return n, m, k, a

def solve(n: int, m: int, k: int, a):
    ans = k * n
    a.sort()
    nc = 1
    overk = False
    uni = UnionFind(n + 1)
    for s, x, y in a:
        if nc == n:
            if overk:
                break
            else:
                ans = min(ans, abs(k - s))
                if s >= k:
                    break
        elif not uni.check(x, y):
            uni.union(x, y)
            nc += 1
            if s >= k:
                if overk:
                    ans += s - k
                else:
                    overk = True
                    ans = s - k
            else:
                ans = min(ans, k - s)
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
