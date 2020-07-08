#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
    int i,l;
    FILE *f1,*f2,*f3;
    int j=0,k=0,lc,sy,no,sym=0,reg,num,vari;
    char var[256],var1[4][10],symb[10][10],add[10][10];
    char delim[] = " ";

    f1=fopen("output.txt","r");
    f3=fopen("symtab.txt","r");
    for(l=1;l<6;l++)
    {
        fscanf(f3,"%s%s",symb[l],add[l]);
    }
    while(k<18)
    {
        fgets(var,sizeof(var),f1);
        i=0;
        char *ptr = strtok(var, delim);
        while(ptr != NULL)
        {
            strcpy(var1[i],ptr);
	//	printf("%s\n", var1[i]);
            ptr = strtok(NULL, delim);
            i++;
        }
        j=i;
        strtok(var1+0,"\n");
        //for(i=0;i<j;i++)
          //  printf("%s\n",var1+i);
        if(strcmp(var1+0,"AD")==0&&strcmp(var1+1,"01")==0)
        {
            lc=atoi(var1+3);
            //printf("%d\n",lc);
        }
        if(strcmp(var1+0,"IS")==0)
        {
            vari=atoi(var1+4);
            strtok(var1+1,"\n");
            if(strcmp(var1+1,"00")==0)
            {
                printf("%d  00 0 000 \n",lc);
            }
            else
            printf("%d  %s  %s  %s\n",lc,var1+1,var1+2,add[vari]);

            lc+=1;
        }
        if(strcmp(var1+0,"DL")==0)
        {
            if(strcmp(var1+1,"02")==0)
            {
                lc+=1;
                printf("%d  Mermory allocation\n",lc);
            }
            if(strcmp(var1+1,"01")==0)
            {
               printf("%d  00 0 001",lc);
               lc+=1;
            }
        }
        k++;
    }
}
