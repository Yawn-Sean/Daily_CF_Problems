import sys
input = lambda: sys.stdin.readline().strip()


# def main():
#     def find(cur, p, depth):
#         for d, x in query[cur]:
#             diff[depth] += x
#             if depth + d + 1 < n:
#                 diff[depth + d + 1] -= x
#
#         ans[cur] = diff[depth] + (ans[p] if p > -1 else 0)
#         for nxt in graph[cur]:
#             if nxt != p:
#                 find(nxt, cur, depth + 1)
#
#         for d, x in query[cur]:
#             diff[depth] -= x
#             if depth + d + 1 < n:
#                 diff[depth + d + 1] += x
#
#     n = int(input())
#     graph = [[] for _ in range(n)]
#     for _ in range(n-1):
#         u, v = map(int, input().split())
#         graph[u-1].append(v-1)
#         graph[v-1].append(u-1)
#
#     query = [[] for _ in range(n)]
#     m = int(input())
#     for _ in range(m):
#         v, d, x = map(int, input().split())
#         query[v-1].append((d, x))
#
#     ans = [0] * n
#     diff = [0] * n
#     find(0, -1, 0)
#     print(*ans)
#
#
# main()

n = int(input())
graph = [[] for _ in range(n)]
for _ in range(n-1):
    u, v = map(int, input().split())
    graph[u-1].append(v-1)
    graph[v-1].append(u-1)

query = [[] for _ in range(n)]
m = int(input())
for _ in range(m):
    v, d, x = map(int, input().split())
    query[v-1].append((d, x))

ans = [0] * n
diff = [0] * n
depth = [-1] * n
depth[0] = 0

val = 0
stack = [0]
while stack:
    cur = stack.pop()
    if cur >= 0:
        stack.append(~cur)
        for d, x in query[cur]:
            diff[depth[cur]] += x
            if depth[cur] + d + 1 < n:
                diff[depth[cur] + d + 1] -= x

        val += diff[depth[cur]]
        ans[cur] = val

        for nxt in graph[cur]:
            if depth[nxt] == -1:
                depth[nxt] = depth[cur] + 1
                stack.append(nxt)

    else:
        cur = ~cur
        val -= diff[depth[cur]]
        for d, x in query[cur]:
            diff[depth[cur]] -= x
            if depth[cur] + d + 1 < n:
                diff[depth[cur] + d + 1] += x

print(' '.join(map(str, ans)))
