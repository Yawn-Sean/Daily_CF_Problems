def main():
    n = II()
    persons = ['Kuro', 'Shiro', 'Katie']
    res = []
    for _ in range(3):
        res.append(I())
    score = [0] * 3
    ln = len(res[0])

    def f(st):
        cnt = Counter(st)
        mx = max(cnt.values())
        ans = min(mx + n, ln)
        if mx == ln and n == 1:
            return ln - 1
        return ans


    for i, s in enumerate(res):
        score[i] = f(s)
    mxScore = max(score)
    if score.count(mxScore) > 1:
        return 'Draw'
    for i in range(3):
        if score[i] == mxScore:
            return persons[i]


T = 1
for ii in range(T):
    print(main())
