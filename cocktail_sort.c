#include <stdio.h>
#define bool int
#define true 1
#define false 0

/*
 * Função responsável por trocar dois valores, 
 * criada para tornar o código mais limpo
 */
void swap(int *firtsValue, int *secondValue) {
    int aux = *firtsValue;
    *firtsValue = *secondValue;
    *secondValue = aux;
}

// Função de ordenação Cocktail
void cocktailSort(int vector[], int vectorSize) {

	/*
	 * Variável responsável por controlar quando
     * houve ou não trocas
	 */
    bool swapped;

	// Índice inicial de iteração com o vetor
    int start = 0;

	// Indíce final de iteração com o vetor
    int end = vectorSize - 2;

    // Loop principal: enquanto houver trocas ele será relizado
    do {

		/*
		 * A cada iteração considera-se que não
         * houve trocas
		 */
        swapped = false;

		/*
         * Loop que move os maiores elementos
         * para o fim da lista
         */
        for (int i = start; i < end; i++) {

			/*
             * Caso o valor de índice atual seja
             * maior que o valor de índice superior,
             * suas posições são trocadas
             */
            if (vector[i] > vector[i + 1]) {
                swap(&vector[i], &vector[i + 1]);

				/*
                 * Visto que houve troca, agora
                 * a variável swapped recebe o valor
                 * verdadeiro
                 */
                swapped = true;
            }

        }
				
		/*
         * Aqui é verificado se houve alguma troca.
         * Caso sim, é realizado o loop responsável
         * por levar os menores elementos para o
         * início da lista. Caso não, esse loop é
         * ignorado e o outro loop superior (while)
         * é finalizado
         */
        if (swapped) {

			/*
			 * Loop responsável 
             * por levar os menores elementos para o
             * início da lista
			 */
            for (int i = end; i >= start; i--) {

				/*
		         * Caso o valor de índice atual seja
		         * maior que o valor de índice 
                 * superior, suas posições são 
                 * trocadas
		         */
                if (vector[i] > vector[i + 1]) {
                    swap(&vector[i], &vector[i + 1]);
                   
                    /*
                     * Visto que houve troca, agora
                     * a variável swapped recebe o 
                     * valor verdadeiro
                     */
                    swapped = true;
                }

            }

        }

    /*
     * Verifica se houve trocas, caso sim, o loop continua, 
     * caso não, o loop é finalizado
     */
    } while (swapped);
}