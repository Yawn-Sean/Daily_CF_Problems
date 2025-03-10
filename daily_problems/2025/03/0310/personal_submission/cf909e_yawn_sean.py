# Submission link: https://codeforces.com/problemset/submission/909/309690160
def main():
    n, m = MII()
    tags = LII()

    path = [[] for _ in range(n)]
    indegs = [0] * n

    for _ in range(m):
        u, v = MII()
        path[u].append(v)
        indegs[v] += 1

    stk1, stk0 = [], []

    for i in range(n):
        if indegs[i] == 0:
            if tags[i]: stk1.append(i)
            else: stk0.append(i)

    ans = 0
    while stk0 or stk1:
        while stk0:
            u = stk0.pop()
            for v in path[u]:
                indegs[v] -= 1
                if indegs[v] == 0:
                    if tags[v]: stk1.append(v)
                    else: stk0.append(v)
        
        if len(stk1): ans += 1
        
        while stk1:
            u = stk1.pop()
            for v in path[u]:
                indegs[v] -= 1
                if indegs[v] == 0:
                    if tags[v]: stk1.append(v)
                    else: stk0.append(v)

    print(ans)