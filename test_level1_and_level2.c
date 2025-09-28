#include <stdio.h>
#include <string.h>
#include <windows.h>

char usernames[26][2];
int put_items;

int check_input_buffer() {
    int c;
    int has_extra = 0;
    
    while ((c = getchar()) != '\n' && c != EOF)
    {
        has_extra = 1; 
    }
    return has_extra;
}
struct SEAT
    {
        char seat_status[2];
    }seat[7][5][4][4];
int initial()
{
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
}
char cmdname[7][20] ={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};   
int seat_reserved = 1;
int reservation(char *reservecheck_input)
{
    int flag = 0;
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
                        printf("座位被预约。\n");
                        flag += 1;
                    }
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("暂无预约！\n");
        seat_reserved = 0;
    }
    
}
int checkseat(char *cmdname_input,char *checkseat_username)
{
    char checkseat_input[20];
    int floorinput;
    put_items = scanf("%s%d",  checkseat_input, &floorinput);
    if (put_items < 2)
    {
        printf("Error:输入有误！\n");
        return -1;
    }
    if (check_input_buffer())
    {
        printf("Error:输入有误！\n");
        return -1;
    }
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
                                if (strcmp(checkseat_username, "Admin") != 0)
                                {
                                    if (seat[iaa][ibb][icc][idd].seat_status[0] != '0')
                                    {
                                        if (seat[iaa][ibb][icc][idd].seat_status[0] == checkseat_username[0])
                                        {
                                            printf("1");
                                        }
                                        else
                                        {
                                            printf("2");
                                        }
                                    }
                                    else
                                    {
                                        printf("%s", seat[iaa][ibb][icc][idd].seat_status);
                                    }
                                }
                                else
                                {
                                    printf("%s", seat[iaa][ibb][icc][idd].seat_status);
                                }
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
int reserveseat(char *reserveseat_username)
{
    char seatre_date_input[20];
    char seatre_floor_input[20];
    int floor_re;
    char seatre_seat_input[20];
    int line_re;
    int row_re;
    scanf("%s", seatre_date_input); 
    scanf("%s", seatre_floor_input);
    scanf("%d", &floor_re); 
    scanf("%s", seatre_seat_input);
    scanf("%d", &line_re); 
    scanf("%d", &row_re);
    if (check_input_buffer())
    {
        printf("Error:输入有误！\n");
        return -1;
    }
    int zre = 0;
    int flag_re = 0;
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
                                        seat[zre][floor_re-1][line_re-1][row_re-1].seat_status[0] = reserveseat_username[0];
                                        flag_re += 1;
                                    }
                                    else
                                    {
                                        printf("该座位已被预约！\n");
                                        flag_re += 1;
                                        break;
                                    }
                                }
                                else
                                {
                                    printf("Error:无法识别的操作1\n");
                                    flag_re += 1;

                                    
                                }   
                            }
                        else
                        {
                            printf("Error:无法识别的操作2\n");

                            flag_re += 1;
                            
                        }
                    }
                    else
                    {
                        printf("Error:无法识别的操作3\n");
                        flag_re += 1;
                        
                        

                    }
                }
                else
                {
                    printf("Error:无法识别的操作4\n");
                    flag_re += 1;
                    
                    
                }
                
            }
        
    }    
    if (flag_re == 0)
    {
        printf("Error:无法识别的操作5\n");
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
int cancelseat(char *cancelseat_username)
{
    seat_reserved = 1;
    reservation(cancelseat_username);
    if (seat_reserved == 1)
    {
        return -1;
    }
    printf("输入想取消的座位，或取消所有座位：");
    char cancel_operation[20];
    scanf("%s",cancel_operation);
    if (strcmp(cancel_operation, "all") == 0)
    {
        for (int caa = 0; caa < 7; caa++)
        {
            for (int cab = 0; cab < 5; cab++)
            {
                for (int cac = 0; cac < 4; cac++)
                {
                    for (int cad = 0; cad < 4; cad++)
                    {
                        if (seat[caa][cab][cac][cad].seat_status[0] == cancelseat_username[0])
                        {
                            seat[caa][cab][cac][cad].seat_status[0] = '0';
                            
                        }
                    }
                }
            }
        }
        saveseat();
        printf("取消成功！\n");
    }
    else if (strcmp(cancel_operation, "cancel") == 0)
    {
        char cancel_date_input[20];
        char cancel_floor_input[20];
        int floor_c;
        char cancel_seat_input[20];
        int line_c;
        int row_c;
        scanf("%s", cancel_date_input); 
        scanf("%s", cancel_floor_input);
        scanf("%d", &floor_c); 
        scanf("%s", cancel_seat_input);
        scanf("%d", &line_c); 
        scanf("%d", &row_c);
        int zc = 0;
        for (zc = 0; zc < 7; zc++)
        {
            if (strcmp(cancel_date_input, cmdname[zc]) == 0)
            {
                if (strcmp(cancel_floor_input, "floor") == 0 && strcmp(cancel_seat_input, "seat") == 0)
                {
                    if (floor_c == 1 || floor_c == 2 || floor_c == 3 || floor_c == 4 || floor_c == 5)
                    {
                        if (line_c == 1 || line_c == 2 || line_c == 3 || line_c == 4)
                        {
                            if (row_c == 1 || row_c == 2 || row_c == 3 || row_c == 4)
                            {   
                                if (seat[zc][floor_c-1][line_c-1][row_c-1].seat_status[0] == cancelseat_username[0])
                                {
                                     printf("取消成功！\n");
                                     seat[zc][floor_c-1][line_c-1][row_c-1].seat_status[0] = '0';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    

}
int activities()
{
    
    char activities_date_input[20];
    printf("请输入日期：");
    scanf("%s",activities_date_input);
    for (int da = 0;da < 7;da++)
    {
        if (strcmp(activities_date_input, cmdname[da]) == 0)
        {
            for (int daa = 0;daa < 5;daa++)
            {
                for (int dab = 0;dab < 4;dab++)
                {
                    for (int dac = 0;dac < 4;dac++)
                    {
                        if (seat[da][daa][dab][dac].seat_status[0] != '0')
                        {
                        seat[da][daa][dab][dac].seat_status[0] = '0';
                        }
                    }
                }
            }
        }
        
        
    }
    printf("当日所有座位已取消！\n");  
    saveseat();  
}
int Admin_reservation_change()
{
    printf("请输入用户名：");
    char username_change[20];
    scanf("%s", username_change);
    if (check_input_buffer())
    {
        printf("Error:输入有误！\n");
        return -1;
    }
    else
    {   
        printf("请输入想执行的操作：");
        char operation_change[20];
        scanf("%s", operation_change);
        if (check_input_buffer())
        {
            printf("Error:输入有误！\n");
            return -1;
        }
        else
        {
            if (strcmp(operation_change, "Reserveseat") == 0)
            {
                printf("输入座位信息：\n");
                reserveseat(username_change);
                saveseat();
            
            }
            else if (strcmp(operation_change, "Cancelseat") == 0)
            {
                
                cancelseat(username_change);
                saveseat();
            }
            
        }
               
    }
        
}
int main()
{
    SetConsoleOutputCP(CP_UTF8); 
    FILE *fp = NULL;
    initial();
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
            put_items =scanf("%s", firstinput);
            if (put_items < 1)
            {
                printf("Error:输入有误！\n");
                continue;
            }
            if (check_input_buffer())
            {
                printf("Error:输入有误！\n");
                continue;
            }
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
                        if (check_input_buffer())
                        {
                            printf("Error:输入有误！\n");
                            continue;
                        }
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
                                        if (check_input_buffer())
                                        {
                                            printf("Error:输入有误！\n");
                                            continue;
                                        }
                                        else
                                        {
                                             pgbreak = 114514;
                                            inputexit = 114514;
                                            break;
                                        }
                                    }
                                    else if (strcmp(logininput, "Exit") == 0)
                                    {
                                        if (check_input_buffer())
                                        {
                                            printf("Error:输入有误！\n");
                                            continue;
                                        }
                                        else
                                        {

                                            printf("退出成功！\n");
                                            break;
                                        }
                                    }   
                                    else if (strcmp(logininput, "Cancelseat") == 0)
                                    {
                                        cancelseat(usernameinput);
                                    }
                                    else if (strcmp(logininput, "Reservation") == 0)
                                    {
                                        if (check_input_buffer())
                                        {
                                            printf("Error:输入有误！\n");
                                            continue;
                                        }
                                        else
                                        {
                                            ("查询成功！以下是您的预约记录：\n");
                                            reservation(usernameinput);
                                        }
                                    }
                                    else
                                    {   
                                        int z = 0;
                                        for (z = 0; z < 7; z++)
                                        {
                                            if (strcmp(logininput, cmdname[z]) == 0)
                                            {
                                                checkseat(logininput,usernameinput);
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
                                
                                printf("正处于管理员模式。请输入您想执行的操作：");
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
                                else if (strcmp(logininput, "Changeseat") == 0)
                                {
                                    Admin_reservation_change();
                                    saveseat();
                                }
                                else if (strcmp(logininput, "Clear") == 0)
                                {
                                    printf("清除成功！\n");
                                    initial();
                                    saveseat();
                                }
                                else if (strcmp(logininput, "Repairation") == 0)
                                {
                                    printf("请输入检修楼层：");
                                    int repairation_floor;
                                    scanf("%d", &repairation_floor);
                                    if (repairation_floor == 1 || repairation_floor == 2 || repairation_floor == 3 || repairation_floor == 4 || repairation_floor == 5)
                                    {
                                        for(int ra = 0;ra < 7;ra++)
                                        {
                                            for(int rb = 0;rb < 4;rb++)
                                            {
                                                for(int rc = 0;rc < 4;rc++)
                                                {
                                                    seat[ra][repairation_floor-1][rb][rc].seat_status[0] = '4';
                                                }
                                            }
                                        }
                                        printf("已录入检修指令\n");
                                        saveseat();
                                    } 
                                    else
                                    {
                                        printf("Error:无法识别的操作7\n");
                                    }
                                }
                                else if (strcmp(logininput, "Activities") == 0)
                                {
                                    activities();
                                }
                                else if (strcmp(logininput, "Repairover") == 0)
                                {
                                    printf("请输入修复完毕的楼层：");
                                    int repairover_floor;
                                    scanf("%d", &repairover_floor);
                                    if (repairover_floor == 1 || repairover_floor == 2 || repairover_floor == 3 || repairover_floor == 4 || repairover_floor == 5)
                                    {
                                        for(int ra = 0;ra < 7;ra++)
                                        {
                                            for(int rb = 0;rb < 4;rb++)
                                            {
                                                for(int rc = 0;rc < 4;rc++)
                                                {
                                                    if (seat[ra][repairover_floor-1][rb][rc].seat_status[0] == '4')
                                                    {
                                                        seat[ra][repairover_floor-1][rb][rc].seat_status[0] = '0';
                                                    }
                                                }
                                            }
                                        }
                                        printf("已完成检修，已恢复所有座位！\n");
                                        saveseat();
                                    } 
                                }
                                
                                else if (strcmp (logininput,"Reservation") == 0)
                                {
                                    printf("以下是所有预约记录：\n");
                                    for (int adaa = 0; adaa < 7; adaa++)
                                    {
                                        for (int adbb = 0; adbb < 5; adbb++)                                        
                                        {
                                            for (int adcc = 0; adcc < 4; adcc++)
                                            {                                                
                                                for (int addd = 0; addd < 4; addd++)
                                                {
                                                    if (seat[adaa][adbb][adcc][addd].seat_status[0] != '0' && seat[adaa][adbb][adcc][addd].seat_status[0] != '4')
                                                    {
                                                        printf("日期：%s  ", cmdname[adaa]);
                                                        printf("楼层：%d  ", adbb+1);
                                                        printf("行：%d  ", adcc+1);
                                                        printf("列：%d  ", addd+1);
                                                        printf("座位被用户%s预约！\n", seat[adaa][adbb][adcc][addd].seat_status);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {   
                                    int z = 0;
                                    for (z = 0; z < 7; z++)
                                    {
                                        if (strcmp(logininput, cmdname[z]) == 0)
                                        {
                                            checkseat(logininput,usernameinput);
                                            break;
                                        }
                                    }
                                    if (z == 7)
                                    {
                                        if (strcmp(logininput, "Reserve") == 0)
                                        {
                                                                                      
                                        }
                                        else
                                        {
                                            printf("Error:无法识别的操作6\n");
                                        }
                                    }
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