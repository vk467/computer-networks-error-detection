#include<stdio.h> 

void red () {
  printf("\033[1;31m");
}

void reset () {
  printf("\033[0m");
}

void yellow() {
  printf("\033[1;33m");
}

void green() {
  printf("\033[0;32m");
}

void blue() {
  printf("\033[0;34m");
}

void clock(){
    int i;
    red();
    printf("\nCLOCK\n");
    reset();
    printf("     ");
    for(i=0;i<8;i++)
    printf(" _______        ");
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++)
    printf("|       |       ");
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++)
    printf("|       |_______"); 
    printf("\n");

}


void uni(int a[8]){
    int i;
    red();
    printf("\nUnipolar\n");
    blue();
    printf("5 V  ");
    reset();
    for(i=0;i<8;i++)
    {
        if(a[i] && a[i-1]==0){
            printf(" _______________");
            
        }else if(a[i]){
            printf("________________");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++)
    {
        if(!i){
            printf("                ");
        }
        else if(a[i] && a[i-1]==0){
            printf("|               ");
            
        }else if(a[i]){
            printf("                ");
        }
        else if(a[i-1]==1){
            printf("|               ");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    blue();
    printf("0 V  ");
    reset();
    for(i=0;i<8;i++)
    {
        if(!i && a[i]){
            printf("                ");
        }
        else if(a[i] && a[i-1]==0){
            printf("|               ");
            
        }
        else if(a[i]){
            printf("                ");
        }
        else if(a[i-1]==0){
            printf("________________");
        }else{
            printf("|_______________");
        }
    }

    printf("\n");
}


void NRZL(int a[8]){
    int i;
    red();
    printf("\nNRZ-L\n");
    reset();
    blue();
    printf("Vcc  ");
    reset();
    for(i=0;i<8;i++)
    {
        if( !a[i] && a[i-1]==1){
            printf(" _______________");
            
        }else if(!a[i]){
            printf("________________");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++)
    {
        if(!i){
            printf("                ");
        }
        else if(!a[i] && a[i-1]==1){
            printf("|               ");
            
        }else if(!a[i]){
            printf("                ");
        }
        else if(a[i-1]==0){
            printf("|               ");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++)
    {
        if(!i){
            printf("                ");
        }
        else if(!a[i] && a[i-1]==1){
            printf("|               ");
            
        }else if(!a[i]){
            printf("                ");
        }
        else if(a[i-1]==0){
            printf("|               ");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++)
    {
        if(!i){
            printf("                ");
        }
        else if(!a[i] && a[i-1]==1){
            printf("|               ");
            
        }else if(!a[i]){
            printf("                ");
        }
        else if(a[i-1]==0){
            printf("|               ");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    blue();
    printf("-Vcc ");
    reset();
    for(i=0;i<8;i++)
    {
        if(!a[i] && a[i-1]==1){
            printf("|               ");   
        }
        else if(!a[i]){
            printf("                ");
        }
        else if(a[i-1]==1 || !i){
            printf("________________");
        }else{
            printf("|_______________");
        }
    }

    printf("\n");
}

void NRZI(int a[8]){
    int i;
    int f[8];
    int flag;
    red();
    printf("\nNRZ-I\n");
    reset();
    flag=0;
    for(i=0;i<8;i++){
        if(a[i]){
            flag=!flag;
            f[i]=flag;
        }
        else{
            f[i]=flag;
        }
    }

    blue();
    printf("Vcc  ");
    reset();
    for(i=0;i<8;i++)
    {
        if( !f[i] && f[i-1]==1){
            printf(" _______________");
            
        }else if(!f[i]){
            printf("________________");
        }
        else{
            printf("                ");
        }
    }

    printf("\n");
    printf("     ");
    for(i=0;i<8;i++)
    {
        if(!i){
            printf("                ");
        }
        else if(!f[i] && f[i-1]==1){
            printf("|               ");
            
        }else if(!f[i]){
            printf("                ");
        }
        else if(f[i-1]==0){
            printf("|               ");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++)
    {
        if(!i){
            printf("                ");
        }
        else if(!f[i] && f[i-1]==1){
            printf("|               ");
            
        }else if(!f[i]){
            printf("                ");
        }
        else if(f[i-1]==0){
            printf("|               ");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++)
    {
        if(!i){
            printf("                ");
        }
        else if(!f[i] && f[i-1]==1){
            printf("|               ");
            
        }else if(!f[i]){
            printf("                ");
        }
        else if(f[i-1]==0){
            printf("|               ");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    blue();
    printf("-Vcc ");
    reset();
    for(i=0;i<8;i++)
    {
        if(!f[i] && f[i-1]==1){
            printf("|               ");
            
        }
        else if(!f[i]){
            printf("                ");
        }
        else if(f[i-1]==1 || !i){
            printf("________________");
        }else{
            printf("|_______________");
        }
    }

    printf("\n");
}



void RZ(int a[8]){
    int i;
    red();
    printf("\nRZ\n");
    reset();
    blue();
    printf("Vcc  ");
    reset();

    for(i=0;i<8;i++){
        if(a[i]){
            printf(" _______        ");
        }
        else{
            printf("                ");
        }
    }

    printf("\n");
    printf("     ");
    for(i=0;i<8;i++){
        if(a[i]){
            printf("|       |       ");
        }
        else{
            printf("                ");
        }
    }
    printf("\n");
    blue();
    printf("0 V  ");
    reset();
    for(i=0;i<8;i++){
        if(a[i]){
            printf("|       |_______");
        }
        else{
            printf("         _______");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++){
        if(a[i]){
            printf("                ");
        }
        else{
            printf("|       |       ");
        }
    }
    printf("\n");
    blue();
    printf("-Vcc ");
    reset();
    for(i=0;i<8;i++){
        if(a[i]){
            printf("                ");
        }
        else{
            printf("|_______|       ");
        }
    }
    
    printf("\n");
}



void manch(int a[8]){
    int i;
    red();
    printf("\nMANCHESTER\n");
    printf("\n");
    reset();
    blue();
    printf("Vcc  ");
    reset();
    for(i=0;i<8;i++){
        if(a[i]){
            printf("         _______");
        }
        else if(!a[i-1]){
            printf(" _______        ");
        }
        else{
            printf("________        ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++){
        if (a[i] && a[i-1]){
            printf("|       |       ");
        }
        else if(a[i] || (!a[i] && a[i-1]) || (!i && !a[i])){
            printf("        |       ");
        }
        else {
            printf("|       |       ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++){
        if(!i && !a[i]){
            printf("        |       ");
        }
        else if(a[i] && a[i-1]){
            printf("|       |       ");
        }
        else if (!a[i] && !a[i-1]){
            printf("|       |       ");
        }
        else{
            printf("        |       ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++){
        if(!i && !a[i]){
            printf("        |       ");
        }
        else if(a[i] && !a[i-1]){
            printf("        |       ");
        }
        else if(a[i] || (!a[i] && !a[i-1])){
            printf("|       |       ");
        }
        else{
            printf("        |       ");
        }
    }
    printf("\n");
    blue();
    printf("-Vcc ");
    reset();
    for(i=0;i<8;i++){
        if(!i && !a[i]){
            printf("        |_______");
        }
        else if(a[i] && !a[i-1]){
            printf("________|       ");
        }
        else if(a[i]){
            printf("|_______|       ");
        }
        else if(!a[i] && !a[i-1]){
            printf("|       |_______");
        }
        else{
            printf("        |_______");
        }
    }
    printf("\n");
}

void diff_manch(int a[8]){
    int i;
    red();
    printf("\nDIFFERENTIAL MANCHESTER\n");
    reset();
    blue();
    printf("Vcc  ");
    reset();
    for(i=0;i<8;i++){
        if(!a[i]){
            printf("         _______");
        }
        else if(a[i-1]){
            printf(" _______        ");
        }
        else{
            printf("________        ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++){
        if(!i && !a[i]){
            printf("        |       ");
        }
        else if (!a[i] && !a[i-1]){
            printf("|       |       ");
        }
        else if(!a[i] || (a[i] && !a[i-1])){
            printf("        |       ");
        }
        else {
            printf("|       |       ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++){
        if(!i && !a[i]){
            printf("        |       ");
        }
        else if(!a[i] && !a[i-1]){
            printf("|       |       ");
        }
        else if (a[i] && a[i-1]){
            printf("|       |       ");
        }
        else{
            printf("        |       ");
        }
    }
    printf("\n");
    printf("     ");
    for(i=0;i<8;i++){
        if(!i && !a[i]){
            printf("        |       ");
        }
        else if(!a[i] && a[i-1]){
            printf("        |       ");
        }
        else if(!a[i] || (a[i] && a[i-1])){
            printf("|       |       ");
        }
        else{
            printf("        |       ");
        }
    }
    printf("\n");
    blue();
    printf("-Vcc ");
    reset();
    for(i=0;i<8;i++){
        if(!i && !a[i]){
            printf(" _______|       ");
        }
        else if(!a[i] && a[i-1]){
            printf("________|       ");
        }
        else if(!a[i]){
            printf("|_______|       ");
        }
        else if(a[i] && a[i-1]){
            printf("|       |_______");
        }
        else{
            printf("        |_______");
        }
    }
    printf("\n");
}

void display(int a[8]){
    int i;
    printf("\n\n\n");
    printf("     ");
    yellow();
    for(i=0;i<8;i++)
    printf("   %d            ",a[i]);
    reset();
    printf("\n");

}


//main driver

void main()   
{  
    int i;
    // int a[8]={1,0,1,1,0,0,0,1};

    int a[8];
    printf("Enter 8 bit data one by one: ");
    for(i=0;i<8;i++){
        scanf("%d",&a[i]);
    }

    display(a);
    clock();  
    uni(a);  
    NRZL(a);
    NRZI(a); 
    RZ(a);
    manch(a);
    diff_manch(a);
    

}  