#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*vezmime nase korene a podla nich vypocitame koeficienty*/
void vyp_koef(float* korene, short k, float* q) {
     if (k != 0)
          q[0] = 1; /*koeficienty vlozime do pola q*/
     for (int i = 0; i < k; i++){
          for (int j = i; j >= 0; j--)
               q[j + 1] -= korene[i] * q[j];
     }
}

/*vypocitame koeficienty kazdeho polynoma(kvadratickeho) nasho rezidua*/
void vyp_koef_kv(float* a, float* b, float* c) {
     float D;
     
     do {
           *a = rand() % 21 - 10;
     } while (*a == 0); 
     do {
          *b = rand() % 21 - 10;
     } while (*b == 0); 
  
     D = rand() % 10 - 10; 
     *c = ((*b) * (*b) - D) / (4 * (*a));
}


char nahodny_polynom(float* q, short rad, short k, float* koef) {
     float* korene = calloc(k, sizeof(float));    /*bude sa generovat nejake k korenov*/
     float koren;
     char flag = 1;
     int poc_pol = (rad - k) / 2;  /*pocet polynomov rezidua*/
     float** quadratics = (float **)malloc((poc_pol) * sizeof(float *));    /*pole pre polia s troma koeficientmi pre kazdy pol z rezidua (alokovali pamat pre polynomy)*/
     
     if ((k > rad || (rad % 2 != 0 && k % 2 == 0) || (rad % 2 == 0 && k % 2 != 0)) && k != 0)    /*podmienky, podla ktorych polynom sa nevygeneruje */
          return 0;

     if (k != 0) {
          if (k < rad)    /*v tomto pripade prvy koren vzdy sa rovna 0*/
               korene[0] = (float)0.;
          else
               korene[0] = (float)(rand() % 21 - 10);
     }

/*tu generujeme nahodne realne korene pre polynom a zabezpecujeme, aby tieto korene boli unikatne:*/
     for (int j = 1; j < k; j++) {
    
          koren=(float)(rand() % 21 - 10);
    
          for (int i = 0; i < k; i++) {/*kontrolujeme, ci uz tento koren existuje medzi doteraz vygenerovanymi*/
      
               if (korene[i] == koren) { /*ak sa najde zhodny koren*/
                    flag = 0; /*koren nie je unikatny*/
                    break;
               }     
          }
          if (flag) /*koren je unikatny*/
               korene[j] = koren; /*priradi novy koren do pola korenov*/
          else 
               j--;
     }
  
     printf("Korene su: ");
     
     for (int j = 0; j < k; j++) 
          printf("%.2f ", korene[j]);

     printf("\n");
  
     vyp_koef(korene, k, q);
  
     if (k != rad) {/*praca s reziduom*/
          
          for (int i = 0; i < poc_pol; i++) {     
          quadratics[i] = (float *)malloc(3 * sizeof(float));    /*pre kazdy pol alokuje pamat pre 3 koeficienty*/
          vyp_koef_kv(&quadratics[i][0], &quadratics[i][1], &quadratics[i][2]);
          printf("Reziduum %d: ", i+1); /*vypiseme kazdy polynom rezidua*/
          printf("(%.2fx^2 + %.2fx + %.2f)\n", quadratics[i][0], quadratics[i][1], quadratics[i][2]);
          }
     }
     printf("Rovnica: ");
     return 1;
}
  
                                                                 

int main(){
     short rad = 0, k = 0;
     float* q = calloc(rad + 1, sizeof(float));
     float* koef = calloc(1, sizeof(float));
     
     srand(time(0));

     printf("Zadajte stupen polynomu: ");
     scanf("%hd", &rad);
     printf("Zadajte pocet korenov: ");
     scanf(" %hd", &k);
  
     if (nahodny_polynom(q, rad, k, koef)) {
          if (k != 0) {
               printf("(");
               for (int i = 0; i <= rad; i++) {
                    if (q[i] != (float)0) {
                         if (q[i] >= 0 && i != 0)
                              printf("+");
                         printf("%.3f", q[i]);
                         printf("x^%hd ", (short)(rad - i));
                    }
               }
               printf(")");
          }
          if (k != rad) 
               printf("(krat vsetky polynomy rezidua)");
          printf("=0\n");
     }
     else 
          printf("Nepodarilo sa vygenerovat polynom");
  
     free(q);
}

