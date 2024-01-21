#include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
#include "biblioteca.h"

int main() {

  int opcao;

  do {

    printf("\n\n------------- SPM - Inicio -------------\n");
    printf("\n1 - Viatura Login");
    printf("\n2 - Viatura em Uso");
    printf("\n3 - COPOM");
    printf("\n4 - Policial Militar");
    printf("\n5 - Oficial");
    printf("\n6 - Comandante Geral");
    printf("\n\n0 - Encerrar Programa");
    printf("\n\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
      viaturaLogin();
    } else if (opcao == 2) {
    } else if (opcao == 3) {
    } else if (opcao == 4) {
    } else if (opcao == 5) {
    } else if (opcao == 6) {
    }

  } while (opcao != 0);

  // desalocar lista

  return 0;
}
