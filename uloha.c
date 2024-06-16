#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*vezmime nase korene a podla nich vypocitame koeficienty*/
void vyp_koef(float* korene, short k, float* q) {
    if (k != 0)
        q[0] = 1; /*koeficienty vlozime do pola q*/
    for (int i = 0; i < k; i++) {
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

/*nasob dva polynomy*/
void multiply_poly(float* A, int degA, float* B, int degB, float* result) {
    for (int i = 0; i <= degA + degB; i++) {
        result[i] = 0;
    }
    for (int i = 0; i <= degA; i++) {
        for (int j = 0; j <= degB; j++) {
            result[i + j] += A[i] * B[j];
        }
    }
}

char nahodny_polynom(float* q, short rad, short k, float* koef) {
    if (q == NULL || koef == NULL)
        return 0;

    float* korene = calloc(k, sizeof(float));
    if (korene == NULL)
        return 0;

    int poc_pol = (rad - k) / 2;
    if ((k > rad || (rad % 2 != 0 && k % 2 == 0) || (rad % 2 == 0 && k % 2 != 0)) && k != 0) {
        free(korene);
        return 0;
    }

    if (k != 0) {
        korene[0] = (k < rad) ? 0.0f : (float)(rand() % 21 - 10);
    }

    for (int j = 1; j < k; j++) {
        float koren = (float)(rand() % 21 - 10);
        int is_unique;
        do {
            is_unique = 1;
            for (int i = 0; i < j; i++) {
                if (korene[i] == koren) {
                    is_unique = 0;
                    koren = (float)(rand() % 21 - 10);
                    break;
                }
            }
        } while (!is_unique);
        korene[j] = koren;
    }

    printf("Korene su: ");
    for (int j = 0; j < k; j++)
        printf("%.2f ", korene[j]);
    printf("\n");

    vyp_koef(korene, k, q);

    float** quadratics = (float**)malloc(poc_pol * sizeof(float*));
    if (quadratics == NULL) {
        free(korene);
        return 0;
    }

    for (int i = 0; i < poc_pol; i++) {
        quadratics[i] = (float*)malloc(3 * sizeof(float));
        if (quadratics[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(quadratics[j]);
            free(quadratics);
            free(korene);
            return 0;
        }
        vyp_koef_kv(&quadratics[i][0], &quadratics[i][1], &quadratics[i][2]);
        printf("Reziduum %d: (%.2fx^2 + %.2fx + %.2f)\n", i + 1, quadratics[i][0], quadratics[i][1], quadratics[i][2]);
    }

    int final_degree = rad;
    float* final_poly = calloc(final_degree + 1, sizeof(float));
    if (final_poly == NULL) {
        for (int i = 0; i < poc_pol; i++)
            free(quadratics[i]);
        free(quadratics);
        free(korene);
        return 0;
    }

    float* temp_poly = calloc(final_degree + 1, sizeof(float));
    if (temp_poly == NULL) {
        free(final_poly);
        for (int i = 0; i < poc_pol; i++)
            free(quadratics[i]);
        free(quadratics);
        free(korene);
        return 0;
    }

    for (int i = 0; i <= rad; i++) {
        final_poly[i] = q[i];
    }

    for (int i = 0; i < poc_pol; i++) {
        multiply_poly(final_poly, rad, quadratics[i], 2, temp_poly);
        for (int j = 0; j <= final_degree; j++) {
            final_poly[j] = temp_poly[j];
        }
    }

    printf("Rovnica: ");
    for (int i = 0; i <= final_degree; i++) {
        if (final_poly[i] != 0) {
            if (i != 0 && final_poly[i] > 0) printf("+");
            printf("%.3fx^%d ", final_poly[i], final_degree - i);
        }
    }
    printf("= 0\n");

    free(final_poly);
    free(korene);
    for (int i = 0; i < poc_pol; i++)
        free(quadratics[i]);
    free(quadratics);
    return 1;
}

int main() {
    short rad = 0, k = 0;

    srand(time(0));

    printf("Zadajte stupen polynomu: ");
    scanf("%hd", &rad);
    printf("Zadajte pocet korenov: ");
    scanf(" %hd", &k);

    float* q = calloc(rad + 1, sizeof(float));
    float* koef = calloc(1, sizeof(float));

    if (q == NULL || koef == NULL) {
        printf("Chyba pri alokacii pamate\n");
        free(q);
        free(koef);
        return 1;
    }

    if (nahodny_polynom(q, rad, k, koef)) {
        printf("Polynom bol uspesne vygenerovany.\n");
    }
    else {
        printf("Nepodarilo sa vygenerovat polynom\n");
    }

    free(q);
    free(koef);
    return 0;
}

