#include <stdio.h>
#include <stdlib.h>                  // Includo le librerie
#include <time.h>
#include <string.h>

void vistaMenu();
void crittografiaChiaveInserita();    // Definisco le funzioni
void crittografiaChiaveGenerata();

int main() {
  // Variabili
  int scelta = 0;
  time_t t;
  // Inizializzo il seme
  srand((unsigned) time(&t));
  vistaMenu();
  do {
    printf("Inserisci una voce: ");
    scanf("%d", &scelta);
    switch (scelta) {
      case 0: printf("Arrivederci!\n");
        break;
      case 1:
        printf("Hai selezionato la voce 1\n");
        crittografiaChiaveInserita();
        break;
      case 2:
        printf("Hai selezionato la voce 2\n");
        crittografiaChiaveGenerata();
        break;
      default:
        printf("La voce inserita e' inesistente\n");
    }
  } while(scelta != 0);
  return 0;
}

void crittografiaChiaveInserita() {
  char m[128], k[128], c[128];    // La stringa M è il messaggio in chiaro, k la chiave e c è la stringa M cifrata
  while (getchar()!='\n');  // Svuoto il buffer dello standard input
  printf("Inserisci la stringa M da cifrare: ");
  fgets(m,128,stdin);
  printf("Inserisci la stringa K per la cifratura: ");
  do {
    fgets(k,128,stdin);
    if(strlen(m) > strlen(k)) {
      printf("La chiave K è meno lunga della stringa M\nPer favore reinserisci la chiave K: ");
    }
  } while(strlen(m) > strlen(k));
  printf("La stringa M cifrata e visualizzata in esadecimale: ");
  for(int i = 0; i < strlen(m)-1; i++) {    // strlen(m)-1 per via del carattere terminatore
    c[i] = m[i] ^ k[i];     // OR esclusivo M + K = C per cifrare
    printf("%X", c[i]);     // Stampo i valori delle celle di c in esadecimale
  }
  printf("\nLa stringa M decifrata: ");
  for(int i = 0; i < strlen(m)-1; i++) {
    m[i] = c[i] ^ k[i];   // OR esclusivo C + K = M per decifrare
    printf("%c", m[i]);   // Stampo i valori delle celle di C in char
  }
  printf("\n");
}

void crittografiaChiaveGenerata() {
  char m[128], k[128], c[128];
  while (getchar()!='\n');
  printf("Inserisci la stringa M da cifrare: ");
  fgets(m,128,stdin);
  printf("La chiave generata: ");
  for(int i = 0; i < strlen(m)-1; i++) {
    k[i] = 33 + rand() % 93;    // Genero valori da 0 a 93 e ci aggiungo 33 per filtrare i caratteri speciali
    printf("%c", k[i]);
  }
  printf("\nLa stringa M cifrata e visualizzata in esadecimale: ");
  for(int i = 0; i < strlen(m)-1; i++) {
    c[i] = m[i] ^ k[i];
    printf("%X", c[i]);
  }
  printf("\nLa stringa M decifrata: ");
  for(int i = 0; i < strlen(m)-1; i++) {
    m[i] = c[i] ^ k[i];
    printf("%c", m[i]);
  }
  printf("\n");
}

void vistaMenu() {
  printf("\t------ Algoritmo di crittografia RC4 ------\n");
  printf("\t| 1: Inserisci da tastiera la chiave K    |\n");
  printf("\t| 2: Genera la chiave K                   |\n");
  printf("\t| 0: Esci dal programma                   |\n");
  printf("\t-------------------------------------------\n");
}
