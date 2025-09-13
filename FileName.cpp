#include <stdio.h>

int main() {
    int n;  // 상품 개수
    int i, id;

    // 1. 상품 개수 입력
    printf("상품 개수를 입력하세요: ");
    scanf("%d", &n);

    int incoming[101]; 
    int sales[101];    
    int stock[101];   

    // 2. 상품별 입고 수량 입력
    printf("상품별 입고 수량을 입력하세요:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &incoming[i]);
    }

    // 3. 상품별 판매 수량 입력
    printf("상품별 판매 수량을 입력하세요:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &sales[i]);
    }

    // 4. 재고 계산
    for (i = 1; i <= n; i++) {
        stock[i] = incoming[i] - sales[i];
    }

    // 5. 조회할 ID 입력
    printf("조회할 상품 ID를 입력하세요: ");
    scanf("%d", &id);

    // 해당 상품 재고 출력
    if (id >= 1 && id <= n) {
        printf("%d\n", stock[id]);
    }
    else {
        printf("잘못된 ID입니다.\n");
        return 0;
    }

    // 전체 상품 재고 출력
    for (i = 1; i <= n; i++) {
        printf("%d", stock[i]);
    }
    printf("\n");

    return 0;
}
