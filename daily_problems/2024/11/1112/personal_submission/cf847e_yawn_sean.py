# Submission link: https://codeforces.com/contest/847/submission/291124120
def main():
    n = II()
    s = I()

    asterisks = []
    packmen = []

    for i in range(n):
        if s[i] == '*':
            asterisks.append(i)
        elif s[i] == 'P':
            packmen.append(i)

    l, r = 0, 2 * 10 ** 5
    k = len(asterisks)

    while l <= r:
        m = (l + r) // 2
        
        pt = 0
        for p in packmen:
            if abs(asterisks[pt] - p) > m:
                continue
            
            left = fmax(0, p - asterisks[pt])
            right = p + fmax((m - left) // 2, m - left * 2)
            
            while pt < k and asterisks[pt] <= right:
                pt += 1
            
            if pt == k:
                break
        
        if pt == k:
            r = m - 1
        else:
            l = m + 1

    print(l)