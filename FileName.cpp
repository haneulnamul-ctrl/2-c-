#include <stdio.h>

int main() {
    int n;
    printf("상품 개수를 입력하세요(1~100): ");
    scanf("%d", &n);

    int stock[100], sales[100], remain[100];
    int totalStock = 0, totalSales = 0;

    printf("상품별 입고수량 입력: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
        totalStock += stock[i];
    }

    printf("상품별 판매수량 입력: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
        remain[i] = stock[i] - sales[i];
        totalSales += sales[i];
    }

    // 판매율 계산
    double rate = (totalStock == 0) ? 0 : (double)totalSales / totalStock * 100.0;

    // 최대/최소 판매량 찾기
    int maxSales = sales[0], minSales = sales[0];
    int maxID = 1, minID = 1;

    for (int i = 1; i < n; i++) {
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxID = i + 1;
        }
        if (sales[i] < minSales) {
            minSales = sales[i];
            minID = i + 1;
        }
    }

    // 출력
    printf("\n재고수량 : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", remain[i]);
    }

    printf("\n총 판매량 : %d (판매율 %.2f%%)\n", totalSales, rate);
    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxID, maxSales);
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minID, minSales);

    for (int i = 0; i < n; i++) {
        if (remain[i] <= 2) {
            printf("상품 ID %d : 재고부족(%d)\n", i + 1, remain[i]);
        }
    }

    return 0;
}

