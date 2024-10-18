from queue import PriorityQueue
def main():
    n = int(input())
    g = []
    for i in range(n):
        h,w = map(int, input().split())
        h,w = min(h,w), max(h,w)
        g.append((h,w,i))
    g.sort(key=lambda x: (x[0], -x[1]))
    ans = [-2] * n
    cur = 10**9
    idx = -1
    for _,w,i in g:
        if w > cur:
            ans[i] = idx
        else:
            idx = i
            cur = w
    ans = [i+1 for i in ans]
    print(*ans)
    
    

t = int(input())
for _ in range(t):
    main()