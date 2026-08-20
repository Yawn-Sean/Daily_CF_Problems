package main

import (
	"fmt"
	"slices"
)

func main() {
	var t int
	fmt.Scan(&t)
	for range t {
		var u, v string
		fmt.Scan(&u, &v)
		ub, vb := 0, 0
		for _, x := range u {
			if x == 'B' {
				ub++
			}
		}
		for _, x := range v {
			if x == 'B' {
				vb++
			}
		}
		if ub%2 != vb%2 {
			fmt.Println("NO")
			continue
		}
		ut, vt := make([]byte, 0), make([]byte, 0)
		for _, x := range u {
			if x == 'A' || x == 'C' {
				if len(ut) > 0 && ut[len(ut)-1] == byte(x) {
					ut = ut[:len(ut)-1]
				} else {
					ut = append(ut, byte(x))
				}
			}
		}
		for _, x := range v {
			if x == 'A' || x == 'C' {
				if len(vt) > 0 && vt[len(vt)-1] == byte(x) {
					vt = vt[:len(vt)-1]
				} else {
					vt = append(vt, byte(x))
				}
			}
		}
		if slices.Equal(ut, vt) {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
