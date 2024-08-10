package main

import (
	"bufio"
	"fmt"
	"os"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
func solve(in *bufio.Reader, out *bufio.Writer) {
	var l, r, x, y int
	fmt.Fscan(in, &l, &r, &x, &y)
	ans := 0
	check := func(a int) bool {
		b := x * y / a
		return gcd(a, b) == x && l <= b && b <= r && l <= a && a <= r
	}
	for i := 1; i*i <= y; i++ {
		if y%i == 0 {
			if check(i) {
				ans++
			}
			if i*i != y {
				if check(y / i) {
					ans++
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
