#include <stdio.h>

int main() {
    int n;  // ��ǰ ����
    int i, id;

    // 1. ��ǰ ���� �Է�
    printf("��ǰ ������ �Է��ϼ���: ");
    scanf("%d", &n);

    int incoming[101]; 
    int sales[101];    
    int stock[101];   

    // 2. ��ǰ�� �԰� ���� �Է�
    printf("��ǰ�� �԰� ������ �Է��ϼ���:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &incoming[i]);
    }

    // 3. ��ǰ�� �Ǹ� ���� �Է�
    printf("��ǰ�� �Ǹ� ������ �Է��ϼ���:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &sales[i]);
    }

    // 4. ��� ���
    for (i = 1; i <= n; i++) {
        stock[i] = incoming[i] - sales[i];
    }

    // 5. ��ȸ�� ID �Է�
    printf("��ȸ�� ��ǰ ID�� �Է��ϼ���: ");
    scanf("%d", &id);

    // �ش� ��ǰ ��� ���
    if (id >= 1 && id <= n) {
        printf("%d\n", stock[id]);
    }
    else {
        printf("�߸��� ID�Դϴ�.\n");
        return 0;
    }

    // ��ü ��ǰ ��� ���
    for (i = 1; i <= n; i++) {
        printf("%d", stock[i]);
    }
    printf("\n");

    return 0;
}
