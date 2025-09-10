#include <stdio.h>
#include <string.h>

struct{
    char jian[20];
    char zhi[20];
}rightstrct[10000];
int main() {
    int i = 0;
    FILE *filetest = fopen("data.txt", "r");
    if (filetest == NULL) {
        printf("Error: the file cannot be opened.\n");
        
    }
    
    else 
    {
        while(1)
        {
            if(feof(filetest)){
                printf("这里有%d个正确数据\n",i);
                break;
            }

            else
            {
                char buffer[100];
                
                fgets(buffer, 100, filetest);
                char *weizhi = strstr(buffer, ":");
                if(weizhi!= NULL)
                {
                    memcpy(rightstrct[i].jian,buffer,weizhi-buffer);
                    memcpy(rightstrct[i].zhi,weizhi+1,strlen(buffer)-(weizhi-buffer+1));
                    i++;
                }
            }
        }
        fclose(filetest);
    
        char input[116];
        int nCount = i;
        while (1) {
                        printf("请输入键：");
                        scanf("%s", input);
                        if (strcmp(input, "Quit") == 0)
                            break;
                        else
                        {                            int flag    = 0;
                            for(i = 0;i < nCount;i++)
                            {
                                if (strcmp(input, rightstrct[i].jian) == 0) {
                                    printf("%s",rightstrct[i].zhi);
                                    flag = 1;   
                                    break;
                                } 
                                
                            }
                            if(flag == 0)
                            {
                                    printf("Error\n");
                                    
                            }

                        }
                    }
    }
    
}