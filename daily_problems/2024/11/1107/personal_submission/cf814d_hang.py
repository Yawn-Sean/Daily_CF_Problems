import math
def main():
    n = int(input())
    g = []
    for _ in range(n):
        x,y,r = map(int,input().split())
        g.append((x,y,r))
    g.sort(key=lambda x:-x[2])
    def f(i,j):
        return (g[i][0] - g[j][0]) ** 2 + (g[i][1] - g[j][1]) ** 2 <= (g[i][2] - g[j][2]) ** 2
    d = [0] * n
    for i in range(n):
        for j in range(i):
            if f(i,j):
                d[i] += 1
    ans = 0 
    for i in range(n):
        if max(0, d[i] - 1) % 2:
            ans -= g[i][2] ** 2
        else:
            ans += g[i][2] ** 2
    print(ans * math.pi)

main()