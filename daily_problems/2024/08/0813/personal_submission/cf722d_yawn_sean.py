# Submission link: https://codeforces.com/contest/722/submission/276021467
def main():
    n = II()
    nums = LII()

    random.shuffle(nums)

    hpq = [-num for num in nums]
    heapify(hpq)

    used = set(nums)

    while True:
        x = -hpq[0]
        target = x
        while target in used:
            target //= 2
        if target == 0: break
        heapreplace(hpq, -target)
        used.remove(x)
        used.add(target)

    print(' '.join(str(-x) for x in hpq))