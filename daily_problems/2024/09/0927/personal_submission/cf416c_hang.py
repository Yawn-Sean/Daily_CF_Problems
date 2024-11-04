from queue import PriorityQueue
def main():
    n = int(input())
    g = []
    for _ in range(n):
        c,p = map(int,input().split())
        g.append((c,p))
    k = int(input())
    z = list(map(int,input().split()))
    client = sorted(range(n),key=lambda i:g[i][0])
    server = sorted(range(k),key=lambda i:z[i])
    ans = [-1] * n
    pt = 0
    pq = PriorityQueue()
    for i in server:
        while pt < n and g[client[pt]][0] <= z[i]:
            pq.put(-g[client[pt]][1] * n + client[pt])
            pt += 1
        if pq.qsize() > 0:
            ans[pq.get() % n] = i
    cnt, tot =0,0
    res = []
    for i in range(n):
        if ans[i] != -1:
            cnt += 1
            tot += g[i][1]
            res.append(f'{i+1} {ans[i]+1}')

    print(cnt,tot)
    for i in res:
        print(i) 
    

main()