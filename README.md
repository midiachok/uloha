. Generujem náhodný polynóm a jeho koeficienty ukladám do poľa q. 
. Generujem jeho reziduum vo forme postupnosti kvadratických polynómov, ktoré sú reprezentované ako ich koeficienty v poli quadratics.
. Generujem pole korene, ktoré obsahuje náhodné korene.
. Funkcia vypKoef vypočíta koeficienty polynómu podľa jeho koreňov pomocou Hornerovej schémy.
. Generujem reziduum. Každý z tých kvadratických polynómov generujem pomocou funkcie vypKoefKv, ktorá taktiež využíva náhodné koeficienty. Potom vypíšem každý polynóm rezidua.
. Pre každý kvadratický polynóm rezidua vykonám násobenie s ostatnými kvadratickými polynómami. Výsledok násobenia uchovávam v poli koef. Na tento účel používam funkciu nasobPol, ktorá násobí dva polynómy a ukladá výsledok do poľa koef.
. Tento proces pokračuje, kým všetky kvadratické polynómy rezidua nie sú násobené medzi sebou. (ale niečo sa nepodarilo :(( )

Teda ten reziduum je náhodný polynóm stupňa (rad - k), ktorý nemá žiadne korene a vždy sa dá napísať ako súčin (rad - k)/2 kvadratických polynómov, ktoré nemajú žiadne reálne korene. 
