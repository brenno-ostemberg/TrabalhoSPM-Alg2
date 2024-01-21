#define MAX 101

// Structs:

struct Lista {
  int tipoDado;
  void *chave;
  struct Lista *prox;
};

struct viatura {
  char tipo; // R = Regular (2-4) | E = Especializada (4)
  int codigo;
  int quantidadePM;
  struct policias;
};

struct policial {
  char nomeGuerra[MAX];
  struct policial *proxPolicial;
};

// Funções:

void viaturaLogin();
bool verificarViatura(int codigo, char *&tipo);
struct policial *criarFichaPolicial(int numero);
