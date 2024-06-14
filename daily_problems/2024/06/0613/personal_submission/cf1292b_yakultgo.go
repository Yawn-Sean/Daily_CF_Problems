package main

import (
	"bufio"
	"fmt"
	"os"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// 注意到ax,ay都是大于等于2的，因此暴力枚举到第一个大于1e16的点即可，几十个点而已
func solve(in *bufio.Reader, out *bufio.Writer) {
	var x0, y0, ax, ay, bx, by int
	fmt.Fscan(in, &x0, &y0, &ax, &ay, &bx, &by)
	var xs, ys, t int
	fmt.Fscan(in, &xs, &ys, &t)
	type pair struct{ x, y int }
	a := []pair{{x0, y0}}
	for i := 0; ; i++ {
		if a[i].x > 1e16 || a[i].y > 1e16 {
			break
		}
		a = append(a, pair{a[i].x*ax + bx, a[i].y*ay + by})
	}
	n := len(a)
	dis := func(i, j int) int {
		return (a[j].x - a[i].x) + a[j].y - a[i].y
	}
	ans := 0
	for i := 0; i < n; i++ {
		for j := 0; j <= i; j++ {
			for k := i; k < n; k++ {
				if abs(a[i].x-xs)+abs(a[i].y-ys)+dis(j, k)+min(dis(j, i), dis(i, k)) <= t {
					ans = max(ans, k-j+1)
				}
			}
		}
	}
	fmt.Fprintln(out, ans)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
