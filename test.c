#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>
#define Row 3
#define Col 3
void menu()
{
   printf("*******************\n");
   printf("***1��ʼ   0����***\n");
   printf("*******************\n");

}

void csqp(char qipan[Row][Col],int row,int col)
{
printf("***������***\n\n");
int i;
int j;
for (i=0;i<row;i++)
{
      for (j=0;j<col;j++)
      {
      qipan[i][j]=' ';//���̳�ʼ�� ��ɿյ�
      
      }
}
}//������������

void dyqp(char qipan[Row][Col],int row,int col)
{
    int i;          //��ӡ����
    int j;
    for (i=0;i<row;i++)
    {
        for (j=0;j<col;j++)
        {
           printf(" %c ",qipan[i][j]);           
           if(j<col-1)//��ӡ  |  |  |
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
}//��������������������

void wj_game(char qipan[Row][Col],int row,int col)
{
    int x;
    int y;
    printf("�������:\n���������֮����пո�!\n");
  while(1)
  {
    printf("����������-->");
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
             printf("�����걻ռ��!");
           }
      }
    else
      {
        printf("����Ƿ�������������!\n");
      }
   }  
}//������������

void dn_game(char qipan[Row][Col],int row,int col)
{
   int x;
   int y;
   printf("��������->\n");
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
//��������
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
    printf("��ѡ��1����0: ");
    scanf("%d",&a);
    printf("\n");
    switch(a)
     {
      case 1:      
        csqp(qipan,Row,Col);
        dyqp(qipan,Row,Col);
       while(1)
        {
          wj_game(qipan,Row,Col);//������
          dyqp(qipan,Row,Col);
          rew=shuying(qipan,Row,Col);
          system("cls");
          if(rew!='c')
           {
             break;
           }
          dn_game(qipan,Row,Col);//��������
          dyqp(qipan,Row,Col);
          rew=shuying(qipan,Row,Col);
          if(rew!='c')
           {
             break;
           }              
        }
        if(rew=='*')
           {
             printf("���Ӯ!\n");
           }
          else if(rew=='#')
           {
             printf("����Ӯ!\n\n");
           }
          else
           {
             printf("ƽ��!\n");
           }
         break;
      case 0:
         printf("���˳���Ϸ!");
         break;
      default:
         printf("������ѡ��!\n");
         break;
      }
   } while(a);       
    
    return 0;
}









