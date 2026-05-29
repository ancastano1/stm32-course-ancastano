// En este ejercicio voy a repasar a lo BARE-METAL como configurar el TIMER

#include <stdint.h>
#include "stm32f4xx.h"

void configureTimer3(void) {
	/* Configurando el TIMER3 */

	// 1. Habilitar reloj del TIMER3
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	// 2. Configurar prescaler y periodo
	TIM3->PSC = 15999;  // Prescaler
	TIM3->ARR = 249;    // Auto-reload value
	TIM3->CNT = 0;      // Contador a cero

	// 3. Configurar y habilitar el timer
	TIM3->CR1 = 0;
	TIM3->CR1 |= TIM_CR1_CEN;  // Habilitar contador
}

int main(void) {
	/* Inicializar Timer3 */
	configureTimer3();

	/* Loop infinito */
	while(1) {
		// Aquí puedes leer el contador: uint16_t count = TIM3->CNT;
	}

	return 0;
}



