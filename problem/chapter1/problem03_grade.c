/*
 * [문제 3] 학점 계산
 *
 * 0~100 사이의 점수를 입력받아 학점을 출력하시오.
 *
 * 학점 기준:
 *   90 이상       → A
 *   80 이상 90 미만 → B
 *   70 이상 80 미만 → C
 *   60 이상 70 미만 → D
 *   60 미만       → F
 *
 * 예시 입력: 85
 * 예시 출력: 학점: B
 */

#include <stdio.h>

int main(void) {
    int score;

    printf("점수를 입력하세요 (0~100): ");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("올바르지 않은 점수입니다.\n");
    } else if (score >= 90) {
        printf("학점: A\n");
    } else if (score >= 80) {
        printf("학점: B\n");
    } else if (score >= 70) {
        printf("학점: C\n");
    } else if (score >= 60) {
        printf("학점: D\n");
    } else {
        printf("학점: F\n");
    }

    return 0;
}
