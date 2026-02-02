n = int(input())
a = [0] + list(map(int, input().split()))
s = [0] * (n + 1)

def query(l, r) -> int:
    if r <= l + 1: return 0
    return min(a[l], a[r]) * (r - 1 - l) - (s[r - 1] - s[l])


def uuz():
    for i in range(1, n + 1): s[i] = s[i - 1] + a[i]
    sk = []
    ans = 0
    for i in range(1, n + 1):
        while len(sk) and a[i] > a[sk[-1]]: sk.pop()
        if len(sk): ans = max(ans, query(sk[-1], i))
        sk.append(i)

    a[1: n + 1] = reversed(a[1: n + 1])
    return ans


print(max(uuz(), uuz()))
