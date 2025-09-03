#include <stdio.h>

int n, m, K;
long long ans, sum;

int map[10][10];
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
		if (sum <= K)
			ans++;

		return;
	}

	for (int i = 0; i < n + m; i++) {
		if (valid(row, i, 'q')) {		// place queen at [row][i].
			queen[row] = i;
			rook[row] = -1;

			sum += map[row][i];
			place(row + 1, q - 1, r);
			sum -= map[row][i];
		}

		if (valid(row, i, 'r')) {		// place rook at [row][i].
			queen[row] = -1;
			rook[row] = i;

			sum += map[row][i];
			place(row + 1, q, r - 1);
			sum -= map[row][i];
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d", &n, &m, &K);
		ans = 0;

		for (int i = 0; i < n + m; i++) {
			for (int k = 0; k < n + m; k++) {
				scanf("%d", &map[i][k]);
			}
		}

		place(0, n, m);

		printf("%lld\n", ans);
	}
}
