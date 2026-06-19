import sys

input = lambda: sys.stdin.readline().rstrip()


def win(is_first: bool) -> None:
    exit(print("Petyr" if is_first else "Varys"))


n, A, B = map(int, input().split())
a = list(map(int, input().split()))
mx, MOD = max(a), min(A, B) + 1
sg, cnt = 0, 0
for x in a:
    if x >= MOD:
        cnt += 1
        sg ^= x % MOD
    else:
        sg ^= x
if A == B:
    win(sg != 0)
elif A > B:
    win(sg != 0 or cnt != 0)
else:
    take = sg ^ (mx % MOD)
    win((cnt == 0 and sg != 0) or (cnt == 1 and A >= take and (mx - take) < MOD))


"""
1. 首先考虑 A == B 的情况
- 此时对于单独的一堆 x 而言, 看 x % (B+1) 即可
- 那对于多堆呢? 套用 Nim 游戏的结论, 看先取模再异或的结果即可
2. 如果 A > B
- 如果 Xor 之和不为 0, 规约到 A == B 的情况, 先手必胜
- 如果 Xor 之和为 0
    - 如果有一堆的个数 >= (B+1), 那么先手第一次取 (B+1) 颗石子, 留给后手必败状态
      先手必胜
    - 否则先手必败
3. 如果 A < B
- 类似于 2 中的结论, 先手需要确保第一步动完后:
    - Xor 之和为 0
    - 任何一堆的个数都 < (A+1)
  才能保证先手必胜
- 如果开局有 >= 2 堆的个数 >= (A+1), 先手必败
- 如果开局全部堆都 < (A+1), 那可以令 B <- A, 规约到 1
- 如果开局恰好有一堆 >= (A+1)
    - 因为 Xor 之和初始唯一, 判断先手取完这么多石子后, 这一堆是否 < (A+1) 即可
"""
