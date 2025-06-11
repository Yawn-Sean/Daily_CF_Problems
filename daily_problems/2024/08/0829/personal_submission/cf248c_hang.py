# 考虑镜面呈像会简单点 https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/08/0829/solution/cf248c.md
def main():
    y1, y2, yw, xb, yb, r = map(int, input().split())
    y1, y2 = 2 * yw - y2 - 2 * r, 2 * yw - y1 - 2 * r
    if r * r * ((yb - y2 + r) ** 2 + xb ** 2) > (y2 - y1 - r) ** 2 * xb ** 2:
        print(-1)
    else:
        print((y2 - yw) * xb / (y2 - r - yb))
main()