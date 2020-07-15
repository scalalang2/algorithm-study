package main

import (
	"fmt"
	"strconv"
)

var arr [8]int

func main() {
	var N, M int

	fmt.Scanf("%d %d", &N, &M)
	f(0, "", N, M)
}

func f(l int, text string, N int, M int) {
	if l == M {
		fmt.Println(text)
		return
	}

	for i := 0; i < N; i++ {
		if arr[i] == 1 {
			continue
		}

		arr[i] = 1
		f(l+1, text+strconv.Itoa(i+1)+" ", N, M)
		arr[i] = 0
	}
}
