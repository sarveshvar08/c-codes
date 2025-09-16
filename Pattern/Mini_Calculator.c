#include <stdio.h>
#include <math.h>

// Functions
//SUM

void sum(float a, float b) {
    printf("The sum = %.2f\n", a + b);
}

//Subtraction

void sub(float a, float b) {
    printf("The difference = %.2f\n", a - b);
}

//Multiplication

void mul(float a, float b) {
    printf("The product = %.2f\n", a * b);
}

//Division

void divi(float a, float b) {
    if (b != 0)
        printf("The division = %.2f\n", a / b);
    else
        printf("Division by zero is not allowed.\n");
}

//Modulus

void mod(float a, float b) {
    if (b != 0)
        printf("The modulus = %.2f\n", fmod(a, b)); // fmod for floats
    else
        printf("Modulus by zero is not allowed.\n");
}

//Power

void power(float a, float b) {
    printf("The power = %.2f\n", pow(a, b));
}

//Square Root

void sqrt_func(float a) {
    if (a >= 0)
        printf("The square root = %.2f\n", sqrt(a));
    else
        printf("Square root of negative number is not allowed.\n");
}

// Main function

int main() {
    int choice;
    float num1, num2;

    while (1) {
        // Menu
        printf("\n===== Calculator Menu =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Square Root\n");
        printf("8. Exit\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        // Input handling
        if (choice >= 1 && choice <= 6) {
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
        } 
        else if (choice == 7) {
            printf("Enter one number: ");
            scanf("%f", &num1);
        }

        // Switch
        switch (choice) {
            case 1: 
                sum(num1, num2); 
                break;
            case 2: 
                sub(num1, num2); 
                break;
            case 3: 
                mul(num1, num2); 
                break;
            case 4: 
                divi(num1, num2);
                break;
            case 5:
                mod(num1, num2);   
                break;
            case 6: 
                power(num1, num2); 
                break;
            case 7: 
                sqrt_func(num1); 
                break;
            case 8: 
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
