#include<stdio.h>
#define maxn 505
int main() {
	int n;
	scanf("%d", &n);
	int arr[maxn];
	for (int i = 1;i <= n;i++)
		scanf("%d", arr + i);    // = scanf("%d",&arr[i])
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int ans = 0, cnt = 0;
		for (int i = 1;i <= 500;i++) {
			int now_cnt = 0;
			for (int j = l;j <= r;j++)
				if (arr[j] == i)
					now_cnt++;
			if (now_cnt > cnt)
				ans = i, cnt = now_cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}
