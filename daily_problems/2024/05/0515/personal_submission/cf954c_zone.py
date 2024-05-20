def main(ac=FastIO()):
    """
    url: 
        question:   https://codeforces.com/problemset/problem/954/C
        submission: https://codeforces.com/contest/954/submission/261069227
    time: 218 ms 
    """
    n = ac.read_int() 
    a = ac.read_list_ints() 
    x, y = 10 ** 9, -1 
    cnt0, cnt1, max_cnt = 0, 0, 0

    def check():
        if y < max_cnt: return False
        for lst, nxt in zip(a[:-1], a[1:]):
            if lst % y == 1: 
                st = [] 
                if lst != 1: st.append(lst - y)
                st.append(lst + y)
                st.append(lst + 1)
                if nxt not in st: return False
            if lst % y == 0: 
                st = [] 
                if lst != 1: st.append(lst - y)
                st.append(lst + y)
                st.append(lst - 1)
                if nxt not in st: return False
        return True

    for lst, nxt in zip(a[:-1], a[1:]):
        if nxt - lst == 1: 
            cnt1 = 0
            cnt0 += 1
            continue
        if nxt - lst == -1: 
            cnt0 = 0 
            cnt1 += 1
            continue 
        max_cnt, cnt0, cnt1 = max(cnt0, cnt1), 0, 0 
        if ~y and abs(nxt - lst) != y or nxt == lst: 
            print("NO")
            return 
        if y == -1: 
            y = abs(nxt - lst)            
    if y == -1: y = 1
    elif not check():
        print("NO")
        return 
    print(f"YES\n{x} {y}")
