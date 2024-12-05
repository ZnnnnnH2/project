#include<cstdio>
#include<iostream>

using namespace std;

int main() {
	int ma[101][101][3];
	int ma2[101][101][3];
	int m, n;
	scanf("%d %d\n", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(j!=n) {
				scanf("R %d G %d B %d ", &ma[i][j][0], &ma[i][j][1], &ma[i][j][2]);
			} else {
				scanf("R %d G %d B %d", &ma[i][j][0], &ma[i][j][1], &ma[i][j][2]);
			}
//		if(i!=m) {
//
		}
//			printf("%d\n",i);
		if(i!=m) {
			scanf("\n");
		}

	}
	for (int i = 1; i <= m; i++) {
		printf("%d",i);
		for (int j = 1; j <= n; j++) {
			printf("R %d G %d B %d ", ma[i][j][0], ma[i][j][1], ma[i][j][2]);
		}
		printf("\n");
	}
	printf("\n");
	int tot = 1;
	while (tot > 0) {
		tot = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (ma[i][j][0] == 0 and ma[i][j][1] == 0 and ma[i][j][2] == 0) {
					int count = 0;
					if (!(ma[i - 1][j][0] == 0 and ma[i - 1][j][1] == 0 and ma[i - 1][j][2] == 0)) {
						for (int k = 0; k <= 2; k++) {
							ma[i][j][k] += ma[i - 1][j][k];
						}
						count++;
					}
					if (!(ma[i + 1][j][0] == 0 and ma[i + 1][j][1] == 0 and ma[i + 1][j][2] == 0)) {
						for (int k = 0; k <= 2; k++) {
							ma[i][j][k] += ma[i + 1][j][k];
						}
						count++;
					}
					if (!(ma[i][j - 1][0] == 0 and ma[i][j - 1][1] == 0 and ma[i][j - 1][2] == 0)) {
						for (int k = 0; k <= 2; k++) {
							ma[i][j][k] += ma[i][j - 1][k];
						}
						count++;
					}
					if (!(ma[i][j + 1][0] == 0 and ma[i][j + 1][1] == 0 and ma[i][j + 1][2] == 0)) {
						for (int k = 0; k <= 2; k++) {
							ma[i][j][k] += ma[i][j + 1][k];
						}
						count++;
					}
					if (count > 0) {
						for (int k = 0; k <= 2; k++) {
							ma[i][j][k] = (ma[i][j][k] + 1) / count;
						}
						tot++;
					}
				}
			}
			for (int i = 1; i <= m; i++) {
				printf("%d",i);
				for (int j = 1; j <= n; j++) {
					printf("R %d G %d B %d ", ma[i][j][0], ma[i][j][1], ma[i][j][2]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	for (int i = 1; i <= m; i++) {
//		printf("%d",i);
		for (int j = 1; j <= n; j++) {
			printf("R %d G %d B %d ", ma[i][j][0], ma[i][j][1], ma[i][j][2]);
		}
		printf("\n");
	}
	return 0;
}

