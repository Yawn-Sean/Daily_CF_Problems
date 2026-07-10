import sys
from collections import Counter
input = sys.stdin.readline
def I():
    return input().strip()
s=I()
cnt=Counter(s)
cnt['1']-=1
cnt['6']-=1
cnt['8']-=1
cnt['9']-=1
prefix_mods={1869:0,1968:1,1689:2,6198:3,1698:4,1986:5,1896:6}
prefix=''
for i in range(9,0,-1):
    prefix+=chr(48+i)*cnt[chr(48+i)]
mod=0
for c in prefix:
    mod=(mod*10+ord(c)-48)%7
mod=mod*10000%7
target=(7-mod)%7
suffix=''
for num,m in prefix_mods.items():
    if m==target:
        suffix=str(num)
        break
zero='0'*cnt['0']
print(prefix+suffix+zero)
