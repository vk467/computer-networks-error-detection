#include<stdio.h>

void reset () {
  printf("\033[0m");
}

void yellow() {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}

int XOR(int v[],int n){
    int i,d;
    d=0;
    for(i=0;i<n;i++)
    {
        d=d^v[i];
    }
    return d;
}


void single_parity(){
    char d[4],r[5];
    int data[4],code[5],code_r[5],data_r[4];
    int i,p,syndrome;
    printf("\nEnter 4-bit Data: ");
    for(i=0;i<4;i++)
        scanf("\n%c",&d[i]);

    for(i=0;i<4;i++)
    {
       if (d[i]=='1') 
            data[i]=1;
       else 
            data[i]=0;
    }

    p=XOR(data,4);
    for(i=0;i<5;i++){
        if(i<4)
            code[i]=data[i];
        else
            code[i]=p;
    }

    
    printf("\nThe Codeword sent by the Sender is: ");
    yellow();
    for(i=0;i<5;i++)
        printf("%d",code[i]);
    reset();

    printf("\n\nEnter the codeword received by the receiver: ");
    for(i=0;i<5;i++)
        scanf("\n%c",&r[i]);
        
    for(i=0;i<5;i++)
    {
       if (r[i]=='1') 
            code_r[i]=1;
       else 
            code_r[i]=0;
    }
    syndrome=XOR(code_r,5);
    yellow();
    if(syndrome){
        printf("\n! ! ! Error in received codeword. ! ! !");
        
    }
    else{
        printf("\nReceived Dataword is: ");
        for(i=0;i<4;i++)
            printf("%d",code_r[i]);
        
    }
    reset();
}

void parity2D(){
    char d[4][7],r[5][8];
    int data[4][7],code[5][8],code_r[5][8],data_r[4][7];
    int i,j,temp[4],t[5],s,sr[5],sc[8];
    
    for(i=0;i<4;i++)
    {
        printf("\nEnter 7-bit Data: ");
        for(j=0;j<7;j++)
            scanf("\n%c",&d[i][j]);
    }
        
    for(i=0;i<4;i++){
        for(j=0;j<7;j++)
        {
            if (d[i][j]=='1') 
                data[i][j]=1;
            else 
                data[i][j]=0;
         }
    }

    for(i=0;i<4;i++){                  //row parity generation
        for(j=0;j<7;j++){
            code[i][j]=data[i][j];
        }
        code[i][7]=XOR(data[i],7);
    }

    for(j=0;j<8;j++){                   //column parity generation
        for(i=0;i<4;i++){
            temp[i]=data[i][j];
        }
        code[4][j]=XOR(temp,4);
    }

    
    printf("\nThe Series of Codeword sent by the Sender is: ");
    yellow();
    for(i=0;i<5;i++){
        for(j=0;j<8;j++)
        {
            printf("%d",code[i][j]);
         }
        printf(" ");
    }
    reset();

    printf("\n\nEnter the codeword(series with space) as received by the receiver: ");
    for(i=0;i<5;i++)
    {
        for(j=0;j<8;j++)
            scanf("\n%c",&r[i][j]);
    } 
    
    for(i=0;i<5;i++){
        for(j=0;j<8;j++)
        {
            if (r[i][j]=='1') 
                code_r[i][j]=1;
            else 
                code_r[i][j]=0;
         }
    }

    s=0;
    for(i=0;i<5;i++){                  //row parity check
        sr[i]=XOR(code_r[i],8);
        if(sr[i]) s+=1;
    }

    for(j=0;j<8;j++){                   //column parity check
        for(i=0;i<5;i++){
            t[i]=code_r[i][j];
        }
        sc[j]=XOR(t,5);
        if(sc[j]) s+=1;
    }


    yellow();
    if(s){
        printf("\n! ! ! Error in received codeword. ! ! !");
        for(i=0;i<4;i++){                   
            for(j=0;j<7;j++){
                if(sr[i] && sc[j])
                  printf("\nError in Data-%d at position-%d",i+1,j+1);
            }
        }
    }
    else{
        printf("\nReceived Set of Dataword:\n");
        for(i=0;i<4;i++){
            for(j=0;j<7;j++)
            {
                printf("%d",code_r[i][j]);
            }
            printf("\n");
        } 
    }
    reset();
}

int crc()
{
int i,f[20],n[50],div[50],j,k,temp,quotient[20],z[10],y[50],encode[10],g[20],q[20],d[20],c,ks;
printf("enter the data size k:");
scanf("%d",&k);
printf("\nenter the data to be sent: ");
for(i=0;i<k;i++)
{
scanf("%d",&n[i]);
}
for(i=0;i<k;i++)
{
    y[i] = n[i];
}

printf("\nenter the key size: ");
scanf("%d",&ks);
printf("\nenter the key: ");
for(i=0;i<ks;i++)
{
scanf("%d",&div[i]);
}

c=k+ks-1;
for(i=k;i<c;i++)
{
n[i]=0;
}
for(i=0;i<k;i++)
{
temp=i;
if(n[i]==1)
{
for (j=0;j<ks;j++)
{
if (n[temp]==div[j])
{n[temp]=0;
f[j]=0;}
else
{n[temp]=1;
f[j]=1;}
temp=temp+1;

}
quotient[i]=1;
}
else
quotient[i]=0;
}

printf("\n CRC is :");

for(j=1;j<ks;j++)
printf("%d",f[j]);

for(i=0;i<k;i++)
encode[i] = y[i];
for(i=k,j=1;i<c;i++,j++)
encode[i] = f[j];

printf("\nCodeword sent is: ");
for(i=0;i<c;i++)
printf("%d",encode[i]);


//Reciever part

printf("\n\n enter the received data:\n");
for(i=0;i<c;i++)
{
scanf("%d",&encode[i]);
}

for(i=0;i<k;i++)
{
temp=i;
if(encode[i]==1)
{
for (j=0;j<ks;j++)
{
if (encode[temp]==div[j])
{encode[temp]=0;
g[j]=0;}
else
{encode[temp]=1;
g[j]=1;}
temp=temp+1;

}
q[i]=1;
}
else
q[i]=0;
}


printf("\n CRC is : ");

for(j=1;j<ks;j++)
printf("%d",g[j]);

if(!g[1] && !g[2]  && !g[3]){
    printf("\nThe decoded dataword is: ");
    for(i=0;i<k;i++){
        printf("%d",encode[i]);
    }
}
else{
    printf("\nError in received Codeword !!");
}

return 0;
}


void main()
{
    int n=1;
    
    while(n){

        printf("\n\nMenu:\n1.Single Parity Check\n2.2D parity check(LRC and VRC)\n3.CRC(Cyclic Redundancy check)\n4.CheckSum\n5.Quit");
        red();
        printf("\n\nEnter your option: ");
        scanf("%d",&n);
        reset();
        switch(n){
            case 1: {
                single_parity();
                break;
            }
            case 2: {
                parity2D();
                break;
            }
            case 3: {
                crc();
                break;
            }
            case 4: {
                single_parity();
                break;
            }
            default: break;

        }
    }
    printf("\nExited...");

}