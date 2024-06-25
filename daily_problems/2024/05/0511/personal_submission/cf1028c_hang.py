def main():
    n = int(input())
    xl,xr,yl,yr = [],[],[],[]
    for i in range(n):
        a,b,c,d = map(int,input().split())
        xl.append(a)
        xr.append(c)
        yl.append(b)
        yr.append(d)
    pre_xl_mx = xl.copy()
    pre_yl_mx = yl.copy()

    pre_xr_mn = xr.copy()
    pre_yr_mn = yr.copy()

    for i in range(1, n):
        pre_xl_mx[i] = max(pre_xl_mx[i], pre_xl_mx[i-1])
        pre_yl_mx[i] = max(pre_yl_mx[i], pre_yl_mx[i-1])
        pre_xr_mn[i] = min(pre_xr_mn[i], pre_xr_mn[i-1])
        pre_yr_mn[i] = min(pre_yr_mn[i], pre_yr_mn[i-1])
    suf_xl_mx = xl.copy()
    suf_yl_mx = yl.copy()
    suf_xr_mn = xr.copy()
    suf_yr_mn = yr.copy()
    for i in range(n-2, -1, -1):
        suf_xl_mx[i] = max(suf_xl_mx[i], suf_xl_mx[i+1])
        suf_yl_mx[i] = max(suf_yl_mx[i], suf_yl_mx[i+1])
        suf_xr_mn[i] = min(suf_xr_mn[i], suf_xr_mn[i+1])
        suf_yr_mn[i] = min(suf_yr_mn[i], suf_yr_mn[i+1])
    for i in range(1, n-1):
        if max(pre_xl_mx[i-1], suf_xl_mx[i+1]) <= min(pre_xr_mn[i-1], suf_xr_mn[i+1]) and max(pre_yl_mx[i-1], suf_yl_mx[i+1]) <= min (pre_yr_mn[i-1], suf_yr_mn[i+1]):
            print(max(pre_xl_mx[i-1], suf_xl_mx[i+1]),max(pre_yl_mx[i-1], suf_yl_mx[i+1]))
            return
    if suf_xl_mx[1] <= suf_xr_mn[1] and suf_yl_mx[1] <= suf_yr_mn[1]:
        print(suf_xl_mx[1],suf_yl_mx[1])
        return
    print(pre_xl_mx[n-2], pre_yl_mx[n-2])
    return
main()