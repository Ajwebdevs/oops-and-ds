#include <stdio.h>

struct Polynomial {
    int coeff;
    int exp;
};

int main() {
    int n1, n2, i, j, k;
    
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    struct Polynomial poly1[n1];
    
    for (i = 0; i < n1; i++) {
        printf("Coefficient: ");
        scanf("%d", &poly1[i].coeff);
        printf("Exponent: ");
        scanf("%d", &poly1[i].exp);
    }
    
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    struct Polynomial poly2[n2];
    
    for (i = 0; i < n2; i++) {
        printf("Coefficient: ");
        scanf("%d", &poly2[i].coeff);
        printf("Exponent: ");
        scanf("%d", &poly2[i].exp);
    }
    
    struct Polynomial result[n1 + n2];
    i = j = k = 0;
    
    while (i < n1 && j < n2) {
        if (poly1[i].exp == poly2[j].exp) {
            result[k].coeff = poly1[i].coeff + poly2[j].coeff;
            result[k].exp = poly1[i].exp;
            i++;
            j++;
            k++;
        } else if (poly1[i].exp > poly2[j].exp) {
            result[k].coeff = poly1[i].coeff;
            result[k].exp = poly1[i].exp;
            i++;
            k++;
        } else {
            result[k].coeff = poly2[j].coeff;
            result[k].exp = poly2[j].exp;
            j++;
            k++;
        }
    }
    
    while (i < n1) {
        result[k] = poly1[i];
        i++;
        k++;
    }
    while (j < n2) {
        result[k] = poly2[j];
        j++;
        k++;
    }
    
    // Print the resultant polynomial
    printf("Resultant polynomial: ");
    for (i = 0; i < k; i++) {
        if (i > 0 && result[i].coeff > 0) {
            printf("+ ");
        }
        printf("%dx^%d ", result[i].coeff, result[i].exp);
    }
    
    return 0;
}