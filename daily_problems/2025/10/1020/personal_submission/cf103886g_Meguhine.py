# -*- coding: UTF-8 -*-
from Yawn_Sean_Template import *
def cmp(a,b):
    i=0
    while 1:
        x=a>>i&1
        y=b>>i&1
        if x==y:
            i+=1
            continue
        return -1 if x>y else 1

def main():
    n=II()
    a=[i for i in range(1,n+1)]
    a.sort(key=cmp_to_key(cmp))
    for i in range(n):
        print(a[i],end=' ')
    return

multi_test = 0
if __name__ == "__main__":
    T = II() if multi_test else 1
    for _ in range(T):
        main()
