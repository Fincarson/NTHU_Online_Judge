#include <stdio.h>

int n, m;
long long ans;

int queen[10];
int rook[10];

int abs(int v) {
	return (v > 0) ? v : -v;
}

int valid(int row, int col, char type) {
	for (int i = 0; i < row; i++) {
		if (queen[i] == col) return 0;
		if (rook[i] == col) return 0;
	}

	for (int i = 0; i < row; i++) {
		if (queen[i] != -1) {
			if (abs(i - row) == abs(queen[i] - col)) return 0;
		}

		if (type == 'q') {
			if (queen[i] != -1) {
				if ((abs(i - row)) == abs(queen[i] - col)) return 0;
			}
			else {
				if ((abs(i - row)) == abs(rook[i] - col)) return 0;
			}
		}
	}

	return 1;
}

void place(int row, int q, int r) {
	if (q < 0 || r < 0) return;
	if (row == n + m) {
		ans++;
		return;
	}

	for (int i = 0; i < n + m; i++) {
		if (valid(row, i, 'q')) {		// place queen at [row][i].
			queen[row] = i;
			rook[row] = -1;
			place(row + 1, q - 1, r);
		}

		if (valid(row, i, 'r')) {		// place rook at [row][i].
			queen[row] = -1;
			rook[row] = i;
			place(row + 1, q, r - 1);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);
		ans = 0;

		place(0, n, m);

		printf("%lld\n", ans);
	}
}