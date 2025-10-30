#include <stdio.h>

int n, m;
long long ans;

int knight[10];
int rook[10];

int abs(int v) {
	return (v > 0) ? v : -v;
}

int valid(int row, int col, char type) {
	for (int i = 0; i < row; i++) {
		if (rook[i] == col) return 0;
		if (knight[i] == col) return 0;
	}

	if (row - 2 >= 0) {
		if (col - 1 >= 0 && knight[row - 2] == col - 1) return 0;
		if (col + 1 < n + m && knight[row - 2] == col + 1) return 0;

		if (type == 'k') {
			if (col - 1 >= 0 && rook[row - 2] == col - 1) return 0;
			if (col + 1 < n + m && rook[row - 2] == col + 1) return 0;
		}
	}

	if (row - 1 >= 0) {
		if (col - 2 >= 0 && knight[row - 1] == col - 2) return 0;
		if (col + 2 < n + m && knight[row - 1] == col + 2) return 0;

		if (type == 'k') {
			if (col - 2 >= 0 && rook[row - 1] == col - 2) return 0;
			if (col + 2 < n + m && rook[row - 1] == col + 2) return 0;
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
		if (valid(row, i, 'k')) {		// place knight at [row][i].
			knight[row] = i;
			rook[row] = -1;
			place(row + 1, q - 1, r);
		}

		if (valid(row, i, 'r')) {		// place rook at [row][i].
			knight[row] = -1;
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
