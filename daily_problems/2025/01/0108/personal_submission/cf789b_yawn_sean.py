# Submission link: https://codeforces.com/contest/789/submission/300099963
def main():
    b1, q, l, m = MII()
    nums = LII()
    rnd = random.getrandbits(20)

    vis = {v + rnd for v in nums}

    if abs(b1) > l: print(0)
    elif b1 == 0: print(0 if b1 + rnd in vis else 'inf')
    elif q == 1: print(0 if b1 + rnd in vis else 'inf')
    elif q == -1: print(0 if b1 + rnd in vis and -b1 + rnd in vis else 'inf')
    elif q == 0:
        if rnd in vis: print(0 if b1 + rnd in vis else 1)
        else: print('inf')
    else:
        cnt = 0
        while abs(b1) <= l:
            if b1 + rnd not in vis:
                cnt += 1
            b1 *= q
        print(cnt)