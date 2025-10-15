# Submission link: https://codeforces.com/contest/741/submission/326349264
def main():
    n = II()
    perm = LGMI()

    vis = [0] * n
    ans = 1

    for i in range(n):
        if not vis[i]:
            x = i
            c = 0
            while not vis[x]:
                vis[x] = 1
                x = perm[x]
                c += 1
            
            if x != i:
                exit(print(-1))
            
            if c % 2 == 0: c //= 2
            ans = math.lcm(ans, c)

    print(ans)