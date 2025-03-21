# Submission link: https://codeforces.com/contest/214/submission/311600919
def main():
    n = II()
    cnt = [0] * 10
    total = 0

    for v in MII():
        cnt[v] += 1
        total += v

    def print_answer():
        ans = ''.join(str(x) * cnt[x] for x in range(9, -1, -1))
        if ans[0] == '0': print(0)
        else: print(ans)

    if cnt[0] == 0:
        print(-1)
    elif total % 3 == 0:
        print_answer()
    else:
        for i in range(10):
            if cnt[i] and (total - i) % 3 == 0:
                cnt[i] -= 1
                print_answer()
                exit()
        
        for i in range(10):
            if cnt[i] > 0:
                cnt[i] -= 1
                for j in range(i + 1):
                    if cnt[j] and (total - i - j) % 3 == 0:
                        cnt[j] -= 1
                        print_answer()
                        exit()
                cnt[i] += 1