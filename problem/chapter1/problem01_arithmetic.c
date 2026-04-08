/*
 * [문제 1] 사칙연산 출력
 *
 * 두 정수를 입력받아 합, 차, 곱, 몫, 나머지를 출력하시오.
 *
 * 입력: 두 정수 a, b (b != 0)
 * 출력: a+b, a-b, a*b, a/b, a%b
 *
 * 예시 입력: 10 3
 * 예시 출력:
 *   합: 13
 *   차: 7
 *   곱: 30
 *   몫: 3
 *   나머지: 1
 */

#include <stdio.h>

int main(void) {
    int a, b;

    printf("두 정수를 입력하세요 (b는 0이 아니어야 합니다): ");
    scanf("%d %d", &a, &b);

    printf("합: %d\n", a + b);
    printf("차: %d\n", a - b);
    printf("곱: %d\n", a * b);
    printf("몫: %d\n", a / b);
    printf("나머지: %d\n", a % b);

    return 0;
}
