/*
 * [문제 5] 1부터 N까지의 합
 *
 * 양의 정수 N을 입력받아 1부터 N까지의 합을 반복문으로 계산하여 출력하시오.
 *
 * 입력: 양의 정수 N
 * 출력: 1 + 2 + ... + N = 합계
 *
 * 예시 입력: 10
 * 예시 출력: 1부터 10까지의 합: 55
 */

#include <stdio.h>

int main(void) {
    int n;

    printf("양의 정수 N을 입력하세요: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("양의 정수를 입력해야 합니다.\n");
        return 1;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("1부터 %d까지의 합: %d\n", n, sum);

    return 0;
}
