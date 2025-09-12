#include <stdio.h>
#include <string.h>

char usernames[26][2];
int main()
{
    for(int i = 0;i < 26;i++)
    {
    usernames[i][0] = 'A' + i;
    usernames[i][1] = '\0';

    }
    char firstinput[255];
    while (1) 
        {
            printf("请输入指令：");
            scanf("%s", firstinput);

            if (strcmp(firstinput, "Quit") == 0) 
            {
                break;
            } 
            else if (strcmp(firstinput, "Login") == 0) 
            {
                int pgbreak = 0;
                while(1)
                    {
                        char usernameinput[255];
                        if (pgbreak == 114514)
                        {
                            break;
                        }
                        printf("请输入用户名：");
                        scanf("%s", usernameinput);
                        for (int j = 0;j <26;j++)
                        {
                            if (strcmp(usernameinput,usernames[j]) == 0)
                            {
                                printf("登陆成功！欢迎您，用户%s!\n请输入您想执行的操作：", usernameinput);
                                char logininput[255];
                                scanf("%s", logininput);
                                if (strcmp(logininput, "Quit") == 0)
                                {
                                    pgbreak = 114514;
                                    break;
                                }
                                else
                                {
                                    printf("Error\n");
                                    pgbreak = 114514;
                                }

                                pgbreak = 114514;
                                break;
                            }
                            else if (j == 25)
                            {
                                printf("用户不存在！\n");

                            } 
                        }

                    }
            }
            else {
                printf("Error\n");
            }
        }
}