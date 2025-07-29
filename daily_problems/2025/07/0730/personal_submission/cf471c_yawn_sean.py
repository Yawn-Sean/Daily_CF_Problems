# Submission link: https://codeforces.com/contest/471/submission/331437571
def main():
    n = II()
    
    l, r = 1, 10 ** 9
    while l <= r:
        mid = (l + r) // 2
        if (n + mid) // 3 >= (mid + 1) * mid // 2:
            l = mid + 1
        else:
            r = mid - 1
    
    print((r - (3 - n % 3)) // 3 + 1)