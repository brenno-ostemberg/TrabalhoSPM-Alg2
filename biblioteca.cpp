#include "biblioteca.h"
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void viaturaLogin() {

  int codigoViatura, quantidadePMs, i;
  char *tipoViatura;

  printf("\n---------------- SPM - Viatura Login ----------------");
  printf("\nCódigo da viatura: ");
  scanf("%d", &codigoViatura);

  if (verificarViatura(codigoViatura, tipoViatura) == false) {
    printf("\nFalha no Login.\nViatura não encontrada.");
    return;
  }

  tipoViatura[strlen(tipoViatura) - 1] = '\0';

  printf("\nQuantidade de PMs: ");
  scanf("%d", &quantidadePMs);

  if (((strcmp(tipoViatura, "especializada") == 0 && quantidadePMs != 4)) ||
      ((strcmp(tipoViatura, "regular") == 0 &&
        (quantidadePMs < 2 || quantidadePMs > 4)))) {
    printf("\nFalha no Login.\nQuantidade de PMs invalida.");
    return;
  }

  for (i = 0; i < quantidadePMs; i++) {
    criarFichaPolicial(i);
  }
}

bool verificarViatura(int codigo, char *&tipo) {

  FILE *txtViatura;
  int txtCodigo;
  char txtTipo[MAX];

  txtViatura = fopen("viaturas.txt", "r");

  if (txtViatura == NULL) {
    printf("Erro na leitura do arquivo txt.");
    return false;
  }

  fscanf(txtViatura, "%d %[^\n]", &txtCodigo, txtTipo);

  while (feof(txtViatura) == 0) {

    if (txtCodigo == codigo) {
      tipo = strdup(txtTipo);
      fclose(txtViatura);
      return true;
    }

    fscanf(txtViatura, "%d %[^\n]", &txtCodigo, txtTipo);
  }

  fclose(txtViatura);

  return false;
}

struct policial *criarFichaPolicial(int numero) {

  policial *novoPolicial;
  char nomeGuerraF[MAX];

  novoPolicial = (policial *)calloc(1, sizeof(policial));

  printf("Informe o nome de guerra do %d° policial: ", numero + 1);
  scanf(" %[^\n]", nomeGuerraF);

  strcpy(novoPolicial->nomeGuerra, nomeGuerraF);
  novoPolicial->proxPolicial = NULL;

  return novoPolicial;
}
