# Submission link: https://codeforces.com/contest/439/submission/309000688
def main():
    n, k, p = MII()
    nums = LII()

    odd = []
    even = []

    for v in nums:
        if v & 1: odd.append(v)
        else: even.append(v)

    if len(odd) < k - p:
        print('NO')
    elif (len(odd) - (k - p)) % 2:
        print('NO')
    elif len(even) + (len(odd) - (k - p)) // 2 < p:
        print('NO')
    else:
        print('YES')
        ars = []
        
        for _ in range(k - p):
            ars.append([odd.pop()])
        
        for _ in range(p):
            if even: ars.append([even.pop()])
            else: ars.append([odd.pop(), odd.pop()])
        
        ars[-1].extend(odd)
        ars[-1].extend(even)
        
        for ar in ars:
            print(len(ar), *ar)