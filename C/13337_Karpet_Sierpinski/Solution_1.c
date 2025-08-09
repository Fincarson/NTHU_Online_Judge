#include <stdio.h>

int check(int x, int y, int len) {
	if (len == 0) return 0;
	if (x >= len && x < len * 2 && y >= len && y < len * 2) return 1;
	return check(x % len, y % len, len / 3);
}

int main() {
	int n; scanf("%d", &n);
	int len = 1;
	for (int i = 0; i < n; i++) len *= 3;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) printf("%c", check(i, j, len / 3) ? '#' : '.');
		printf("\n");
	}
	return 0;
}