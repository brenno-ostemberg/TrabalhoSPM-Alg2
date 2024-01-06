#define MAX 101

struct Lista {
  
  int tipoDado;
  void *chave;
  struct Lista *prox;

};

struct viatura {

  char tipo; // R = Regular | E = Especializada
  int codigo;
  int quantidadePM;
  struct policias;
};

struct policial {

  char nomeGuerra[MAX];
  struct policial *proxPolicial;
};

