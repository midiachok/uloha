#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char nahodny_polynom(float *q,char rad,char k){

if(k>rad)
return 0;

do{



//generujeme nejake k korenov
float* korene = calloc(k, sizeof(float));
for(int j=0;j<k;j++){
korene[j]=rand()%21-10;
}

/*generujeme koeficienty rovnice podla vygenerovanych korenov
tu sa pouzije Vietov vztah ale ako?? a co s tymi nasobnostami!!
*/

for(int i=rad;i>=0;i--){
        q[i]=0; 

       
        for(int j=0;j<=k;j++){
            
            if(i!=j){
                if(q[i]==0){
                    q[i]=1; 
                }
                q[i]*=-korene[j];
            }
        }
    }

/*overujeme dve podmienky ktore zistia ci ma uloha riesenie (vtedy oznamime kod (ne)uspechu
spravne rozumiem ze 'uloha ma riesenie' nehovori o korenoch teda nemusi kod hovorit ci mame 
uspech na zaklade toho ci ma vygenerovana rovnica riesenia ale ci mozeme vobec vygenerovat
rovnicu podla nahodne vygenerovanych korenov? napriklad ak mame vygenerovanu 
kv.rov. x^2-3x+10=0, korene ziadne nemame ale neznamena to ze mame neuspech. znamena toto, ze 
mame k=0,rad=2,q[]={1,-3,10} a musime oznamit kod uspechu. 
to znamena ze musime nejakym padom overovat ci vygenerovane korene sa hodia na vytvorenie 
aspon nejakych koeficientov. ak ano tak mame kod uspechu.
mozne podmienky na overovanie: 1. ci k<=rad  2. ci urcite polynom ma k korenov (ak hodnota polynomu
sa = 0, tak je koren, a k vtedy ++)
*/

float hodnota_polynomu(float *q,char rad,float x) {
    float hodnota=q[0];
    for(char i=1;i<=rad;i++){
        hodnota=hodnota*x+q[i];
    }
    return hodnota;
}

char pocet_korenov = 0;
    for (float x = -10.0; x <= 10.0; x += 0.01) {
        if (hodnota_polynomu(q, rad, x) == 0.0) {
            pocet_korenov++;
        }
    }

}while(pocet_korenov!=k);
return 1;
/*ak kod uspechu tak vypisat polynom
ak neuspechu tak napisat ze polynom neexistuje
*/

/*a toto vsetko zatial bez algebraickych nasobnosti!!!*/
}



int main(){
srand(time(0));
char rad=0,k=0;


printf("Zadajte stupen polynomu: ");
    scanf("%c", &rad);
    printf("Zadajte pocet korenov: ");
    scanf(" %c", &k);
float* q = calloc(rad + 1, sizeof(float));
    
    if (nahodny_polynom(q,rad,k)){
    for (int i=0;i<=rad;i++){
            printf("%fx^%c",q[i],rad-i);
        }
        printf("=0\n");
    }else{
        printf("Nepodarilo sa vygenerovat polynom");
    }

free(q);
}
