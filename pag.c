#include <stdio.h>
#include <stdlib.h>


#define MAX_REFERENCES 10

/*
void envelhecimento_pag(int string[], int strLen, int pages[], int pageLen) {

    int age_count[pageLen];
    int hits = 0;

    for (int i = 0; i < pageLen; i++) {
        pages[i] = -1;  // Inicializa os frames como vazios
        age_count[i] = 0;  // Inicializa os contadores de idade
    }

    for (int i = 0; i < strLen; i++) {
        int page = string[i];
        int achou = 0;

        // Verifica se a página já está nos frames
        for (int j = 0; j < pageLen; j++) {
            if (pages[j] == page) {
                achou = 1;
                hits++;
                age_count[j] |= 0x80;  // Define o bit de envelhecimento mais significativo como 1
                break;
            }
        }

        // Se a página não foi encontrada nos frames
        if (!achou) {
            int min_age_index = 0;

            // Envelhece os contadores de idade
            for (int j = 0; j < pageLen; j++) {
                age_count[j] >>= 1;  // Rotaciona os bits para a direita (envelhecimento)
                if (age_count[j] < age_count[min_age_index]) {
                    min_age_index = j;
                }
            }

            // Substitui a página com o menor contador de idade
            pages[min_age_index] = page;
            age_count[min_age_index] = 0x80;  // Define o bit de envelhecimento mais significativo como 1

            // Imprime os frames e o item de referência atual
            printf("%d \t\t", page);
            for (int j = 0; j < pageLen; j++) {
                printf("%d:%d \t\t", pages[j], age_count[j] & 0x7F);  // Imprime apenas os 7 bits menos significativos
            }
            printf("\n");
        }
    }

    printf("\nHits: %d\n", hits);
    printf("Misses: %d\n", strLen - hits);
}

int main() {
    int string[10] = {2, 3, 6, 7, 3, 1, 0, 0, 2, 5};
    int strLen = 10;
    int pageLen = 3;
    int pages[pageLen];

    printf("Reference \tFrames\n");
    envelhecimento_pag(string, strLen, pages, pageLen);

    return 0;
}

*/
void envelhecimento_pag(int string[], int strLen, int pages[], int pageLen) {

    int age_count[pageLen];
    int hits = 0;

    for (int i = 0; i < pageLen; i++) {
        pages[i] = -1;  // Inicializa os frames como vazios
        age_count[i] = 0;  // Inicializa os contadores de idade
    }

    for (int i = 0; i < strLen; i++) {
        int page = string[i];
        int achou = 0;

        // Verifica se a página já está nos frames
        for (int j = 0; j < pageLen; j++) {
            if (pages[j] == page) {
                achou = 1;
                hits++;
                age_count[j] |= 0x80;  // Define o bit de envelhecimento mais significativo como 1
                break;
            }
        }

        // Se a página não foi encontrada nos frames
        if (!achou) {
            int min_age_index = 0;

            // Envelhece os contadores de idade
            for (int j = 0; j < pageLen; j++) {
                age_count[j] >>= 1;  // Rotaciona os bits para a direita (envelhecimento)
                if (age_count[j] < age_count[min_age_index]) {
                    min_age_index = j;
                }
            }

            // Substitui a página com o menor contador de idade
            pages[min_age_index] = page;
            age_count[min_age_index] = 0x80;  // Define o bit de envelhecimento mais significativo como 1

            // Imprime os frames e o item de referência atual
            printf("%d \t\t", page);
            for (int j = 0; j < pageLen; j++) {
                printf("%d:%d \t\t", pages[j], age_count[j] & 0x7F);  // Imprime apenas os 7 bits menos significativos
            }
            printf("\n");
        }
    }

    printf("\nHits: %d\n", hits);
    printf("Misses: %d\n", strLen - hits);
}

int main() {
    int string[10] = {2, 3, 6, 7, 3, 1, 0, 0, 2, 5};
    int strLen = 10;
    int pageLen = 3;
    int pages[pageLen];

    printf("Reference \tFrames\n");
    envelhecimento_pag(string, strLen, pages, pageLen);

    return 0;
}
