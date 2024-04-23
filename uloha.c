#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char nahodny_polynom(float *q,char rad,char k){

//generujeme nejake k korenov
float korene[k];
for(int i=0;i<rad;i++){
korene[i]=rand()%21-10; //ale to bude integer, moj buduci problem
}

/*generujeme koeficienty rovnice podla vygenerovanych korenov
...
*/

/*ulozime tieto koeficienty do pola q?
...
*/

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

/*ak kod uspechu tak vypisat polynom
ak neuspechu tak napisat ze polynom neexistuje
*/

/*a toto vsetko zatial bez algebraickych nasobnosti!!!*/
}
