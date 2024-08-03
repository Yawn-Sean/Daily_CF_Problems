# Submission link: https://codeforces.com/contest/863/submission/256985303
def main():
    n = II()
    ls = []
    rs = []
    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r)

    st_range = sorted(range(n), key=lambda x: ls[x] * 2 * 10 ** 9 - rs[x])
    intervals = []
    for i in st_range:
        if len(intervals) > 0 and rs[intervals[-1]] >= rs[i]:
            print(i + 1)
            break
        if len(intervals) > 1 and ls[i] <= rs[intervals[-2]] + 1:
            print(intervals[-1] + 1)
            break
        intervals.append(i)
    else:
        print(-1)