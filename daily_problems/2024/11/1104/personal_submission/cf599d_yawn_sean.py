# Submission link: https://codeforces.com/contest/599/submission/289843484
def main():
    x = II()

    ans = []

    for mi in range(1, 2 * 10 ** 6 + 1):
        a = mi * (mi + 1) * (2 * mi + 1) // 6
        b = mi * (mi + 1) // 2
        
        if x >= a and (x - a) % b == 0:
            w, h = mi, mi + (x - a) // b
            ans.append((w, h))
            if w != h:
                ans.append((h, w))

    ans.sort()
    print(len(ans))
    print('\n'.join(f'{x} {y}' for x, y in ans))