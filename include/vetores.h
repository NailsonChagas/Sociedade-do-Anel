/*Alocando*/
int* alocar_vetor_int(int n);
int** alocar_matriz_int(int l, int c);

/*Imprimindo*/
void imprimir_vetor_int(int *v, int n);
void imprimir_matriz_int(int **m, int l, int c);

/*Desalocando*/
void desalocar_vetor_int(int *v);
void desalocar_matriz_int(int **m, int l);