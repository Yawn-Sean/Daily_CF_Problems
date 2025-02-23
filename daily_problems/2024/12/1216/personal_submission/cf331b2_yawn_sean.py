# Submission link: https://codeforces.com/contest/95/submission/296780151
def main():
    n = II()
    nums = LII()

    pos = [0] * (n + 2)
    for i in range(n):
        pos[nums[i]] = i

    pos[0] = -1
    pos[n + 1] = n

    fen = FenwickTree(n + 1)
    for i in range(n + 1):
        if pos[i] > pos[i + 1]:
            fen.add(i, 1)

    q = II()
    outs = []

    for _ in range(q):
        p, x, y = MII()
        if p == 2:
            x -= 1
            y -= 1
            vx = nums[x]
            vy = nums[y]
            to_check = set()
            for i in range(2):
                to_check.add(vx - i)
                to_check.add(vy - i)
            for i in to_check:
                if pos[i] > pos[i + 1]:
                    fen.add(i, -1)
            pos[vx], pos[vy] = pos[vy], pos[vx]
            nums[x], nums[y] = nums[y], nums[x]
            for i in to_check:
                if pos[i] > pos[i + 1]:
                    fen.add(i, 1)
        else:
            outs.append(fen.rsum(x, y - 1) + 1)

    print('\n'.join(map(str, outs)))