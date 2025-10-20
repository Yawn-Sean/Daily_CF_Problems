# -*- coding: UTF-8 -*-
from Yawn_Sean_Template import *

ck=[]
def init():
    pri=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
    len_p=len(pri)
    mask_lim=2**len_p
    for mask in range(1,mask_lim):
        res=1
        for i in range(len_p):
            if mask>>i&1:
                res*=pri[i]
        ck.append(res)
    ck.sort()

def main():
    n=II()
    a=LII()
    s=set()
    for i in range(n):
        s.add(a[i])
    t=list(s)
    m=len(t)
    for _,x in enumerate(ck):
        ok=1
        for i in range(m):
            if math.gcd(t[i],x)==1:
                ok=0
                break
        if ok:
            print(x)
            break
    return

multi_test = 1
if __name__ == "__main__":
    init()
    T = II() if multi_test else 1
    for _ in range(T):
        main()
