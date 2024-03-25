import math
import sys
input = lambda: sys.stdin.readline().strip()

# 当球下落时，可能直接下落到底部，也可能与之前发出的球发生碰撞，是否碰撞可以通过球心距离是否大于直径来判断
# 发射一个球时，可以遍历之前已发射球的位置来判断是否碰撞
# 如果多个球都可能与当前球碰撞，应当优先考虑位置最高的，因此我们可以按 y 值倒序遍历
# 用 SortedList 会报错，换成与所有圆判断后取最大值

n, r = map(int, input().split())
xs = list(map(int, input().split()))

ans = [r] * n
for i, xi in enumerate(xs):
    for j in range(i):
        if abs(xi - xs[j]) > r << 1:
            continue
        ans[i] = max(ans[i], math.sqrt((r << 1) ** 2 - (xi - xs[j]) ** 2) + ans[j])
print(*ans)



