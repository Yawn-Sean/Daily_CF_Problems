def main():
    n = int(input())
    t = 1
    ans = []
    def f(x):
        nonlocal t
        if x == 0:
            return
        if x == 1:
            ans.append(t)
        elif x == 2:
            ans.append(t)
            ans.append(t * 2)
        elif x == 3:
            ans.append(t)
            ans.append(t)
            ans.append(t * 3)
        else:
            k = (x + 1) // 2
            x -= k
            for _ in range(k): 
                ans.append(t)
            t *= 2
            f(x)
    f(n)
    print(* ans)
            

main()