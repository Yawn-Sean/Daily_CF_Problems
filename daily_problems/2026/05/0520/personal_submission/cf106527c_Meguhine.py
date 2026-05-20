import sys
from bisect import bisect_left
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()


def solve(_case: int) -> int:
    n, m, X = map(int, input().split())
    it = map(int, input().split())

    cnt = [0] * (n + 1)  # 有cnt[x]道被x个人解出来的题
    buc = [0] * (n + 1)  # 为求cnt[x]*x的前缀和的数组
    for x in it:
        cnt[x] += 1
        buc[x] += x
    pre_c = list(accumulate(cnt))
    pre_s = list(accumulate(buc))
    s = pre_s[-1]

    def check(x: int) -> bool:
        rest: int = (s - pre_s[x]) - (m - pre_c[x]) * x
        # print(f"{x=} {rest=}", file=sys.stderr)
        return (n - x) * X >= rest

    return bisect_left(range(n + 1), True, key=check)


if __name__ == "__main__":
    total_cases = int(input())
    print('\n'.join(str(solve(_)) for _ in range(total_cases)))

"""
check(x:int) 的思路
贪心的想, 这 x 人解出了每一道题
那剩余的题:
- buc[1] ~ buc[x] 都会被消耗完, -pre_s[x]
- buc[x+1] ~ . 每道题都会减去 x, -cnt*x == (m-pre_c[x])*x
剩下的人最多做 (n-x)*X 道题
- 这个可以考虑, 尽量把题目平均分配给每一个人
- 相当于在循环数组上, 每次对连续区间+1, 最后判断 最大值<=X
- 发现可以优化, 直接判断 总和<=剩下人能做的最大题数 即可

时间复杂度 O(n)

for x in range(n + 1):
    if check(x):
        # print(f"{x=} IS ANS !!!", file=sys.stderr)
        break
else:
    assert False, "unreachable"
"""
