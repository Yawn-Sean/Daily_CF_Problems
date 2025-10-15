# Submission link: https://codeforces.com/contest/404/submission/296364186
def main():
    d = {'L': -1, 'R': 1}

    s = I()
    n = len(s)

    l, r = 0, 0
    cur = 0
    for i in range(n - 1):
        cur += d[s[i]]
        if cur < l:
            l = cur
        if cur > r:
            r = cur

    cur += d[s[-1]]
    if cur < l or cur > r:
        print(1)

    elif s[-1] == 'L':
        left, right = 1, n
        while left <= right:
            mid = (left + right) // 2
            l = 0
            cur = 0
            for i in range(n - 1):
                cur += d[s[i]]
                if cur >= mid:
                    cur = mid - 1
                if cur < l:
                    l = cur
            cur += d[s[-1]]
            if cur < l: left = mid + 1
            else: right = mid - 1
        print(right)

    else:
        left, right = -n, -1
        while left <= right:
            mid = (left + right) // 2
            r = 0
            cur = 0
            for i in range(n - 1):
                cur += d[s[i]]
                if cur <= mid:
                    cur = mid + 1
                if cur > r:
                    r = cur
            cur += d[s[-1]]
            if cur > r: right = mid - 1
            else: left = mid + 1
        print(-left)