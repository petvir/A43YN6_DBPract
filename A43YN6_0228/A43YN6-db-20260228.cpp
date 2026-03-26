#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIMIT 100

int main() {
    char fileName[MAX_LIMIT];
    char buffer[MAX_LIMIT];
    FILE *fptr;

    // 1. Fájlnév beolvasása
    printf("Adja meg a fajl nevet (pl. neptun.txt): ");
    scanf("%s", fileName);
    getchar(); // A scanf után ottmaradt újsor karakter (\n) kiürítése

    // 2. Fájl megnyitása írásra
    fptr = fopen(fileName, "w");
    if (fptr == NULL) {
        printf("Hiba a fajl letrehozasakor!");
        return 1;
    }

    printf("Adja meg a nevet es a neptun kodot (leallitas: #):\n");

    // 3. Sorok beolvasása a végjelig (#)
    while (1) {
        if (fgets(buffer, MAX_LIMIT, stdin) == NULL) break;

        // Ellenõrizzük, hogy az elsõ karakter a végjel-e
        if (buffer[0] == '#') break;

        // Beírás a fájlba
        fprintf(fptr, "%s", buffer);
    }

    // Fájl lezárása
    fclose(fptr);
    printf("\n--- Fajl elmentve es lezarva ---\n\n");

    // 4. Fájl újbóli megnyitása olvasásra
    fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        printf("Hiba a fajl megnyitasakor!");
        return 1;
    }

    printf("A fajl tartalma nagybetukkel:\n");

    // 5. Beolvasás és nagybetûssé alakítás
    int c;
    while ((c = fgetc(fptr)) != EOF) {
        putchar(toupper(c));
    }

    // Végsõ lezárás
    fclose(fptr);

    return 0;
}
