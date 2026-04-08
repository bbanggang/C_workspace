/*
 * [문제 4] 구구단 출력
 *
 * 2~9 사이의 단을 입력받아 해당 단의 구구단을 출력하시오.
 * 범위를 벗어난 경우 오류 메시지를 출력하시오.
 *
 * 예시 입력: 3
 * 예시 출력:
 *   3 x 1 = 3
 *   3 x 2 = 6
 *   ...
 *   3 x 9 = 27
 */

#include <stdio.h>

int main(void) {
    int dan;

    printf("출력할 단을 입력하세요 (2~9): ");
    scanf("%d", &dan);

    if (dan < 2 || dan > 9) {
        printf("2에서 9 사이의 값을 입력하세요.\n");
        return 1;
    }

    for (int i = 1; i <= 9; i++) {
        printf("%d x %d = %d\n", dan, i, dan * i);
    }

    return 0;
}
