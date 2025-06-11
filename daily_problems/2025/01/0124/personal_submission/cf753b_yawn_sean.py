# Submission link: https://codeforces.com/contest/753/submission/302682015
def main():
    def query(s):
        print(s, flush=True)
        x, y = MII()
        if x == 4: exit()
        return x, y

    tmp = []
    for i in range(10):
        x, y = query(str(i) * 4)
        tmp.extend(str(i) for _ in range(x + y))

    for v in permutations(tmp):
        query(''.join(v))