import bisect
def main():
    n = int(input())
    a = list(map(lambda x: int(x) - 1, input().split()))
    z = [[] for _ in range(n)]
    for i in range(n):
        if i - a[i] >= 0:
            z[a[i]].append(i - a[i])
    ans = []
    for i in range(n):
        for x in reversed(z[i]):
            t = bisect.bisect_right(ans, x)
            if t < len(ans): ans[t] = x
            else: ans.append(x)
    print(len(ans))
    
    

        
main()