# Submission link: https://codeforces.com/contest/916/submission/273639895
def main():
    n, k = MII()
    if n.bit_count() > k:
        print('No')
    else:
        if n < k:
            ma = 1 - (k // n).bit_length()
            ans = [ma] * (n << -ma)
        else:
            l, r = 0, n.bit_length() - 1
            while l <= r:
                m = (l + r) // 2
                cur = n
                cnt = 0
                for i in range(m, -1, -1):
                    v = cur >> i
                    cnt += v
                    cur -= v << i
                if cnt <= k: r = m - 1
                else: l = m + 1
            ans = []
            cur = n
            for i in range(l, -1, -1):
                v = cur >> i
                cur -= v << i
                ans.extend(i for _ in range(v))
        while len(ans) < k:
            x = ans.pop()
            ans.append(x - 1)
            ans.append(x - 1)
        print('Yes')
        print(*ans)