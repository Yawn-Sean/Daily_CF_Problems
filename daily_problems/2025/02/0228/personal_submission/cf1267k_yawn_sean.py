# Submission link: https://codeforces.com/contest/1267/submission/308211573
def main():
    t = II()
    outs = []

    fac = [1] * 20
    for i in range(1, 20):
        fac[i] = fac[i - 1] * i

    for _ in range(t):
        k = II()
        
        cnt = [0] * 20
        length = 0
        
        for i in range(1, 21):
            cnt[k % i] += 1
            length = i
            
            k //= i
            if k == 0:
                break
        
        ans = 0
        
        to_divide = 1
        res = 1
        cur = 0
        
        for i in range(length):
            to_divide *= fac[cnt[i]]
            cur += cnt[i]
            res *= cur
            cur -= 1

        ans += res // to_divide
        
        if cnt[0]:
            cnt[0] -= 1
            length -= 1
            
            to_divide = 1
            res = 1
            cur = 0
        
            for i in range(length):
                to_divide *= fac[cnt[i]]
                cur += cnt[i]
                res *= cur
                cur -= 1
        
            ans -= res // to_divide
        
        outs.append(ans - 1)

    print('\n'.join(map(str, outs)))