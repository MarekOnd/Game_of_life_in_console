#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
int POLE[50][50];

void akce(int size)
{
    int x,y,soucet,pole[size][size];
    for(y=0;y<size;y++)//vse nula
    {
        for(x=0;x<size;x++)
        {
            pole[x][y]=0;
        }
    }
    for(x=0;x<size;x++)
    {
        for(y=0;y<size;y++)
        {
            //printf("%d",sousedi(size,x,y));
            if(POLE[x][y]==1)//umirani
            {
                if(sousedi(size,x,y)==3 || sousedi(size,x,y)==4)
                {
                    pole[x][y]=1;
                }
                else
                {
                    pole[x][y]=0;
                }
            }
            else//oziveni
            {
                if(sousedi(size,x,y)==3)
                {
                    pole[x][y]=1;
                }
                else
                {
                    pole[x][y]=0;
                }
            }
        }
        //printf("\n");
    }
    prepispoledopole(pole,size);
}

int sousedi(int size,int x, int y)
{
    int soucet=0,i,j;
    for(i=-1;i<2;i++)
    {
        for(j=-1;j<2;j++)
        {
            soucet=soucet+POLE[(x+i+size)%size][(y+j+size)%size];
        }
    }
    return soucet;
}

void vypisPOLE(int size)
{
    int x,y;
    for(y=0;y<size;y++)
    {
        for(x=0;x<size;x++)
        {
            if(POLE[x][y]==1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void prepispoledopole(int pole[50][50],int size)
{
    int x,y;
    for(y=0;y<size;y++)
    {
        for(x=0;x<size;x++)
        {
            POLE[x][y]=pole[x][y];
        }
    }
}

int main (){
    int size=50;
    //int pole[size][size];
    int x,y;

    for(y=0;y<size;y++)//vse nula
    {
        for(x=0;x<size;x++)
        {
            POLE[x][y]=0;
        }
    }

    /*POLE[20][18]=1;
    POLE[20][19]=1;
    POLE[20][20]=1;
    POLE[19][20]=1;
    POLE[18][19]=1;

    /*POLE[19][20]=1;
    POLE[19][21]=1;
    POLE[19][22]=1;
    POLE[19][23]=1;
    POLE[19][24]=1;*/

    //POLE[19][25]=1;
    //POLE[19][26]=1;

    //GLIDER GUN
    POLE[1][5]=1;
    POLE[1][6]=1;
    POLE[2][5]=1;
    POLE[2][6]=1;
    POLE[11][5]=1;
    POLE[11][6]=1;
    POLE[11][7]=1;
    POLE[12][4]=1;
    POLE[12][8]=1;
    POLE[13][3]=1;
    POLE[13][9]=1;
    POLE[14][3]=1;
    POLE[14][9]=1;
    POLE[15][6]=1;
    POLE[16][4]=1;
    POLE[16][8]=1;
    POLE[17][5]=1;
    POLE[17][6]=1;
    POLE[17][7]=1;
    POLE[18][6]=1;
    POLE[21][3]=1;
    POLE[21][4]=1;
    POLE[21][5]=1;
    POLE[22][3]=1;
    POLE[22][4]=1;
    POLE[22][5]=1;
    POLE[23][2]=1;
    POLE[23][6]=1;
    POLE[25][1]=1;
    POLE[25][2]=1;
    POLE[25][6]=1;
    POLE[25][7]=1;
    POLE[35][3]=1;
    POLE[35][4]=1;
    POLE[36][3]=1;
    POLE[36][4]=1;

    //EATER
    POLE[45][31]=1;
    POLE[45][32]=1;
    POLE[46][31]=1;
    POLE[47][32]=1;
    POLE[47][33]=1;
    POLE[47][34]=1;
    POLE[48][34]=1;


    int opakovani=10000,i;
    for(i=0;i<opakovani;i++)
    {
        system("cls");
        vypisPOLE(size);
        akce(size);
        //Sleep(10);
    }
    return(0);
}
