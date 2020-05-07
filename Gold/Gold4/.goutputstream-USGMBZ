#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double norma(double*a,int n);
int index(int i,int j,int n);
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
 double qq0[4];
 double p,q;
 double rtr;
 double inv1,inv2; inv1=inv2=0.;
 a=new double[(n*(n+1))/2];
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
    
    if(fscanf(fp,"%lf",&rtr)!=1)
    {
     printf("Error in file\n");
     fclose(fp);
     delete[]a;
     return -1;
    }
    if(i<=j){a[index(i,j,n)]=rtr;}
    if(i>j&&a[index(i,j,n)]!=rtr)
    {
     printf("%f %f\n",a[index(i,j,n)],rtr);
     printf("Matrix isn't symetric\n");
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
      a[index(i,j,n)]=fabs(i-j)+0.;
//   printf("%f ",a[i*n+j]);
   }
  // printf("\n");
  }
 }
 for(i=0;i<n;i++)
 {
  inv1+=a[index(i,i,n)];
  for(j=0;j<n;j++)
  {
   inv2+=a[index(i,j,n)]*a[index(j,i,n)];
  }
 }
 for(i=0;i<n;i++)
 { if(i>10){printf("\n");break;}
  for(j=0;j<n;j++)
  {if(i>10){break;}
   printf("%f ",a[index(i,j,n)]);
  }
  printf("\n");
 }
 double inv01,inv02;
 //return 0;
 inv01=inv1;inv02=inv2;
 printf("inv01=%f inv02=%f\n",inv1,inv2);
 double norm;
 double norma1=norma(a,n);

 //////privedenie matrizi 3-diagonalnomy vidy
 
  double cur1; 
  double cur2; 
  double cur3;
  double cur4;
  double* buf;
  buf=new double[n];
  for(i=0;i<n;i++){buf[i]=0.;}
  for(i=0;i<n-2;i++)
 {

   for(j=i+2;j<n;j++)
   {
    norm=1./sqrt(a[index(i,i+1,n)]*a[index(i,i+1,n)]+a[index(i,j,n)]*a[index(i,j,n)]);
    p=a[index(i,i+1,n)]*norm;///cos
    q=a[index(i,j,n)]*norm;//sin
    
    for(l=i;l<n;l++)
   {     
    cur1=a[index(l,i+1,n)];cur2=a[index(l,j,n)];
    a[index(l,i+1,n)]=cur1*p+cur2*q;
   if(l!=i+1){a[index(l,j,n)]=-cur1*q+cur2*p;}
   if(l==i+1){cur3=-cur1*q+cur2*p;}
   if(l==j){cur4=a[index(l,i+1,n)];}
   }
     cur1=a[index(i+1,i+1,n)]; cur2=a[index(j,j,n)]; 
     a[index(i+1,i+1,n)]=cur1*p+q*cur4;
     a[index(j,i+1,n)]=-cur1*q+p*cur4;
     a[index(j,j,n)]=-cur3*q+p*cur2;

  }
  
  norm=0.;
   
 }
 inv1=inv2=0.;
 for(i=0;i<n;i++)
 {
  inv1+=a[index(i,i,n)];
  for(j=0;j<n;j++)
  {
   inv2+=a[index(i,j,n)]*a[index(j,i,n)];
  }
 }
 printf("inv1-inv01=%e inv2-inv02=%e\n",inv1-inv01,inv2-inv02);
 double*trd;
 double s,a1,a2;
 double qq[4]; qq[0]=0.;qq[1]=0.;qq[2]=0.;qq[3]=0.;
 trd=new double[3*n];
 double x1,x2;
 double sum=0.;
 for(i=0;i<3*n;i++)
 {
  trd[i]=0.;
 }
 for(i=0;i<n-1;i++)
 {
  trd[i]=a[index(i,i+1,n)];
  trd[n+i]=a[index(i,i,n)];
  trd[2*n+i]=trd[i];
 }
 trd[n+n-1]=a[index(n-1,n-1,n)];
 //write(trd,n,n);
 //write(trd,n,n);
 double ved=0.; 
 inv1=inv2=0.;
///////QR-decompozition 
for(int k=n;k>2;k--)
{
 
 //ved=0.;
 while(fabs(trd[2*n+k-2])>1.e-10*norma1)
 { 
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //printf("%e\n",fabs(trd[2*n+k-2]));
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
 
}

sum=0.;

printf("lambda%d=%f\n",n-k+1,ved);
inv1+=ved;inv2+=ved*ved;
}
//////reshaem kvadratnoe yravnenie dlia poslednih 2 lambda;

double B,C,D;
B=trd[n]+trd[n+1];
C=trd[n]*trd[n+1]-trd[0]*trd[0];
D=sqrt(B*B-4*C);
printf("lambda%d=%f\nlambda%d=%f\n",n-1,(B+D)/2.,n,(B-D)/2.);
inv1+=(B+D)/2.+(B-D)/2.;
inv2+=((B+D)/2.)*((B+D)/2.)+((B-D)/2.)*((B-D)/2.);
printf("inv1-inv01=%e inv2-inv02=%e\n",inv1-inv01,inv2-inv02);
 delete[]trd; 
 delete[]a;
 //delete[]b;
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
      sum+=fabs(a[index(i,j,n)]);
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
int index(int i,int j,int n)
{
 int cur;
 if(i<j) {cur=i;i=j;j=cur;}
 cur=0;
 for(int t=0;t<i;t++)
 {
  cur+=t+1;
 }
 cur+=j;
 return cur;
}
