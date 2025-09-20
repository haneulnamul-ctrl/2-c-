#include <stdio.h>

#define PRODUCT_COUNT 5

int main() {
    int stock[PRODUCT_COUNT] = { 0 };   // �԰����
    int sales[PRODUCT_COUNT] = { 0 };   // �Ǹż���
    int remain[PRODUCT_COUNT] = { 0 };  // ������

    int menu, choice, id, qty;
    int i;

    while (1) {
        printf("\n[���θ� ���� ���α׷�]\n");
        printf("���ϴ� �޴��� �����ϼ���.\n");
        printf("1. �԰�\n2. �Ǹ�\n3. ��ǰ��Ȳ\n4. ����\n> ");
        scanf("%d", &menu);

        if (menu == 4) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        switch (menu) {
        case 1: // �԰�
            printf("�԰���� �Է� : ��ü��ǰ 1, ������ǰ 2 ���� > ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("��ü ��ǰ �԰���� (%d��) �Է�: ", PRODUCT_COUNT);
                for (i = 0; i < PRODUCT_COUNT; i++) {
                    scanf("%d", &qty);
                    stock[i] += qty;
                    remain[i] += qty;
                }
            }
            else if (choice == 2) {
                printf("��ǰID(1~%d) �Է�: ", PRODUCT_COUNT);
                scanf("%d", &id);
                printf("�԰���� �Է�: ");
                scanf("%d", &qty);

                if (id >= 1 && id <= PRODUCT_COUNT) {
                    stock[id - 1] += qty;
                    remain[id - 1] += qty;
                }
                else printf("�߸��� ID�Դϴ�.\n");
            }
            break;

        case 2: // �Ǹ�
            printf("�Ǹż��� �Է� : ��ü��ǰ 1, ������ǰ 2 ���� > ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("��ü ��ǰ �Ǹż��� (%d��) �Է�: ", PRODUCT_COUNT);
                for (i = 0; i < PRODUCT_COUNT; i++) {
                    scanf("%d", &qty);
                    if (qty <= remain[i]) {
                        sales[i] += qty;
                        remain[i] -= qty;
                    }
                    else {
                        printf("��ǰ %d ��� ����! (����: %d)\n", i + 1, remain[i]);
                    }
                }
            }
            else if (choice == 2) {
                printf("��ǰID(1~%d) �Է�: ", PRODUCT_COUNT);
                scanf("%d", &id);
                printf("�Ǹż��� �Է�: ");
                scanf("%d", &qty);

                if (id >= 1 && id <= PRODUCT_COUNT) {
                    if (qty <= remain[id - 1]) {
                        sales[id - 1] += qty;
                        remain[id - 1] -= qty;
                    }
                    else {
                        printf("��ǰ %d ��� ����! (����: %d)\n", id, remain[id - 1]);
                    }
                }
                else printf("�߸��� ID�Դϴ�.\n");
            }
            break;

        case 3: // ��ǰ��Ȳ
        {
            int totalStock = 0, totalSales = 0;
            int maxSales = sales[0], minSales = sales[0];
            int maxID = 1, minID = 1;

            printf("\n������ : ");
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

            printf("\n�� �Ǹŷ� : %d (�Ǹ��� %.2f%%)\n", totalSales, rate);
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", maxID, maxSales);
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", minID, minSales);

            for (i = 0; i < PRODUCT_COUNT; i++) {
                if (remain[i] <= 2) {
                    printf("��ǰ ID %d : ������(%d)\n", i + 1, remain[i]);
                }
            }
        }
        break;

        default:
            printf("�߸��� �޴� �����Դϴ�.\n");
        }
    }

    return 0;
}


