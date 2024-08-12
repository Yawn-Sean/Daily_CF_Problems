def main():
    n = II()
    Prob = LFI()
    Prob.sort(reverse=True)
    p0, p1 = 1, 0  # 其恰有一个人做对的概率是 p1, 无人做对的概率是 p0
    ans = 0
    for p in Prob:
        p1 = p0 * p + p1 * (1 - p)
        p0 *= 1 - p
        ans = max(ans, p1)
    print(ans)

    return
