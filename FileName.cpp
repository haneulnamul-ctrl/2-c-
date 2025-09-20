#include <stdio.h>

#define PRODUCT_COUNT 5

int main() {
    int stock[PRODUCT_COUNT] = { 0 };   // 입고수량
    int sales[PRODUCT_COUNT] = { 0 };   // 판매수량
    int remain[PRODUCT_COUNT] = { 0 };  // 재고수량

    int menu, choice, id, qty;
    int i;

    while (1) {
        printf("\n[쇼핑몰 관리 프로그램]\n");
        printf("원하는 메뉴를 선택하세요.\n");
        printf("1. 입고\n2. 판매\n3. 상품현황\n4. 종료\n> ");
        scanf("%d", &menu);

        if (menu == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        switch (menu) {
        case 1: // 입고
            printf("입고수량 입력 : 전체상품 1, 개별상품 2 선택 > ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("전체 상품 입고수량 (%d개) 입력: ", PRODUCT_COUNT);
                for (i = 0; i < PRODUCT_COUNT; i++) {
                    scanf("%d", &qty);
                    stock[i] += qty;
                    remain[i] += qty;
                }
            }
            else if (choice == 2) {
                printf("상품ID(1~%d) 입력: ", PRODUCT_COUNT);
                scanf("%d", &id);
                printf("입고수량 입력: ");
                scanf("%d", &qty);

                if (id >= 1 && id <= PRODUCT_COUNT) {
                    stock[id - 1] += qty;
                    remain[id - 1] += qty;
                }
                else printf("잘못된 ID입니다.\n");
            }
            break;

        case 2: // 판매
            printf("판매수량 입력 : 전체상품 1, 개별상품 2 선택 > ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("전체 상품 판매수량 (%d개) 입력: ", PRODUCT_COUNT);
                for (i = 0; i < PRODUCT_COUNT; i++) {
                    scanf("%d", &qty);
                    if (qty <= remain[i]) {
                        sales[i] += qty;
                        remain[i] -= qty;
                    }
                    else {
                        printf("상품 %d 재고 부족! (가능: %d)\n", i + 1, remain[i]);
                    }
                }
            }
            else if (choice == 2) {
                printf("상품ID(1~%d) 입력: ", PRODUCT_COUNT);
                scanf("%d", &id);
                printf("판매수량 입력: ");
                scanf("%d", &qty);

                if (id >= 1 && id <= PRODUCT_COUNT) {
                    if (qty <= remain[id - 1]) {
                        sales[id - 1] += qty;
                        remain[id - 1] -= qty;
                    }
                    else {
                        printf("상품 %d 재고 부족! (가능: %d)\n", id, remain[id - 1]);
                    }
                }
                else printf("잘못된 ID입니다.\n");
            }
            break;

        case 3: // 상품현황
        {
            int totalStock = 0, totalSales = 0;
            int maxSales = sales[0], minSales = sales[0];
            int maxID = 1, minID = 1;

            printf("\n재고수량 : ");
            for (i = 0; i < PRODUCT_COUNT; i++) {
                printf("%d ", remain[i]);
                totalStock += stock[i];
                totalSales += sales[i];

                if (sales[i] > maxSales) {
                    maxSales = sales[i];
                    maxID = i + 1;
                }
                if (sales[i] < minSales) {
                    minSales = sales[i];
                    minID = i + 1;
                }
            }

            double rate = (totalStock == 0) ? 0 : (double)totalSales / totalStock * 100.0;

            printf("\n총 판매량 : %d (판매율 %.2f%%)\n", totalSales, rate);
            printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxID, maxSales);
            printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minID, minSales);

            for (i = 0; i < PRODUCT_COUNT; i++) {
                if (remain[i] <= 2) {
                    printf("상품 ID %d : 재고부족(%d)\n", i + 1, remain[i]);
                }
            }
        }
        break;

        default:
            printf("잘못된 메뉴 선택입니다.\n");
        }
    }

    return 0;
}


