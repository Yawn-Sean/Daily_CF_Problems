
from collections import Counter
def main():
    n = int(input())
    a,b,c = input(), input(), input()
    def opt(s):
        k = len(s)
        cnt = Counter(s).most_common()[0][1]
        if cnt + n <= k:
            return cnt + n
        if cnt == k and n == 1:
            return max(1, cnt - 1)
        return k
    va,vb,vc = opt(a), opt(b), opt(c)
    if va > vb and va > vc:
        print("Kuro")
    
    elif vb > va and vb > vc:
        print("Shiro")
    
    elif vc > va and vc > vb:
        print("Katie")
    
    else:
        print("Draw")

main()