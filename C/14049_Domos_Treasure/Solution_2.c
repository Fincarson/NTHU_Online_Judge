#include <stdio.h>

int main() {
	int n, s;
	scanf("%d %d", &n, &s);

	int _list[100];
	for (int i = 0; i < n; i++)
		scanf("%d", &_list[i]);

	int ans = 0;

	// Note that the initial value of variable j is set to i+1, ensuring it remains greater than i, as well as for variables k and l
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (_list[j] >= _list[i])    // make sure that Aj >= Ai
				for (int k = j + 1; k < n; k++) {
					if (_list[k] >= _list[j])    // make sure that Ak >= Aj
						for (int l = k + 1; l < n; l++) {
							if (_list[l] >= _list[k]) {    // make sure that Al >= Ak
								if (_list[i] + _list[j] + _list[k] + _list[l] == s)    // if sum is equal to s
									ans++;
							}
						}
				}
		}
	}

	printf("%d\n", ans);
}