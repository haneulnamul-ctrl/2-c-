#include <stdio.h>

int main() {
    int n;
    printf("��ǰ ������ �Է��ϼ���(1~100): ");
    scanf("%d", &n);

    int stock[100], sales[100], remain[100];
    int totalStock = 0, totalSales = 0;

    printf("��ǰ�� �԰���� �Է�: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &stock[i]);
        totalStock += stock[i];
    }

    printf("��ǰ�� �Ǹż��� �Է�: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sales[i]);
        remain[i] = stock[i] - sales[i];
        totalSales += sales[i];
    }

    // �Ǹ��� ���
    double rate = (totalStock == 0) ? 0 : (double)totalSales / totalStock * 100.0;

    // �ִ�/�ּ� �Ǹŷ� ã��
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

    // ���
    printf("\n������ : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", remain[i]);
    }

    printf("\n�� �Ǹŷ� : %d (�Ǹ��� %.2f%%)\n", totalSales, rate);
    printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", maxID, maxSales);
    printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", minID, minSales);

    for (int i = 0; i < n; i++) {
        if (remain[i] <= 2) {
            printf("��ǰ ID %d : ������(%d)\n", i + 1, remain[i]);
        }
    }

    return 0;
}

