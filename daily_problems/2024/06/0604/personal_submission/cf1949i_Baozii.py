from collections import deque

class Solution:
    def solve(self, n: int, disks: list[list[int]]) -> bool:
        def connected(d1, d2):
            x1, y1, r1 = d1
            x2, y2, r2 = d2
            return (x1 - x2) ** 2 + (y1 - y2) ** 2 == (r1 + r2) ** 2
        graph = [[] for _ in range(n)]
        for i in range(n):
            for j in range(i + 1, n):
                if connected(disks[i], disks[j]):
                    graph[i].append(j)
                    graph[j].append(i)
        for i in range(n):
            if not graph[i]:
                return True
        def bfs(root, op):
            seen = {root: op}
            q = deque([(root, op)])
            cur = 0
            while q:
                for _ in range(len(q)):
                    u, _op = q.popleft()
                    cur += _op
                    for v in graph[u]:
                        if v in seen :
                            if seen[v] != -_op:
                                return False
                            continue
                        seen[v] = -_op
                        q.append((v, -_op))
            return cur < 0

        s = set(range(n))
        while s:
            root = s.pop()
            if bfs(root, 1) or bfs(root, -1):
                return True
        return False

TC = 1

def main():
    obj = Solution()
    for _ in range(TC):
        n = int(input())
        disks = list(list(map(int, input().split())) for _ in range(n))
        print("YES" if obj.solve(n, disks) else "NO")

main()
