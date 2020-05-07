#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double norma(double*a,int n);
void write(double*trd,int n,int m);

int main(int argc,char*argv[])
{
 int n,i,j,l,m;
 if(argc<2||argc>3||(n=atoi(argv[1]))<=0)
 {
  printf("Invalid Format\n");
  return -1;
 }
 double*a;
 double*b;
 double qq0[4];
 double p,q;
 double inv1,inv2; inv1=inv2=0.;
 a=new double[n*n];
 if(argc==3)
 {
  FILE*fp;
  if((fp=fopen(argv[2],"r"))==NULL)
  {
   printf("File don't exist\n");
   delete[]a;
   return -1;
  }
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    if(fscanf(fp,"%lf",&a[i*n+j])!=1)
    {
     printf("Error in file\n");
     fclose(fp);
     delete[]a;
     return -1;
    }
   }
  }
 }
 if(argc==2)
 {
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
      a[i*n+j]=fabs(i-j)+0.;
//   printf("%f ",a[i*n+j]);
   }
  // printf("\n");
  }
 }
 for(i=0;i<n;i++)
 {
  inv1+=a[i*n+i];
  for(j=0;j<n;j++)
  {
   inv2+=a[i*n+j]*a[j*n+i];
  }
 }
 printf("inv1=%f inv2=%f\n",inv1,inv2);
 double norma1=norma(a,n);
 b=new double[n*n];
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   b[i*n+j]=a[i*n+j];
  }
 }
 //////privedenie matrizi 3-diagonalnomy vidy
 for(i=1;i<n-1;i++)
 {
 
  for(j=i+1;j<n;j++)
  {
   //  for(l=0;l<n*n;l++)
   //  {
   // b[l]=a[l];
   // }
   p=a[(i-1)*n+i]/sqrt(a[(i-1)*n+i]*a[(i-1)*n+i]+a[(i-1)*n+j]*a[(i-1)*n+j]);
  q=a[(i-1)*n+j]/sqrt(a[(i-1)*n+i]*a[(i-1)*n+i]+a[(i-1)*n+j]*a[(i-1)*n+j]);
   for(l=0;l<n;l++)
   {    
    b[l*n+i]=a[l*n+i]*p+a[l*n+j]*q;
    b[l*n+j]=-a[l*n+i]*q+a[l*n+j]*p;
   }
   for(m=0;m<n;m++)
   {
    a[i*n+m]=b[i*n+m]*p+b[j*n+m]*q;
    a[j*n+m]=-b[i*n+m]*q+b[j*n+m]*p;
    ////
    b[i*n+m]=a[i*n+m]; b[j*n+m]=a[j*n+m];
    //// 
    for(l=0;l<n;l++)
    {
     if(l==i||l==j){continue;}
     a[l*n+m]=b[l*n+m];
    }
    
   }
  }
 }
 inv1=inv2=0.;
 for(i=0;i<n;i++)
 {
  inv1+=a[i*n+i];
  for(j=0;j<n;j++)
  {
   inv2+=a[i*n+j]*a[j*n+i];
  }
 }
 printf("inv1=%f inv2=%f\n",inv1,inv2);
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("%f ",a[i*n+j]);
  }
  printf("\n");
 }
 printf("\n");
 
 double*trd;
 double s,a1,a2;
 double qq[4]; qq[0]=0.;qq[1]=0.;qq[2]=0.;qq[3]=0.;
 trd=new double[3*n];
 double norm,x1,x2;
 double sum=0.;
 for(i=0;i<3*n;i++)
 {
  trd[i]=0.;
 }
 for(i=0;i<n-1;i++)
 {
  trd[i]=a[i*n+i+1];
  trd[n+i]=a[i*n+i];
  trd[2*n+i]=trd[i];
 }
 trd[n+n-1]=a[(n-1)*n+n-1];
 double ved=0.; 

for(int k=n;k>2;k--)
{
 
 //ved=0.;
 while(fabs(trd[2*n+k-2])>1.e-9*norma1)
 {
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  inv1=inv2=0.;
  ved=trd[n+k-1];
//  printf("ved=%f\n",ved);
  for(j=0;j<k;j++)
  {
   trd[n+j]-=ved;
  }
  //write(trd,n,k);
 for(i=0;i<k-1;i++)
 {
  //write(trd,n,m);
 //printf("%d\n",i);
  a1=trd[n+i]; a2=trd[2*n+i];
  s=a2*a2;
  norm=sqrt(a1*a1+s);
  x1=a1-norm; x2=a2;
  norm=sqrt(x1*x1+s);
   if(norm<1.e-15){printf("tttttt\n");continue;}
  x1=x1/norm;x2=x2/norm;
  //printf("%f %f %f\n",a1,a2,s);
  qq[0]=x1*x1;qq[1]=qq[2]=x1*x2;qq[3]=x2*x2;
  for(j=0;j<4;j++)
  {
  //printf("%d %f\n",j,qq[j]);
 // qq[j]/=(a1-s)*(a1-s)+a2*a2;
   qq[j]*=2;
   
  }
  qq[0]=1-qq[0];
  qq[1]=-qq[1];
  qq[2]=-qq[2];
  qq[3]=1-qq[3];
// printf("%f %f \n%f %f\n",qq[0],qq[1],qq[2],qq[3]);
  a1=trd[n+i]; a2=trd[i]; 
  x1=trd[n*2+i]; x2=trd[n+i+1];
  trd[n+i]=qq[0]*a1+qq[1]*x1;
  trd[i]=qq[0]*a2+qq[1]*x2;
  trd[2*n+i]=qq[1]*a1+qq[3]*x1;
  trd[n+i+1]=qq[1]*a2+qq[3]*x2;
  trd[i+1]*=qq[3];
 // trd[2*n+i+1]*=qq[3];
  //write(trd,n,n);
//printf("%f %f \n%f %f\n",qq0[0],qq0[1],qq0[2],qq0[3]);
  if(i>0)
  {
   x1=trd[n+i-1]; x2=trd[i-1];
   a2=trd[n+i]; a1=trd[n*2+i-1];
   trd[n+i-1]=x1*qq0[0]+x2*qq0[1]; 
   trd[i-1]=x1*qq0[1]+x2*qq0[3];
   trd[2*n+i-1]=a1*qq0[0]+a2*qq0[1];
   trd[n+i]=a1*qq0[1]+a2*qq0[3];
  // printf("R*U\n");
  // write(trd,n,n);
  }
 
  if(i==k-2)
  {
   x1=trd[n+i]; x2=trd[i];
   a2=trd[n+i+1]; a1=trd[2*n+i];
   trd[n+i]=qq[0]*x1+qq[1]*x2;
   trd[i]=qq[1]*x1+qq[3]*x2;
   //printf("%f\n",a1);
   trd[2*n+i]=a1*qq[0]+a2*qq[1];
   trd[n+i+1]=a1*qq[1]+a2*qq[3];
   //printf("FINAL\n");
   //write(trd,n,n);
   for(j=0;j<n;j++){trd[j]=trd[2*n+j];}
  }
  for(j=0;j<4;j++) {qq0[j]=qq[j];}
 }
 for(j=0;j<k;j++)
  {
   trd[n+j]+=ved;
  }
  for(j=0;j<n;j++)
  {
   inv1+=trd[n+j];
   inv2+=(trd[n+j]*trd[n+j]+trd[j]*trd[j]+trd[2*n+j]*trd[2*n+j]);
  
  }
  //printf("inv1=%f inv2=%f\n",inv1,inv2);
  //write(trd,n,m);
}
//printf("\n");
sum=0.;
for(j=0;j<k;j++) {sum+=trd[n+j];}
//write(trd,n,k);
printf("\nsum=%f\n",sum);
printf("lambda%d=%f\n",n-k+1,ved);
}
//////reshaem kvadratnoe yravnenie dlia poslednih 2 lambda;

double B,C,D;
B=trd[n]+trd[n+1];
C=trd[n]*trd[n+1]-trd[0]*trd[0];
D=sqrt(B*B-4*C);
printf("lambda%d=%f\nlambda%d=%f\n",n-1,(B+D)/2.,n,(B-D)/2.);
 delete[]trd; 
 delete[]a;
 delete[]b;
 return 0;
}
double norma(double*a,int n)
{
  double sum=0.;
  double max=0.;
  for(int i=0;i<n;i++)
  {
    sum=0.;
   for(int j=0;j<n;j++)
   {
      sum+=fabs(a[i*n+j]);
   }
   if(sum>max){max=sum;}
  }
  return max;
}
void write(double*trd,int n,int m)
{
 double o=0.;
 for(int i=0;i<m;i++)
 {
  for(int j=0;j<m;j++)
  {
   if(i==j)
   {
    printf("%f ",trd[n+i]);
   }
   if(i==j-1)
   {
    printf("%f ",trd[i]);
   }
   if(i==j+1)
   {
    printf("%f ",trd[2*n+j]);
   }
   if(fabs(i-j)>1)
   {
    printf("%f ",o);
   } 
  }
  printf("\n");
 }
 printf("\n"); 
}
