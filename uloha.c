#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
void vypKoef(float *korene,short k,float* q){

     if(k!=0)
     q[0]=1; 
     for(int i=0;i<k;i++){
          for(int j=i;j>=0;j--){
               q[j+1]-=korene[i]*q[j];
}
}
}


void vypKoefKv(float *a, float *b,float *c) {

     float D;
     
     do{
     *a = rand() % 21 - 10;
     }while(a==0); 
     do{*b = rand() % 21 - 10;
     }while(b==0); 
  
     D = rand() % 10 - 10;
     *c = ((*b) * (*b) - D)/(4*(*a));
}


//to nasobenie polynomov mi neide
void nasobPol(float *poly1, int rad1, float *poly2, int rad2, float *koef) {
  
     for (int i = 0; i <= rad1 + rad2; i++) {
     koef[i] = 0;
     }
  
     for (int i = 0; i <= rad1; i++) {
     for (int j = 0; j <= rad2; j++) {
     koef[i + j] += poly1[i] * poly2[j];
}
}
}


char nahodny_polynom(float *q,short rad,short k,float* koef){
  
     float* korene = calloc(k, sizeof(float));//bude sa generovat nejake k korenov
     float koren;
     char flag=1;
     int pocPol=(rad-k)/2;//pocet polynomov rezidua
     float **quadratics = (float **)malloc((pocPol) * sizeof(float *));//pole pre polia s troma koeficientmi pre kazdy pol z rezidua (alokovali pamat pre polynomy)
     
     if((k>rad || (rad%2!=0 && k%2==0)||(rad%2==0 && k%2!=0) )&&k!=0){
          return 0;
}

     if(k!=0){
          if(k<rad) 
               korene[0]=(float)0.;
          else
               korene[0]=(float)(rand()%21-10);
}

     for(int j=1;j<k;j++){
    
          koren=(float)(rand()%21-10);
    
          for(int i=0;i<k;i++){
      
               if(korene[i]==koren){
                    flag=0;
                    break;
}     
}
          if(flag) korene[j]=koren;
          else j--;
}
  
     printf("Korene su: ");
     
     for(int j=0;j<k;j++){ 
          printf("%.2f \n",korene[j]);
}
     printf("\n");
  
     vypKoef(korene,k,q);
  
     if(k!=rad){
          
          for (int i = 0; i < pocPol; i++) {
          quadratics[i] = (float *)malloc(3 * sizeof(float));//pre kazdy pol alokuje pamat pre 3 koeficienty
          vypKoefKv(&quadratics[i][0], &quadratics[i][1], &quadratics[i][2]);
          printf("Reziduum %d: ",i+1);
          printf("(%.2fx^2 + %.2fx + %.2f)\n",quadratics[i][0],quadratics[i][1],quadratics[i][2]);
}
    
     free(koef);
    
//tu nasobenie polynomov rezidua: 
     koef = (float *)calloc((2 * pocPol + 1), sizeof(float));//koeficienty vynasobeneho rezidua
     koef[0] = 1.;
     for (int i = 0; i < pocPol; i++) {
          float *tempKoef = (float *)calloc((i * 2 + 3), sizeof(float));
          nasobPol(koef, i * 2, quadratics[i], 2, tempKoef);//vynasobme vseykky polynomy s ktorych sa sklada reziduum
          free(koef);
          koef = tempKoef;
}
}
     printf("Rovnica: ");
     return 1;
}
  
                                                                 

int main(){

     srand(time(0));
     short rad=0,k=0;
     float* q = calloc(rad + 1, sizeof(float));
     float* koef = calloc(1, sizeof(float));

     printf("Zadajte stupen polynomu: ");
     scanf("%hd", &rad);
     printf("Zadajte pocet korenov: ");
     scanf(" %hd", &k);
  
     if (nahodny_polynom(q,rad,k,koef)){
          if(k!=0){
               printf("(");
               for (int i=0;i<=rad;i++){
                    if(q[i]!=0.){
                         if(q[i]>=0 && i!=0)
                         printf("+");
                         printf("%.3f",q[i]);
                         printf("x^%hd ",(short)(rad-i));
}}
               printf(")");}
          //neide mi nasobenie polynomov :(
          if(k!=rad){
               printf("(krat vsetky polynomy rezidua)");}
      
               /*if(k!=rad){
               printf("(");
               for(int i=0;i<=rad-k;i++){
               if(koef[i]!=0.){
               if(koef[i]>=0 && i!=0)
               printf("+");
               printf("%.3f",koef[i]);
               printf("x^%hd ",(short)(rad-k-i));}
        
}
          printf(")");}*/
          printf("=0\n");}
     else 
          printf("Nepodarilo sa vygenerovat polynom");
  
     free(q);
}

