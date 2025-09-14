#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (int i =1; i <=n; i++) {
        // spaces
        for (int s = 1; s <= n - i; s++) {
            printf("  ");
        }
        // stars
        for (int j = 1; j <=(2*i - 1); j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
