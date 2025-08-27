#include<stdio.h>
#define maxn 505
int main() {
	int n;
	scanf("%d", &n);
	int arr[maxn];
	for (int i = 1;i <= n;i++) scanf("%d", &arr[i]);
	int q;
	scanf("%d", &q);
	int cnt[maxn];
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int ans = arr[l];
		for (int i = l;i <= r;i++) {
			cnt[arr[i]]++;
			if (cnt[arr[i]] > cnt[ans] || (cnt[arr[i]] == cnt[ans] && arr[i] < ans))
				ans = arr[i];
		}
		printf("%d\n", ans);
		for (int i = l;i <= r;i++)	cnt[arr[i]]--;
	}
	return 0;
}