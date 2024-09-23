class Solution:
    """
    problem   : https://codeforces.com/problemset/problem/1648/C
    submission: https://codeforces.com/contest/1648/submission/282622576
    """
    def main(ac=FastIO()):
        n, m = ac.read_ints()
        s = ac.read_ints()
        t = ac.read_ints()

        M = 2 * 10 ** 5 + 1 
        cnt = [0] * M  # 记录s中每个数出现个数
        fen = FenwickTree(M)  # 树状数组存的是s中每个小于k个数个数

        for x in s:
            cnt[x] += 1 
            fen.add(x, 1)

        fac = Factorial(n, ac.MOD2)
        # 初始化
        cur = fac.fac(n)
        for v in cnt:
            cur *= fac.fac_inv(v)
            cur %= ac.MOD2
        ans = 0 
        for i, v in enumerate(t):
            if i >= n: 
                # s只能为t的前缀
                ans += 1 
                break 
            cur = cur * fac.inv(n - i) % ac.MOD2  # 除以n-i
            ans += (cur * fen.rsum(0, v - 1)) % ac.MOD2
            ans %= ac.MOD2

            if cnt[v] == 0: break  # 没有相等的，无法继续计算
            cur = cur * cnt[v] % ac.MOD2
            cnt[v] -= 1 
            fen.add(v, -1)
        ac.st(ans % ac.MOD2)
