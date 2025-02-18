# 裴蜀定理 https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/08/0826/solution/cf1147b.md
def main():
    n,m = map(int,input().split())
    g = []
    used = set()
    for _ in range(m):
        a,b = map(lambda x: int(x) - 1,input().split())
        a,b = sorted([a,b])
        g.append((a,b))
        used.add((a,b))
    
    tmp = n
    for i in range(2, n + 1):
        if n % i == 0:
            while n % i == 0:
                n //= i
            x = tmp // i
            for i in range(m):
                nl = (g[i][0] + x) % tmp
                nr = (g[i][1] + x) % tmp
                if nl > nr: nl, nr = nr, nl
                if (nl, nr) not in used:
                    break
            else:
                print('Yes')
                return
    print('No')

main()