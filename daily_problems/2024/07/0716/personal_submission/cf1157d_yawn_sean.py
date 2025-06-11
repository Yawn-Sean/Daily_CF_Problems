# Submission Link: https://codeforces.com/contest/1157/submission/270784067
def main():
    n, k = MII()

    if n < k * (k + 1) // 2:
        print('NO')
    else:
        n -= k * (k + 1) // 2
        x, y = divmod(n, k)
        ans = list(range(x + 1, x + k + 1))
        
        for i in range(min(y, k - 2)):
            ans[k - 1 - i] += 1
            y -= 1
        
        ans[-1] += y
        for i in range(k - 1):
            if ans[i] * 2 < ans[i + 1]:
                print('NO')
                break
        else:
            print('YES')
            print(*ans)