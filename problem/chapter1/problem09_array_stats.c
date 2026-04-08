/*
 * [문제 9] 배열 통계 (함수 사용)
 *
 * 정수 N을 입력받고 N개의 정수 배열을 입력받아
 * 최솟값, 최댓값, 평균을 출력하시오.
 * 각각 별도의 함수로 구현하시오.
 *
 * 입력: N, 그 다음 줄에 N개의 정수
 * 출력: 최솟값, 최댓값, 평균
 *
 * 예시 입력:
 *   5
 *   3 1 4 1 5
 * 예시 출력:
 *   최솟값: 1
 *   최댓값: 5
 *   평균: 2.80
 */

#include <stdio.h>

int find_min(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

double find_avg(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

int main(void) {
    int n;

    printf("배열의 크기를 입력하세요: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("1 이상의 정수를 입력해야 합니다.\n");
        return 1;
    }

    int arr[n];
    printf("%d개의 정수를 입력하세요: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("최솟값: %d\n", find_min(arr, n));
    printf("최댓값: %d\n", find_max(arr, n));
    printf("평균: %.2f\n", find_avg(arr, n));

    return 0;
}
