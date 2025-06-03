# Submission link: https://codeforces.com/contest/222/submission/322598800
def main():
    n, x = MII()
    v1 = LII()
    v2 = LII()

    v1.sort()
    v2.sort()

    ans = 0
    pt = 0

    for i in range(n - 1, -1, -1):
        while pt < n and v1[i] + v2[pt] < x:
            pt += 1
        
        if pt == n: break
        
        ans += 1
        pt += 1

    print(1, ans)