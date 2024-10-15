# 枚举切割
def main():
    def f(x):
        return x * (m // max(1, k - n // x + 2))
    n, m, k = map(int, input().split())
    ans = 0
    for i in range(1, min(n + 1, 40000)):
        ans = max(ans, f(i))
        ans = max(ans, f(n // i))
    print(ans if ans else -1)
main()