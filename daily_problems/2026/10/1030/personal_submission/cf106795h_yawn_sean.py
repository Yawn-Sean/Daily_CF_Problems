# Submission link: https://codeforces.com/gym/106795/submission/396514746
def main(): 
    n, m, k = MII()
    nodes = LGMI()
    
    path = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    dis = [-1] * n
    dis[0] = 0
    
    que = [0]
    
    for u in que:
        for v in path[u]:
            if dis[v] == -1:
                dis[v] = dis[u] + 1
                que.append(v)
    
    bs = [0] * n
    
    for i in range(k):
        bs[nodes[i]] = 1 << i
    
    for i in reversed(que):
        for j in path[i]:
            if dis[j] == dis[i] + 1:
                bs[i] |= bs[j]
    
    print(max(dis[i] for i in range(n) if bs[i] == bs[0]))