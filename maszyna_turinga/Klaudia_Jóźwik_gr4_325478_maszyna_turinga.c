#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>


#define MAX 100

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

typedef enum {
    q0, q1, q2, q3, q4, q5, q6
} Stan;

typedef struct {
    Stan stan;
    int glowica;
    char tasma[MAX];

} Maszyna_Turinga;





void funkcja(Maszyna_Turinga MT, int m, int n, Stan stan) {

    int k = m + n + 1;

    if (MT.glowica == 0) {
        printf("(q%d)", MT.stan);
        for (int i = 0; i < k; i++) {
            printf("%c", MT.tasma[i]);
        }
    }
    if (MT.glowica == 1) {
        printf("%c", MT.tasma[0]);
        printf("(q%d)", MT.stan);
        for (int i = 1; i < k; i++) {
            printf_s("%c", MT.tasma[i]);
        }

    }

    if (MT.glowica == 2) {
        for (int i = 0; i <= 1; i++) {
            printf("%c", MT.tasma[i]);
        }
        printf("(q%d)", MT.stan);
        for (int i = 2; i < k; i++) {
            printf("%c", MT.tasma[i]);
        }


    }
    if (MT.glowica == 3) {
        for (int i = 0; i <= 2; i++) {
            printf("%c", MT.tasma[i]);
        }
        printf("(q%d)", MT.stan);
        for (int i = 3; i < k; i++) {
            printf("%c", MT.tasma[i]);
        }

    }
    if (MT.glowica == 4) {
        for (int i = 0; i <= 3; i++) {
            printf("%c", MT.tasma[i]);
        }
        printf("(q%d)", MT.stan);
        for (int i = 4; i < k; i++) {
            printf("%c", MT.tasma[i]);
        }

    }
    if (MT.glowica == 5) {
        for (int i = 0; i <= 4; i++) {
            printf("%c", MT.tasma[i]);
        }
        printf("(q%d)", MT.stan);
        for (int i = 5; i < k; i++) {
            printf("%c", MT.tasma[i]);
        }

    }
    if (MT.glowica == 6) {
        for (int i = 0; i <= 5; i++) {
            printf("%c", MT.tasma[i]);
        }
        printf("(q%d)", MT.stan);
        for (int i = 6; i < k; i++) {
            printf("%c", MT.tasma[i]);
        }

    }
    if (MT.glowica == 7) {
        for (int i = 0; i <= 6; i++) {
            printf("%c", MT.tasma[i]);
        }
        printf("(q%d)", MT.stan);
        for (int i = 7; i < k; i++) {
            printf("%c", MT.tasma[i]);
        }

    }
    if (MT.glowica == 8) {
        for (int i = 0; i <= 7; i++) {
            printf("%c", MT.tasma[i]);
        }
        printf("(q%d)", MT.stan);
        for (int i = 8; i < k; i++) {
            printf("%c", MT.tasma[i]);
        }

    }
    if (MT.glowica == 9) {
        for (int i = 0; i <= 8; i++) {
            printf("%c", MT.tasma[i]);
        }
        printf("(q%d)", MT.stan);
        for (int i = 9; i < k; i++) {
            printf("%c", MT.tasma[i]);
        }

    }
    printf(" |- ");

}

void end(Maszyna_Turinga MT) {
    int i = 0;
    char* p = MT.tasma;
    while (p = strchr(p, '0')) {
        i++;
        p++;
    }
    printf("\n\nWynik: %d\n\n\n", i);
}

int main() {
    int m, n, i = 0, tasma_in = 0;
    char tasma[MAX];


    printf("Klaudia Jozwik gr.4 nr.325478\n Emulator Maszyny Turinga obliczajacy roznice wlasciwa:\n\n\n");

    printf(" Postac MT\n M=({q0, q1, q2, q3, q4, q5, q6}, {0,1}, {0,1,B}, d, q0, B, 0)\n\n");
    printf(" d       0         1         B    \n q0  (q1,B,P)  (q5,B,P)      -    \n q1  (q1,0,P)  (q2,1,P)      -    \n q2  (q3,1,L)  (q2,1,P)  (q4,B,L) \n q3  (q3,0,L)  (q3,1,L)  (q0,B,P) \n q4  (q4,0,L)  (q4,B,L)  (q6,0,P) \n q5  (q5,B,P)  (q5,B,P)  (q6,B,P)\n q6      -         -         -    \n\n\n");

    printf("Prosze podac pierwsza liczbe: ");
    scanf_s("%d", &m);
    printf("Prosze podac druga liczbe: ");
    scanf_s("%d", &n);

    int r = m;
    int t = n;
    while (r > 0) {
        tasma[tasma_in] = '0';
        tasma_in++;
        r--;
    }

    tasma[tasma_in] = '1';
    tasma_in++;

    while (t > 0) {
        tasma[tasma_in] = '0';
        tasma_in++;
        t--;
    }

    while (tasma_in < MAX) {
        tasma[tasma_in] = 'B';
        tasma_in++;

    }

    Maszyna_Turinga MT;
    MT.stan = q0;
    strcpy(MT.tasma, tasma);
    MT.glowica = 0;

    printf("\n");

    while (1) {

        funkcja(MT, m, n, MT.stan);

        char symbol = MT.tasma[MT.glowica];
        switch (MT.stan) {
        case q0:
            if (symbol == '0') {
                MT.stan = q1;
                MT.tasma[MT.glowica] = 'B';
                MT.glowica++;
            }
            else if (symbol == '1') {
                MT.stan = q5;
                MT.tasma[MT.glowica] = 'B';
                MT.glowica++;
            }
            else if (symbol == 'B') {
                break;
            }
            break;
        case q1:
            if (symbol == '0') {
                MT.stan = q1;
                MT.tasma[MT.glowica] = '0';
                MT.glowica++;
            }
            else if (symbol == '1') {
                MT.stan = q2;
                MT.tasma[MT.glowica] = '1';
                MT.glowica++;
            }
            else if (symbol == 'B') {
                break;
            }
            break;
        case q2:
            if (symbol == '0') {
                MT.stan = q3;
                MT.tasma[MT.glowica] = '1';
                MT.glowica--;
            }
            else if (symbol == '1') {
                MT.stan = q2;
                MT.tasma[MT.glowica] = '1';
                MT.glowica++;
            }
            else if (symbol == 'B') {
                MT.stan = q4;
                MT.tasma[MT.glowica] = 'B';
                MT.glowica--;
            }
            break;
        case q3:
            if (symbol == '0') {
                MT.stan = q3;
                MT.tasma[MT.glowica] = '0';
                MT.glowica--;
            }
            else if (symbol == '1') {
                MT.stan = q3;
                MT.tasma[MT.glowica] = '1';
                MT.glowica--;
            }
            else if (symbol == 'B') {
                MT.stan = q0;
                MT.tasma[MT.glowica] = 'B';
                MT.glowica++;
            }
            break;
        case q4:
            if (symbol == '0') {
                MT.stan = q4;
                MT.tasma[MT.glowica] = '0';
                MT.glowica--;
            }
            else if (symbol == '1') {
                MT.stan = q4;
                MT.tasma[MT.glowica] = 'B';
                MT.glowica--;
            }
            else if (symbol == 'B') {
                MT.stan = q6;
                MT.tasma[MT.glowica] = '0';
                MT.glowica++;
            }
            break;
        case q5:
            if (symbol == '0') {
                MT.stan = q5;
                MT.tasma[MT.glowica] = 'B';
                MT.glowica++;
            }
            else if (symbol == '1') {
                MT.stan = q5;
                MT.tasma[MT.glowica] = 'B';
                MT.glowica++;
            }
            else if (symbol == 'B') {
                MT.stan = q6;
                MT.tasma[MT.glowica] = 'B';
                MT.glowica++;
            }
            break;
        case q6:


            end(MT);
            Sleep(1000);
            return 0;

        }
    }

    return 0;
}