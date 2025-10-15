# Submission link: https://codeforces.com/contest/932/submission/319957744
def main():
    n, a, b = MII()

    for ca in range(0, n // a + 1):
        if (n - a * ca) % b == 0:
            cb = (n - a * ca) // b
            
            ans = []
            
            cur = 1
            for _ in range(ca):
                for i in range(1, a):
                ans.append(cur + i)
                ans.append(cur)
                cur += a
            
            for _ in range(cb):
                for i in range(1, b):
                    ans.append(cur + i)
                ans.append(cur)
                cur += b 
            
            print(*ans)
            
            exit()

    print(-1)