
# sys.setrecursionlimit(100000)
# start-----------------------------------------------------

def main():
    n,q,m = map(int,input().split())
    a = list(map(int,input().split()))
    a = [0] + a
    queries = []
    while q:
        q -= 1
        t,l,r = map(int,input().split())
        queries.append((t,l,r))

    b = list(map(int,input().split()))
    queries.reverse()
    ans = []
    for idx in b:
        for t,l,r in queries:
            if t == 1:
                if l < idx <= r:
                    idx = idx - 1
                elif idx == l:
                    idx = r
            else:
                if l <= idx <= r:
                    idx = r - idx + l
        ans.append(a[idx])
    print(*ans) 

main()




# end-------------------------------------------------------