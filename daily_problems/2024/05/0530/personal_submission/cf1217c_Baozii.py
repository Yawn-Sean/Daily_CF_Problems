class Solution:
    def solve(self, s: str) -> int:
        n = len(s)
        pre = [-1] * n
        for i, ch in enumerate(s):
            if s[i] == i: pre[i] = i
            elif i == 0: continue
            else: pre[i] = pre[i - 1]
        ans = 0
        for j in range(n):
            cnt = 0
            for i in range(j, max(-1, j - 20), -1):
                if s[i] != "0":
                    cnt += 1 << (j - i)
                    if cnt <= j - (-1 if i == 0 else pre[i - 1]):
                        ans += 1
        print(ans)


TC = int(input())

def main():
    obj = Solution()
    for _ in range(TC):
        s = input()
        obj.solve(s)

main()
