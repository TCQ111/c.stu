#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>
#define Row 3
#define Col 3
void menu()
{
   printf("*******************\n");
   printf("***1开始   0结束***\n");
   printf("*******************\n");

}

void csqp(char qipan[Row][Col],int row,int col)
{
printf("***井字棋***\n\n");
int i;
int j;
for (i=0;i<row;i++)
{
      for (j=0;j<col;j++)
      {
      qipan[i][j]=' ';//棋盘初始化 变成空的
      
      }
}
}//………………

void dyqp(char qipan[Row][Col],int row,int col)
{
    int i;          //打印棋牌
    int j;
    for (i=0;i<row;i++)
    {
        for (j=0;j<col;j++)
        {
           printf(" %c ",qipan[i][j]);           
           if(j<col-1)//打印  |  |  |
           printf("|");
        } 
        printf("\n");
        if(i<row-1)
         {
         for(j=0;j<col;j++)
           {
            printf("---");
            if(j<col-1)
            printf("|");
           }
           printf("\n");
         }                    
    }
    printf("\n");
}//…………………………

void wj_game(char qipan[Row][Col],int row,int col)
{
    int x;
    int y;
    printf("玩家走棋:\n坐标的数字之间得有空格!\n");
  while(1)
  {
    printf("请输入坐标-->");
    scanf("%d%d",&x,&y);   
    if(x>=1&&x<=Row&&y>=1&&y<=Col)
      {
        if((qipan[x-1][y-1])==' ')
           {
             qipan[x-1][y-1]='*';
             break;
           }
        else
           {
             printf("该坐标被占用!");
           }
      }
    else
      {
        printf("坐标非法，请重新输入!\n");
      }
   }  
}//………………

void dn_game(char qipan[Row][Col],int row,int col)
{
   int x;
   int y;
   printf("电脑下棋->\n");
  while(1) 
 {
   x=rand()%Row;
   y=rand()%Col;
   if(qipan[x][y]==' ')
      {
      qipan[x][y]='#';
      break;
      }
 }
}

int full(char qipan[Row][Col],int row,int col)
{
    int i;
    int j;
    for(i=0;i<row;i++)
       {
          for(j=0;j<col;j++)
             {
               if(qipan[i][j]==' ')
                return 0;
             }
       }
    return 1;
}
//…………
char shuying(char qipan[Row][Col],int row,int col)
{
   int i;
   for(i=0;i<row;i++)
     {
       if(qipan[i][0]==qipan[i][1] && qipan[i][1]==qipan[i][2] && qipan[i][0]!=' ')
          {
            return qipan[i][0];
          }
     }
   for(i=0;i<col;i++)
     {
       if(qipan[0][i]==qipan[1][i] && qipan[1][i]==qipan[2][i] && qipan[0][i]!=' ')
          {
            return qipan[0][i];
          }
     }
   if(qipan[0][0]==qipan[1][1] && qipan[1][1]==qipan[2][2] && qipan[0][0]!=' ')
       return qipan[0][0];
   if(qipan[0][2]==qipan[1][1] && qipan[1][1]==qipan[2][0] && qipan[0][2]!=' ')
       return qipan[0][2];
   if(1==full(qipan,Row,Col))
     {
       return 'q';
     }
       return 'c';
}

int main(int argc, char** argv)
{
    int a;
    int b;
    char rew;
    srand((unsigned int)time(NULL));
    char qipan[Row][Col]={};
   do
   { menu();
    printf("请选择1或者0: ");
    scanf("%d",&a);
    printf("\n");
    switch(a)
     {
      case 1:      
        csqp(qipan,Row,Col);
        dyqp(qipan,Row,Col);
       while(1)
        {
          wj_game(qipan,Row,Col);//人下棋
          dyqp(qipan,Row,Col);
          rew=shuying(qipan,Row,Col);
          system("cls");
          if(rew!='c')
           {
             break;
           }
          dn_game(qipan,Row,Col);//电脑下棋
          dyqp(qipan,Row,Col);
          rew=shuying(qipan,Row,Col);
          if(rew!='c')
           {
             break;
           }              
        }
        if(rew=='*')
           {
             printf("玩家赢!\n");
           }
          else if(rew=='#')
           {
             printf("电脑赢!\n\n");
           }
          else
           {
             printf("平局!\n");
           }
         break;
      case 0:
         printf("已退出游戏!");
         break;
      default:
         printf("请重新选择!\n");
         break;
      }
   } while(a);       
    
    return 0;
}









