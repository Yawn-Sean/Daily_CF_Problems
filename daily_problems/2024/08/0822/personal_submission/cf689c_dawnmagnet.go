package main

import (
	"bufio"
	. "fmt"
	"os"
)

var (
	in  *bufio.Reader
	out *bufio.Writer
)
var k int64

func check(n int64) int64 {
	res := int64(0)
	for x := int64(2); x*x*x <= n; x++ {
		res += n / (x * x * x)
	}
	return res
}
func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()
	Fscan(in, &k)
	l := int64(0)
	r := int64(1e18)
	for l < r {
		mid := (l + r) / 2
		if check(mid) >= k {
			r = mid
		} else {
			l = mid + 1
		}
	}
	if check(l) == k {
		Fprint(out, l)
	} else {
		Fprint(out, -1)
	}

}
