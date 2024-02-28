package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1512E(os.Stdin, os.Stdout) }

func CF1512E(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, l, r, s int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		fmt.Fscan(in, &n, &l, &r, &s)
		length := r - l + 1
		ll, rr := 1, n
		for ll <= rr {
			mid := (ll + rr) >> 1
			sm := (mid<<1 + length - 1) * length / 2
			if sm >= s {
				rr = mid - 1
			} else {
				ll = mid + 1
			}
		}
		sm := (ll<<1 + length - 1) * length / 2
		if ll+length-1 > n || sm > s && ll == 1 {
			fmt.Fprintf(out, "-1\n")
			continue
		}
		num := 0
		count := sm - s
		for i := 1; i < l; i++ {
			num = getNextNum(num, ll, length, count)
			fmt.Fprintf(out, "%d ", num)
		}
		cur := count
		for i := ll; i < ll+length; i++ {
			if cur > 0 {
				fmt.Fprintf(out, "%d ", i-1)
				cur--
			} else {
				fmt.Fprintf(out, "%d ", i)
			}
		}
		for i := l + length; i <= n; i++ {
			num = getNextNum(num, ll, length, count)
			fmt.Fprintf(out, "%d ", num)
		}
		fmt.Fprintf(out, "\n")
	}
}
func getNextNum(num, l, length, count int) int {
	if count > 0 {
		if num == l-2 {
			return l + count - 1
		} else if num == l+count-1 {
			return l + length
		}
	} else if num == l-1 {
		return l + length
	}
	return num + 1
}
