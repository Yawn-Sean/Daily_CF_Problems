# Submission link: https://codeforces.com/contest/1270/submission/258628225
def main():
    def query(*args):
        print('?', *args, flush=True)
        return MII()

    n, k = MII()
    cnt = Counter()

    for j in range(1, k + 2):
        idx, val = query(*(i for i in range(1, k + 2) if i != j))
        cnt[val] += 1

    print('!', cnt[max(cnt)])