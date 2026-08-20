package main

import "fmt"

func main() {
	var x, y, z, tx, ty, tz, R float64
	fmt.Scan(&x, &y, &z, &tx, &ty, &tz, &R)
	tx = max(tx, x-tx)
	ty = max(ty, y-ty)
	tz = max(tz, z-tz)
	l, r := 0.0, min(x, y, z)/2
	for range 100 {
		mid := (l + r) / 2
		if (tx-mid)*(tx-mid)+(ty-mid)*(ty-mid)+(tz-mid)*(tz-mid) >= (R+mid)*(R+mid) {
			l = mid
		} else {
			r = mid
		}
	}
	fmt.Println((r + l) / 2)
}
