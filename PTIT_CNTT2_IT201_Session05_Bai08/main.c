#include <math.h>
#include <stdio.h>
#include <string.h>

int checkNum(char input[]) {
    for (int i=0; i<strlen(input); i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
    }
    return 1;
}
// ham tinh 10^n
int pow10(int n) {
    if (n==0)
        return 1;
    return 10*pow10(n-1);
}
int strToInt(char str[], int index, int length) {
    if (index==length) return 0;
    // chuyen ky tu thanh so
    int digit=str[index]-'0';
    return digit * pow10(length-index-1)+strToInt(str, index+1, length);
}
int main(void) {
    char input[20];
    fgets(input, 20, stdin);
    input[strcspn(input,"\n")]='\0';
    if (checkNum(input)==0) {
        printf("Khong phai chuoi ky tu so");
        return 0;
    }
    int length=strlen(input);
    printf("%d", strToInt(input, 0, length));
    return 0;
}
