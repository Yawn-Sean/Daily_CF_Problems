package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var yh, ya, yd, mh, ma, md int
	fmt.Fscan(in, &yh, &ya, &yd, &mh, &ma, &md)
	var h, a, d int
	fmt.Fscan(in, &h, &a, &d)
	ans := math.MaxInt64
	for j := ya; j <= 200; j++ {
		for k := yd; k <= 100; k++ {
			if j-md <= 0 {
				continue
			}
			round := (mh + j - md - 1) / (j - md)
			damage := round * max(0, ma-k)
			ans = min(ans, (j-ya)*a+(k-yd)*d+max(0, damage-yh+1)*h)
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
