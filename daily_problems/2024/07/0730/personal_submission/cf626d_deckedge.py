
def solve():
    n = II()
    a = LII()
    cnt = [0] * 5000
    a.sort()
    for i in range(n):
        for j in range(i):
            cnt[a[i] - a[j]] += 1
    cnt2 = [0] * 5000
    for i in range(5000):
        for j in range(5000):
            if i + j < 5000:
                cnt2[i + j] += cnt[i] * cnt[j]
    for i in range(1, 5000):
        cnt2[i] += cnt2[i-1]
    res = 0
    for i in range(1, 5000):
        res += cnt[i] * cnt2[i-1]

    print(res / (n * (n - 1) / 2) ** 3)

def main():
    t = 1
    while t:
        solve()
        t -= 1
main()