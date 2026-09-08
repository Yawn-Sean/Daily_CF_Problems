package main

import (
	"bufio"
	"cmp"
	"fmt"
	"os"
)

func main() {
	var s, t string
	var p, q int
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	fmt.Fscan(in, &s, &t, &p, &q)
	if p == 0 || q == 0 {
		fmt.Fprintln(out, "=")
		return
	}
	v1 := s + t
	v2 := t + s
	if cmp.Compare(v1, v2) < 0 {
		fmt.Fprintln(out, "<")
	} else if cmp.Compare(v1, v2) > 0 {
		fmt.Fprintln(out, ">")
	} else {
		fmt.Fprintln(out, "=")
	}
}
