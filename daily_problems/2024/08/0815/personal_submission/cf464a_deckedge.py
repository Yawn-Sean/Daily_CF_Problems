def solve():
    n, p = MII()
    idx = n - 1
    a = [ord(c) - ord('a') for c in I()]
    def is_vailed(i):
        if i >= 1 and a[i] == a[i - 1]:
            return False
        if i >= 2 and a[i] == a[i - 2]:
            return False
        return True
    while True:
        if idx == n:
            print(''.join(chr(x + ord('a')) for x in a))
            break
        elif idx < 0:
            print('NO')
            break
        elif a[idx] == p - 1:
            a[idx] = -1
            idx -= 1
        else:
            a[idx] += 1
            if is_vailed(idx):
                idx += 1
def main():
    t = 1
    while t:
        solve()
        t -= 1
main()