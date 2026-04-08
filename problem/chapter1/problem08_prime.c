/*
 * [문제 8] 소수 판별 (함수 사용)
 *
 * 양의 정수 N을 입력받아 소수 여부를 판별하는 함수를 작성하고 결과를 출력하시오.
 * 추가로 2부터 N까지의 소수를 모두 출력하시오.
 *
 * 소수: 1과 자기 자신으로만 나누어지는 1보다 큰 자연수
 *
 * 예시 입력: 20
 * 예시 출력:
 *   20은 소수가 아닙니다.
 *   2부터 20까지의 소수: 2 3 5 7 11 13 17 19
 */

#include <stdio.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    int n;

    printf("양의 정수를 입력하세요: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("양의 정수를 입력해야 합니다.\n");
        return 1;
    }

    if (is_prime(n)) {
        printf("%d은(는) 소수입니다.\n", n);
    } else {
        printf("%d은(는) 소수가 아닙니다.\n", n);
    }

    printf("2부터 %d까지의 소수: ", n);
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
