#include <stdio.h>
#include <string.h>

char usernames[26][2];

struct SEAT
    {
        char seat_status[2];
    }seat[7][5][4][4];

char cmdname[7][20] ={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};   

int reservation(char *reservecheck_input)
{
    for (int rea = 0; rea < 7; rea++)
    {
        for (int reb = 0; reb < 5; reb++)
        {
            for (int rec = 0; rec < 4; rec++)
            {
                for (int red = 0; red < 4; red++)
                {
                    if (seat[rea][reb][rec][red].seat_status[0] == reservecheck_input[0])
                    {
                        printf("日期：%s  ", cmdname[rea]);
                        printf("楼层：%d  ", reb+1);
                        printf("行：%d  ", rec+1);
                        printf("列：%d  ", red+1);
                        printf("座位被您预约！\n");
                    }
                }
            }
        }
    }
    
}
int checkseat(char *cmdname_input)
{
    char checkseat_input[20];
    int floorinput;
    scanf("%s%d",  checkseat_input, &floorinput);
    if (strcmp(checkseat_input, "floor") == 0 && floorinput == 1 || floorinput == 2 || floorinput == 3 || floorinput == 4 || floorinput == 5)
    {
        printf("以下是查询结果：\n");
        for (int iaa = 0; iaa < 7; iaa++)
        {
            if (strcmp(cmdname_input, cmdname[iaa]) == 0)
            {   
                for (int ibb = 0; ibb < 5; ibb++)
                {
                    if (floorinput -1 == ibb)
                    {
                        for (int icc = 0; icc < 4; icc++)
                        {
                            for (int idd = 0; idd < 4; idd++)
                            {
                                printf("%s", seat[iaa][ibb][icc][idd].seat_status);
                            }
                        printf("\n");
                        }
                    }
                    
                }

            }
        
        }
    }
    else
    {
        printf("Error:无法识别的操作\n");
    }
}
char usernameinput[255];
int reserveseat(char *reserveseat_input)
{
    char seatre_date_input[20];
    char seatre_floor_input[20];
    int floor_re;
    char seatre_seat_input[20];
    int line_re;
    int row_re;
    scanf("%s%s%d%s%d%d", seatre_date_input, seatre_floor_input, &floor_re, seatre_seat_input, &line_re,&row_re);
    int zre = 0;
    for (zre = 0; zre < 7; zre++)
    {
        if (strcmp(seatre_date_input, cmdname[zre]) == 0)
            {
                if (strcmp(seatre_floor_input, "floor") == 0 && strcmp(seatre_seat_input, "seat") == 0)
                {
                    if (floor_re == 1 || floor_re == 2 || floor_re == 3 || floor_re == 4 || floor_re == 5)
                    {
                        if (line_re == 1 || line_re == 2 || line_re == 3 || line_re == 4)
                            {
                                if (row_re == 1 || row_re == 2 || row_re == 3 || row_re == 4)
                                {   
                                    if (seat[zre][floor_re-1][line_re-1][row_re-1].seat_status[0] == '0')
                                    {
                                        printf("预约成功！\n");
                                        seat[zre][floor_re-1][line_re-1][row_re-1].seat_status[0] = usernameinput[0];
                                    }
                                    else
                                    {
                                        printf("该座位已被预约！\n");
                                    }
                                }
                                else
                                {
                                    printf("Error:无法识别的操作1\n");
                                    break;
                                }   
                            }
                        else
                        {
                            printf("Error:无法识别的操作2\n");
                            break;
                        }
                    }
                    else
                    {
                        printf("Error:无法识别的操作3\n");
                        break;

                    }
                }
                else
                {
                    printf("Error:无法识别的操作4\n");
                    break;
                }
                break;
            }
        else
        {
            printf("Error:无法识别的操作5\n");
            break;
        }
    }                                    
}
int saveseat()
{
    FILE *fp = NULL;
    fp = fopen("seat.txt", "w");
    for (int ia = 0; ia < 7; ia++)
    {
        for (int ib = 0; ib < 5; ib++)
        {
            for (int ic = 0; ic < 4; ic++)
            {
                for (int id = 0; id < 4; id++)
                {
                    fprintf(fp, "%s\n", seat[ia][ib][ic][id].seat_status);
                }
            }
        }
    }
    fclose(fp);
}
int main()
{
    FILE *fp = NULL;
    for (int ia = 0; ia < 7; ia++)
        {
            for (int ib = 0; ib < 5; ib++)
            {
                for (int ic = 0; ic < 4; ic++)
                {
                    for (int id = 0; id < 4; id++)
                    {
                        seat[ia][ib][ic][id].seat_status[0] = '0';
                        seat[ia][ib][ic][id].seat_status[1] = '\0';
                    }
                }
            }
        }
    fp = fopen("seat.txt", "r");
    if (fp == NULL)
    {
        saveseat();
    }
    else
    {
        for (int ia = 0; ia < 7; ia++)
        {
            for (int ib = 0; ib < 5; ib++)
            {
                for (int ic = 0; ic < 4; ic++)
                {
                    for (int id = 0; id < 4; id++)
                    {
                        char buffer[3];
                        fgets(buffer, 3, fp);
                        seat[ia][ib][ic][id].seat_status[0] = buffer[0];
                    }
                }
            }
        }

        fclose(fp);
    }
    for(int i = 0;i < 26;i++)
    {
    usernames[i][0] = 'A' + i;
    usernames[i][1] = '\0';

    }
    char firstinput[255];
    int inputexit = 0;
    while (1) 
        {   
            if (inputexit == 114514)
            {
                break;
            }
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
                                printf("登陆成功！欢迎您，用户%s!\n", usernameinput);
                                while(1)
                                {
                                    printf("请输入您想执行的操作：");
                                    char logininput[255];
                                    scanf("%s", logininput);
                                    if (strcmp(logininput, "Quit") == 0)
                                    {
                                        pgbreak = 114514;
                                        inputexit = 114514;
                                        break;
                                    }
                                    else if (strcmp(logininput, "Exit") == 0)
                                    {
                                        printf("退出成功！\n");
                                        break;
                                    }   
                                    else if (strcmp(logininput, "Reservation") == 0)
                                    {
                                        printf("查询成功！以下是您的预约记录：\n");
                                        reservation(usernameinput);
                                    }
                                    else
                                    {   
                                        int z = 0;
                                        for (z = 0; z < 7; z++)
                                        {
                                            if (strcmp(logininput, cmdname[z]) == 0)
                                            {
                                                checkseat(logininput);
                                                break;
                                            }
                                        }
                                        if (z == 7)
                                        {
                                            if (strcmp(logininput, "Reserve") == 0)
                                            {
                                                reserveseat(usernameinput);
                                                saveseat();
                                            }
                                            else
                                            {
                                                printf("Error:无法识别的操作6\n");
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                            //admin版本待
                            else if (strcmp(usernameinput, "Admin") == 0)
                            {
                                {
                                printf("登陆成功！欢迎您，管理员！\n请输入您想执行的操作：");
                                char logininput[255];
                                scanf("%s", logininput);
                                if (strcmp(logininput, "Quit") == 0)
                                {
                                    pgbreak = 114514;
                                    break;
                                }
                                else if (strcmp(logininput, "Exit") == 0)
                                {
                                    printf("退出成功！\n");
                                    break;
                                }   
                                else if (strcmp(logininput, "Clear") == 0)
                                {
                                    printf("清除成功！\n");//待添加clear
                                }
                                else
                                {
                                    printf("Error：无法识别的操作\n");
                                    pgbreak = 114514;
                                }

                                pgbreak = 114514;
                                break;
                            }
                            }
                            else if (j == 25)
                            {
                                printf("用户不存在！\n");

                            } 
                        }

                    }
            }
            else {
                printf("Error:无法识别的指令\n");
            }
        }
    return 0;
}