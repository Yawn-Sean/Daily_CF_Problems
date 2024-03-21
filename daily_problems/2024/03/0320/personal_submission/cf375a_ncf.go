package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func main() { CF375A(os.Stdin, os.Stdout) }

func CF375A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var s string
	fmt.Fscan(in, &s)
	m := map[int]string{2: "1689", 4: "1698", 0: "1869", 6: "1896", 1: "1968", 5: "1986", 3: "6198"}
	mm := map[rune]bool{'1': true, '6': true, '8': true, '9': true}
	ans := strings.Builder{}
	cur := 0
	zeroCount := 0
	for _, e := range s {
		if e == '0' {
			zeroCount += 1
			continue
		}
		b := mm[e]
		if !b {
			ans.WriteRune(e)
			cur = (cur*10 + int(e) - 48) % 7
		} else {
			delete(mm, e)
		}
	}
	cur = cur * 10000 % 7
	ans.WriteString(m[(7-cur)%7])
	ans.WriteString(strings.Repeat("0", zeroCount))
	fmt.Fprintf(out, "%s ", ans.String())
}
