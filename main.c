#include <stdio.h>
#include <stdlib.h>

double funct(double x);

int main()
{
    FILE *f_in, *f_out, *fb_out;
    f_in=fopen("input.dat","r");
    if(f_in==NULL)
    {
        printf("File not found!!\n");
        return 0;
    }
    char group[10];
    double a,b,delta;
    int N;
        fscanf(f_in,"%s",group);
        fscanf(f_in,"%lf",&a);
        fscanf(f_in,"%lf",&b);
        fscanf(f_in,"%u",&N);
        fscanf(f_in,"%lf",&delta);
    //printf("%.s %.lf %.lf %.u %.lf",group,a,b,N,delta);

    double x=a,y;
    if(N==0)
    {
        N=(b-a)/delta;
    }
    double **arr;
    arr=malloc(2*sizeof(double *));
    arr[0]=malloc(N*sizeof(double));  //x
    arr[1]=malloc(N*sizeof(double));  //y
    for(int i=0;i<N;i++)
    {
        arr[0][i]=x;
        arr[1][i]=funct(x);
        x+=delta;
    }
    //Тііксті
f_out=fopen("result.txt","w");
    fprintf(f_out,"klk tochok %u\n",N);
    for(int i=0;i<N;i++)
    {
        fprintf(f_out,"%10.2lf %10.2lf\n",arr[0][i], arr[1][i]);
    }
    //Бінарний
    fb_out=fopen("result.bin","wb");
    fwrite(&N,sizeof(int),1,fb_out);
    for(int i=0;i<N;i++)
    {
        fwrite(&arr[0][i],sizeof(double),1,fb_out);
        fwrite(&arr[1][i],sizeof(double),1,fb_out);

    }
             free(arr[0]);
              free(arr[1]);
                free(arr);
                fclose(f_in);
              fclose(f_out);
             fclose(fb_out);
    // print binary file
    fb_out=fopen("result.bin","rb");
    if(fb_out==NULL)
    {
        printf("File not found!!\n");
        return 0;
    }
       fread(&N,sizeof(int),1,fb_out);
       printf("klk tochok = %u\n",N);
       printf("       x           y\n");
     for(int i=0;i<N;i++)
    {
        fread(&x,sizeof(double),1,fb_out);
        fread(&y,sizeof(double),1,fb_out);
        printf("%10.2lf %10.2lf\n",x,y);

    }
    return 0;
}

double funct(double x)
{
    return pow(x,3)+3;
}
