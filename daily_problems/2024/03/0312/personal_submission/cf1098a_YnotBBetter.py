import math


def main():
    n = int(input())
    parent = [-1] + [int(p) - 1 for p in input().split()]
    v_sum = list(map(int, input().split()))

    graph = [[] for _ in range(n)]
    min_child = [math.inf] * n
    for i in range(1, n):
        p = parent[i]
        min_child[p] = min(min_child[p], v_sum[i])
        graph[p].append(i)

    ans = 0
    for cur in range(n):
        v_cur = 0
        if v_sum[cur] == -1:
            if min_child[cur] < math.inf:
                if min_child[cur] < v_sum[parent[cur]]:
                    print(-1)
                    return
                v_cur = min_child[cur] - v_sum[parent[cur]]
            v_sum[cur] = v_sum[parent[cur]] + v_cur
        else:
            v_cur = v_sum[cur] - (v_sum[parent[cur]] if cur > 0 else 0)
        ans += v_cur
    print(ans)


main()
