# Submission Link: https://codeforces.com/contest/535/submission/267111058
def main():
    l, t, m = MII()
    left, right = 0, t * m
    while left <= right:
        mid = (left + right) // 2
        if (a + (l - 1) * b + a + (l + mid - 2) * b) * mid // 2 > t * m or a + (l + mid - 2) * b > t:
            right = mid - 1
        else:
            left = mid + 1
    outs.append(l + right - 1 if right > 0 else -1)
