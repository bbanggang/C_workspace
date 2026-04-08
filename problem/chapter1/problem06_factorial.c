/*
 * [문제 6] 팩토리얼 계산 (함수 사용)
 *
 * 0 이상의 정수 N을 입력받아 N! (팩토리얼)을 계산하는 함수를 작성하고 결과를 출력하시오.
 * 0! = 1로 정의한다.
 *
 * 입력: 정수 N (0 이상 12 이하)
 * 출력: N! = 결과
 *
 * 예시 입력: 5
 * 예시 출력: 5! = 120
 */

#include <stdio.h>

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n;

    printf("N을 입력하세요 (0~12): ");
    scanf("%d", &n);

    if (n < 0 || n > 12) {
        printf("0 이상 12 이하의 값을 입력하세요.\n");
        return 1;
    }

    printf("%d! = %lld\n", n, factorial(n));

    return 0;
}
