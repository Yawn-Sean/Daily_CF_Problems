"""
even if n is 1e9, iterate over 2 digits.
ways: 10+(2^9)*(10*9/2)=23050
so just brute force
"""
def main():
    n=II()
    ans=0
    def check(x):
        nonlocal ans
        y=n-x
        if x>y:
            return
        str_y=str(y)
        len_y=len(str_y)
        cc=set()
        for i in range(len_y):
            cc.add(str_y[i])
        if(len(cc)<3):
            debug(x,y)
            ans+=1
    len_n=len(str(n))
    check(0)
    for l in range(1,len_n+1):
        for i in range(1,10):
            ck=int(str(i)*l)
            check(ck)
        lim_s=(1<<l)-1
        for s in range(1,lim_s):
            bits=[(s>>i&1) for i in range(l)]
            debug(bits)
            for x in range(9):
                for y in range(x+1,10):
                    if x==y:
                        continue
                    num="";
                    for i in range(l):
                        num+=(str(x) if bits[i] else str(y))
                    if num[0]=='0':
                        continue
                    #debug(num)
                    check(int(num))
    print(ans)
    return

multi_test = 0
if __name__ == "__main__":
    T = II() if multi_test else 1
    for _ in range(T):
        main()
