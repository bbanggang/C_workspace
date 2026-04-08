/*
 * [문제 7] 피보나치 수열 출력
 *
 * 양의 정수 N을 입력받아 피보나치 수열의 첫 N개 항을 출력하시오.
 * 피보나치 수열: 1, 1, 2, 3, 5, 8, 13, 21, ...
 * (F(1)=1, F(2)=1, F(n)=F(n-1)+F(n-2))
 *
 * 예시 입력: 8
 * 예시 출력: 1 1 2 3 5 8 13 21
 */

#include <stdio.h>

int main(void) {
    int n;

    printf("항의 개수를 입력하세요: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("양의 정수를 입력해야 합니다.\n");
        return 1;
    }

    long long a = 1, b = 1;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%lld", a);
        } else if (i == 2) {
            printf(" %lld", b);
        } else {
            long long next = a + b;
            a = b;
            b = next;
            printf(" %lld", b);
        }
    }
    printf("\n");

    return 0;
}
