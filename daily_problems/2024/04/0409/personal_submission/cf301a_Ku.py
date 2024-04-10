import  sys
import bisect
n = int(input())
li = list(map(int,input().split()))
opt = [abs(x) for x in li]
li.sort()
opt.sort()
q = bisect.bisect_left(li,0)  #q表示原数组中有多少个负数
if q % 2 == 0:
    print(sum(opt))
else:
    if n % 2 == 1:
        print(sum(opt))  
    else:
        print(sum(opt) - 2 * opt[0])  
