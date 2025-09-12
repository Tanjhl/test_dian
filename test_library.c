#include <stdio.h>
#include <string.h>
char username[26];
int main()
{
    int pgbreak = 0;
    for(int i = 0;i < 26;i++)
    {
    username[i] = 'A' + i;
    }
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
            if (usernameinput[0] == username[j])
            {
                printf("登陆成功！欢迎您，用户%s!", usernameinput);
                pgbreak = 114514;
                break;
            }
            else if (j == 25)
            {
                printf("用户不存在！");

            } 
        }

    }
}