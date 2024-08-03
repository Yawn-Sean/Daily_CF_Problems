# Submission link: https://codeforces.com/contest/1031/submission/257367635
def main():
    a, b = MII()

    x_a = (math.isqrt(8 * a + 1) - 1) // 2
    chosen_a = list(range(1, x_a + 1))
    a -= sum(chosen_a)

    for i in range(x_a - 1, -1, -1):
        if a == 0: break
        chosen_a[i] += 1
        a -= 1

    to_fill = x_a + 1
    for i in range(x_a):
        if chosen_a[i] != i + 1:
            to_fill = i + 1
            break

    chosen_b = []
    if b >= to_fill:
        chosen_b.append(to_fill)
        b -= to_fill

    for x in count(x_a + 2):
        if b < x: break
        b -= x
        chosen_b.append(x)

    print(len(chosen_a))
    print(' '.join(map(str, chosen_a)))
    print(len(chosen_b))
    print(' '.join(map(str, chosen_b)))