from collections import Counter
def q(*args):
    print('?',*args,flush=True)
    return map(int,input().split())
def main():
    n, k = map(int,input().split())
    cnt = Counter()
    for j in range(1, k + 2):
        pos,val = q(*(i for i in range(1,k + 2) if i != j))
        cnt[val] += 1
    print('!', cnt[max(cnt)])
    # print(cnt)
    # print(max(cnt))
main()