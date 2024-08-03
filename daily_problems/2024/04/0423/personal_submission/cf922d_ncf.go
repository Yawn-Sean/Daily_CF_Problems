package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF922D(os.Stdin, os.Stdout) }

func CF922D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	type union struct {
		a, b int
		c    string
	}
	t := make([]union, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &t[i].c)
		a := 0
		for _, e := range t[i].c {
			if e == 's' {
				a += 1
			}
		}
		t[i].a = a
		t[i].b = len(t[i].c) - a
	}
	sort.Slice(t, func(i, j int) bool {
		return t[i].a*t[j].b > t[i].b*t[j].a
	})
	ans := 0
	cur := 0
	for i := 0; i < n; i++ {
		for _, e := range t[i].c {
			if e == 's' {
				cur += 1
			} else {
				ans += cur
			}
		}
	}
	fmt.Fprintf(out, "%d\n", ans)
}
