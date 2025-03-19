#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int GettingNumber(char *str, int *i);
int Calculation();
int main(){
    printf("%d\n", Calculation());
}
int WrongFormatCheck(char *str);
int Calculation(){
    char str[256] = {};
    printf("Enter string.\n");
    if(fgets(str, 256, stdin) == NULL){
        printf("Smth went wrong when I was trying to get input.\n");
        return -1;
    }
    if(WrongFormatCheck(str) == 1){
        return 1;
    }
    int stack[4] = {};
    int stackIndx = 0;
    int i = 0;
    while(str[i] != 0){
        if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
            int sum = 0;
            switch(str[i]){
                case '+':
                    sum =  stack[stackIndx - 2] + stack[stackIndx - 1];
                    stack[stackIndx - 2] = sum;
                    stackIndx -= 1;
                    break;
                case '-':
                    sum = stack[stackIndx - 2] - stack[stackIndx - 1];
                    stack[stackIndx - 2] = sum;
                    stackIndx -= 1;
                    break;
                case '*':
                    sum =  stack[stackIndx - 2] * stack[stackIndx - 1];
                    stack[stackIndx - 2] = sum;
                    stackIndx -= 1;
                    break;
                case '/':
                    sum =  stack[stackIndx - 2] / stack[stackIndx - 1];
                    stack[stackIndx - 2] = sum;
                    stackIndx -= 1;
                    break;
            }
            i += 2;
        }
        else{
            stack[stackIndx] = GettingNumber(str, &i);
            stackIndx++;
        }
    }
    return stack[0];
}
int GettingNumber(char *str, int *i){
    char *temp = malloc(12);
    int j = 0;
    while(str[*i] != 32){
        temp[j] = str[*i];
        j++;
        *i += 1;
    }
    *i += 1;
    return atoi(temp);
}
int WrongFormatCheck(char *str){
    size_t strlenght = strlen(str);
    for(int i = 0; i < strlenght; i++){
        if (isalpha(str[i])){
            printf("WRONG FORMAT.");
            return 1;
        }
    }
    return 0;
}