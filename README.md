1. generujem náhodné k koreňov a vkladám ich do poľa korene.
2. podľa nich vo funkcii vyp_koef vypočítam koeficienty a vkladám ich do poľa q, toto pomocou Hornerovej schémy
3. Generujem reziduum polynóma vo forme postupnosti kvadratických polynómov, ktoré sú reprezentované ako ich koeficienty v poli quadratics.
4. quadratics, koeficienty sa vypočítajú pomocou funkcie vyp_koef_kv. Potom vypíšem každý polynóm rezidua.
Teda ten reziduum je náhodný polynóm stupňa (rad - k), ktorý nemá žiadne korene a vždy sa dá napísať ako súčin (rad - k)/2 kvadratických polynómov, ktoré nemajú žiadne reálne korene.


