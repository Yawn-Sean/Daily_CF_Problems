# Submission link: https://codeforces.com/contest/1320/submission/307869691
def main():
    n, m = MII()
    path = [[] for _ in range(n)]
    rev_path = [[] for _ in range(n)]

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        rev_path[v].append(u)

    k = II()
    nums = LGMI()

    des = nums[-1]

    dis = [-1] * n
    dis[des] = 0

    que = [0] * n
    l, r = 0, 1
    que[l] = des

    while l < r:
        u = que[l]
        l += 1
        for v in rev_path[u]:
            if dis[v] == -1:
                dis[v] = dis[u] + 1
                que[r] = v
                r += 1

    v1, v2 = 0, 0

    for i in range(k - 1):
        u = nums[i]
        v = nums[i + 1]
        
        if dis[v] >= dis[u]:
            v1 += 1
            v2 += 1
        
        else:
            c = 0
            for x in path[u]:
                if dis[x] < dis[u]:
                    c += 1
            
            if c > 1:
                v2 += 1

    print(v1, v2)