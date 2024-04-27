#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char nahodny_polynom(float *q,short rad,short k){

if((k>rad || (rad%2!=0 && k%2==0)||(rad%2==0 && k%2!=0) )&&k!=0){
return 0;
}
else if(k==0){
q[rad]=1;


for(int i=0;i<rad;i++){

q[i]=(float)(rand()%21-10);
q[rad]*= -q[i];
}



return 1;
}

//generujeme nejake k korenov
float* korene = calloc(k, sizeof(float));
for(int j=0;j<k;j++){ 
korene[j]=(float)(rand()%21-10); //?
}
if(k<rad)
korene[0]=0.;

printf("Korene su:\n");
for(int j=0;j<k;j++){ 
printf("%.0f \n",korene[j]);
}
printf("\n");


/*???
funkcia na nasobenie polynomov*/

/*???
generujeme koeficienty rovnice podla vygenerovanych korenov
REZIDUUM
*/


void vypKoef(float *korene,short k,float* q){

    q[0]=1; 

    for(int i=0;i<k;i++){
        for(int j=i;j>=0;j--){
            q[j+1]-=korene[i]*q[j];
        }
    }
}
vypKoef(korene,k,q);
  printf("Rovnica: ");
return 1;

/*overujeme dve podmienky ktore zistia ci ma uloha riesenie (vtedy oznamime kod (ne)uspechu
spravne rozumiem ze 'uloha ma riesenie' nehovori o korenoch teda nemusi kod hovorit ci mame 
uspech na zaklade toho ci ma vygenerovana rovnica riesenia ale ci mozeme vobec vygenerovat
rovnicu podla nahodne vygenerovanych korenov? napriklad ak mame vygenerovanu 
kv.rov. x^2-3x+10=0, korene ziadne nemame ale neznamena to ze mame neuspech. znamena toto, ze 
mame k=0,rad=2,q[]={1,-3,10} a musime oznamit kod uspechu. 
to znamena ze musime nejakym padom overovat ci vygenerovane korene sa hodia na vytvorenie 
aspon nejakych koeficientov. ak ano tak mame kod uspechu.


podmienky na overovanie: 1. k<=rad  2. ak rad je parny tak k tiez parny a naopak
*/




/*ak kod uspechu tak vypisat polynom
ak neuspechu tak napisat ze polynom neexistuje
*/


}



int main(){
srand(time(0));
short rad=0,k=0;


printf("Zadajte stupen polynomu: ");
    scanf("%hd", &rad);
    printf("Zadajte pocet korenov: ");
    scanf(" %hd", &k);
float* q = calloc(rad + 1, sizeof(float));
    
    
    if (nahodny_polynom(q,rad,k)){
    for (int i=0;i<=rad;i++){
            printf("%.0fx^%hd ",q[i],rad-i);
        }
        printf("=0\n");
    }else{
        printf("Nepodarilo sa vygenerovat polynom");
    }

free(q);
}
