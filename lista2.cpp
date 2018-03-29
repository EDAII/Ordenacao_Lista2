#include <sys/time.h>
#include <sys/resource.h>
#include <bits/stdc++.h>

using namespace std;

double calcula_tempo(const struct rusage *b, const struct rusage *a) {
    if (b == NULL || a == NULL)
        return 0;
    else
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                 (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                 (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
}


void insertionSort(int original[], int length) {
	int i, j, atual;

	for (i = 1; i < length; i++) {
		atual = original[i];


		for (j = i - 1; (j >= 0) && (atual < original[j]); j--) {
			original[j + 1] = original[j];
        }

		original[j+1] = atual;
	}

}

void shellSort(int *vet, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
            }
            vet [j] = value;
        }
    }
}

int main(int argc, char const *argv[]) {
   struct rusage tempo_inicial, tempo_final;
	 double tempo,tempo2;
	 int tam;
	 cout << "Insira o tamanho do vetor: ";
	 cin >> tam;
	 int vetor[tam],vetor2[tam];
	 for (int i=1; i < tam; i++){
    vetor[i] = rand()%10000;
  }
	for (int i=1; i < tam; i++){
	 vetor2[i] = rand()%10000;
 }

 if (tam <= 20){
   cout << "Vetor 1 = ";
    for (size_t i = 0; i < tam; i++)
      cout << vetor[i] << " ";
    cout << endl;
  }
	if (tam <= 20){
    cout << "Vetor 2 = ";
    for (size_t i = 0; i < tam; i++)
      cout << vetor2[i] << " ";
    cout << endl;
  }
	getrusage(RUSAGE_SELF, &tempo_inicial);
		shellSort(vetor,tam);
	getrusage(RUSAGE_SELF, &tempo_final);
	tempo = calcula_tempo(&tempo_inicial, &tempo_final);

	if (tam <= 20){
	    for (size_t i = 0; i < tam; i++)
	      cout << vetor[i] << " ";
      cout << endl;
	  }


	getrusage(RUSAGE_SELF, &tempo_inicial);
		insertionSort(vetor2,tam);
	getrusage(RUSAGE_SELF, &tempo_final);
	tempo2 = calcula_tempo(&tempo_inicial, &tempo_final);

	if (tam <= 20){
	    for (size_t i = 0; i < tam; i++)
	      cout << vetor2[i] << " ";
      cout << endl;
	  }

  printf("Tempo Shell Sort: %lf\n",tempo);
  printf("Tempo Insertion Sort: %lf\n",tempo2);

  return 0;
}
