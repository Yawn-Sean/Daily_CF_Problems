import math
def main():
    n = int(input())
    g = []
    for _ in range(n): 
        x,y = map(int,input().split())
        g.append(math.atan2(y,x))
    g.sort()
    ans = 0
    for i in range(1,n): 
        ans = max(ans,g[i] - g[i-1])
    
    ans = min(2*math.pi - ans, g[-1] - g[0]) / math.pi * 180
    print(ans)
main()