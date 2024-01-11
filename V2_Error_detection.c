#include<stdio.h>

int carry = 0;


int* fulladd( int A[], int B[],int n ){
int *s;

for(int i=n-1;i>=0;i--){
    s[i]=carry ^ A[i] ^ B[i];
    carry = ((A[i] & B[i]) | (B[i] & carry) | (carry & A[i]));
}
return s;
}

int* complement(int A[],int n){
    int *c;
    for(int i=0;i<n;i++){
        if(A[i]) c[i]=0;
        else c[i]=1;
    }
    return c;
}


void main()
{int choice;
int dataword[5];
int codeword_r[5];
printf("1.single bit parity check\n2.LRC and VRC\n3.CRC\n4.Check_sum");
printf("\nEnter choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
{printf("Enter dataword:");
for(int i=0;i<=3;i++)
{scanf("%d",&dataword[i]);
}
dataword[4]=dataword[0];
for(int i=1;i<=3;i++)
{dataword[4]=dataword[4]^dataword[i];
}
printf("Codeword sent from encoder/sender: ");
for(int i=0;i<=4;i++)
{printf("%d",dataword[i]);
}
printf("\nEnter codeword received by the decoder/receiver:");
for(int i=0;i<=4;i++)
{scanf("%d",&codeword_r[i]);
}int temp=codeword_r[0];
for(int i=1;i<=3;i++)
{temp=temp^codeword_r[i];
}
if(temp==codeword_r[4])
{
printf("Message is recovered successfully:");
for(int i=0;i<=3;i++)
{printf("%d",codeword_r[i]);
} }
else{
printf("Message received is corrupted");
}
break; }
case 2:{int dataword_t[4][8];
int codeword_rt[4][8];
for(int i=0;i<=2;i++)
{
printf("Enter dataword""%d"":",i);
for(int j=0;j<=6;j++)
{
scanf("%d",&dataword_t[i][j]);
} }
for (int j=0;j<=2;j++)// parity calculation
{
dataword_t[j][7]=dataword_t[j][0];
for(int i=1;i<=6;i++)
{dataword_t[j][7]=dataword_t[j][7]^dataword_t[j][i];// row parity
} }
for (int j=0;j<=7;j++)// parity calculation
{
dataword_t[3][j]=dataword_t[0][j];
for(int i=1;i<=2;i++)
{dataword_t[3][j]=dataword_t[3][j]^dataword_t[i][j];// column parity
} }
printf("Codewords sent from encoder/sender: ");
for(int j=0;j<=3;j++)
{for(int i=0;i<=7;i++)
{
printf("%d",dataword_t[j][i]);// row parity
}
printf("\n");
}
for(int i=0;i<=3;i++)
{printf("Enter codeword ""%d"" received:",i);
for(int j=0;j<=7;j++)
{
scanf("%d",&codeword_rt[i][j]);
}
}
int temp2;
int row=0,column=0;
for (int j=0;j<=7;j++)// parity calculation
{temp2=codeword_rt[0][j];
// codeword_rt[3][j]=codeword_rt[0][j];
for(int i=1;i<=2;i++)
{temp2=temp2^codeword_rt[i][j];// column parity
}
if(codeword_rt[3][j]==temp2)
{if(j<7)
continue;
else
column=1;
}
else{
printf("\nMesggae corrupted -->column");
break;
}
}
int temp;
for(int j=0;j<=2;j++)
{temp=codeword_rt[j][0];
for(int i=1;i<7;i++)
{temp=temp^codeword_rt[j][i];
}
if(temp==codeword_rt[j][7])
{if(j<2)
continue;
row=1;
}
else{
printf("\nMessage corrupted ---> row");
break;
}
}
if(row==1&&column==1)
{
printf("\nMessgae received successfully");
}
break;
}











case 3:
{ // CRC encoding
int dataword_c[50];
int ip_to_gen[50];
int divisor[25];
int rem[25];
int k,n,g,d;

printf("Enter dataword size k: ");
scanf("%d",&k);

printf("Enter dataword: ");
for(int i=0;i<k;i++)
scanf("%d",&dataword_c[i]);

printf("Enter divisor size: ");
scanf("%d",&d);

g=d-1;
n=g+k;

for(int i=0;i<n;i++) //input to gen
{
if(i<k)
{
ip_to_gen[i]=dataword_c[i];
}
else{
ip_to_gen[i]=0;
}
}
printf("Enter divisor: "); //input divisor
for(int i=0;i<d;i++)
{
scanf("%d",&divisor[i]);
}
for(int i=0;i<n;i++)
rem[i]=ip_to_gen[i];

for(int i=0;i<k;i++)
{
    if(rem[0]==1)//divide with divisor
    {
        for(int j=0;j<d;j++)
        rem[j]=rem[j]^divisor[j];
    }
    else{ //use 0 as divisor
        for(int j=0;j<d;j++)
        rem[j]=rem[j]^0;
    }

    if(i<(k-1)){
        for(int i=1;i<=n;i++)
        {
        rem[i-1]=rem[i];
        }
    /*for(int i=0;i<4;i++) //print rem every time
    {
    printf("%d",rem[i]);
    }printf("\n");*/
        }

    else{
    /* for(int i=0;i<4;i++)
    {
    printf("%d",rem[i]);
    }printf("\n");*/
        for(int j=k,i=1;j<n&&i<=k;j++,i++) // insert last rem to dataword to make codeword
            dataword_c[j]=rem[i];
        }
    }
printf("Codeword sent from the encoder: ");
for(int i=0;i<n;i++)
{
printf("%d",dataword_c[i]);
}
// CRC decoding
int codeword_rc[50];
printf("\nEnter codeword received at decoder: ");
for(int i=0;i<n;i++) // input to checker as well
{
scanf("%d",&codeword_rc[i]);
}
/* for(int i=0;i<4;i++) //print divisor
{
printf("%d",divisor[i]);
}printf("\n");*/
// calculating syndrome
for(int i=0;i<n;i++)
{
    rem[i]=codeword_rc[i];
    }


for(int i=0;i<k;i++)
{

if(rem[0]==1)//divide with divisor
{for(int j=0;j<d;j++)
rem[j]=rem[j]^divisor[j];
}
else{ //use 0 as divisor
for(int j=0;j<d;j++)
rem[j]=rem[j]^0;
}


if(i<k-1)
{
for(int i=1;i<=n;i++)
{
rem[i-1]=rem[i];
}

}
else{printf("syndrome is: ");
for(int i=1;i<=g;i++)
{
printf("%d",rem[i]); //print syndrome
}printf("\n");
// check syndrome

if(rem[1]==0 && rem[2]==0 && rem[3]==0)
{
    printf("Data recovered: ");
    for(int i=0;i<k;i++)
        printf("%d",codeword_rc[i]);

}
else
{
    printf("\nError occured, received data discarded");

}
}

}break; 

}//case3










case 4:
{
int k,n;
int a[10][20];
int b[20],rec[20];
int *r;
printf("\nEnter size of dataword k: ");
scanf("%d",&k);

printf("\nEnter no. of dataword: ");
scanf("%d",&n);

for(int i=0;i<n;i++){
    printf("\nEnter dataword %d : ",i+1);
    for(int j=0;j<k;j++){
        scanf("%d",&a[i][j]);
    }
}

// a[0][0]=1;
// a[0][1]=0;
// a[0][2]=0;
// a[0][3]=1;
// a[0][4]=1;
// a[0][5]=0;
// a[0][6]=0;
// a[0][7]=1;

// a[1][0]=1;
// a[1][1]=1;
// a[1][2]=1;
// a[1][3]=0;
// a[1][4]=0;
// a[1][5]=0;
// a[1][6]=1;
// a[1][7]=0;

// a[2][0]=0;
// a[2][1]=0;
// a[2][2]=1;
// a[2][3]=0;
// a[2][4]=0;
// a[2][5]=1;
// a[2][6]=0;
// a[2][7]=0;

// a[3][0]=1;
// a[3][1]=0;
// a[3][2]=0;
// a[3][3]=0;
// a[3][4]=0;
// a[3][5]=1;
// a[3][6]=0;
// a[3][7]=0;


for(int i=1;i<n;i++){
    if (i==1) 
        r=fulladd(a[i-1],a[i],k);
    else
        r=fulladd(a[n],a[i],k);


    for(int i=0;i<k;i++){
        a[n][i]=r[i];
    }

    // for(int i=0;i<k;i++){
    // printf("%d",r[i]);
    // }
}

if(carry){
    for(int i=0;i<k;i++){
      b[i]=0;    
    }
    r=fulladd(a[n],b,k);
    for(int i=0;i<k;i++){
        a[n][i]=r[i];
    }
}

printf("\nThe checksum sent is:");
r=complement(a[n],k);
for(int i=0;i<k;i++){
        a[n][i]=r[i];
        printf("%d",r[i]);
    }


//receiver
printf("\nEnter the received checksum :");
for(int i=0;i<k;i++){
        scanf("%d",&rec[i]);
    }
for(int i=1;i<n;i++){
    if (i==1) 
        r=fulladd(a[i-1],a[i],k);
    else
        r=fulladd(a[n],a[i],k);

    for(int i=0;i<k;i++){
        a[n][i]=r[i];
    }

    // for(int i=0;i<k;i++){
    // printf("%d",r[i]);
    // }
}

r=fulladd(a[n],rec,k);
for(int i=0;i<k;i++){
   a[n][i]=r[i];
}

if(carry){
    for(int i=0;i<k;i++){
      b[i]=0;    
    }
    r=fulladd(a[n],b,k);
    for(int i=0;i<k;i++){
        a[n][i]=r[i];
    }
}

printf("\nThe checksum at receiver is: ");
r=complement(a[n],k);
int count=0;
for(int i=0;i<k;i++){
        printf("%d",r[i]);
        if(!r[i]) count+=1;
    }
if(count==k){
    printf("\n\nNO Error. Data is accepted.");
}
else{
    printf("\n\nError!! Data is corrupted. Entire packet is dropped.");
}

break;
} } }//void main