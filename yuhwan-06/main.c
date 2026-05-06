#include <stdlib.h>
#include <stdio.h>
int Add(int n);

int main(void){
    int n;
    printf("n값 입력 : ");
    scanf("%d", &n);
    
    printf("%d\n", Add(n));
    return 0;
}

int Add(int n){
    if(n == 0){
        return 0;
    }
    
    if(n % 3 == 0){
        return n + Add(n - 1);
    }
    
    else
        return Add(n - 1);
}
