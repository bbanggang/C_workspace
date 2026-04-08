/*
 * [문제 10] 메뉴 기반 계산기
 *
 * 반복문과 함수, 조건문을 이용하여 메뉴 방식의 계산기를 구현하시오.
 * 사용자가 0을 입력할 때까지 계산을 반복한다.
 *
 * 메뉴:
 *   1. 덧셈
 *   2. 뺄셈
 *   3. 곱셈
 *   4. 나눗셈
 *   0. 종료
 *
 * 예시:
 *   메뉴 선택: 1
 *   두 수 입력: 10 5
 *   결과: 10 + 5 = 15
 */

#include <stdio.h>

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }

int divide(double a, double b, double *result) {
    if (b == 0) return 0;
    *result = a / b;
    return 1;
}

void print_menu(void) {
    printf("\n===== 계산기 =====\n");
    printf("1. 덧셈\n");
    printf("2. 뺄셈\n");
    printf("3. 곱셈\n");
    printf("4. 나눗셈\n");
    printf("0. 종료\n");
    printf("선택: ");
}

int main(void) {
    int choice;
    double a, b, result;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("계산기를 종료합니다.\n");
            break;
        }

        if (choice < 1 || choice > 4) {
            printf("올바른 메뉴를 선택하세요.\n");
            continue;
        }

        printf("두 수를 입력하세요: ");
        scanf("%lf %lf", &a, &b);

        switch (choice) {
            case 1:
                printf("결과: %.2f + %.2f = %.2f\n", a, b, add(a, b));
                break;
            case 2:
                printf("결과: %.2f - %.2f = %.2f\n", a, b, subtract(a, b));
                break;
            case 3:
                printf("결과: %.2f x %.2f = %.2f\n", a, b, multiply(a, b));
                break;
            case 4:
                if (!divide(a, b, &result)) {
                    printf("오류: 0으로 나눌 수 없습니다.\n");
                } else {
                    printf("결과: %.2f / %.2f = %.2f\n", a, b, result);
                }
                break;
        }
    }

    return 0;
}
