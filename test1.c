#include <stdio.h>
#include <string.h>
#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8); 
    char input[116];

    while (1) {
        printf("请输入指令：");
        scanf("%s", input);

        if (strcmp(input, "Dian") == 0) {
            printf("2002\n");
        } else if (strcmp(input, "Quit") == 0) {
            break;
        } else {
            printf("Error\n");
        }
    }

    return 0;
}