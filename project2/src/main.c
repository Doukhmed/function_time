#include "stm32f10x.h"

void Timefunction(int temps);
int main(void) {
    RCC->APB2ENR |= 0x00000014; // Activer l'horloge pour les ports GPIOA et GPIOC
    GPIOC->CRH = (GPIOC->CRH & 0xFF0FFFFF) | 0x00300000; // Configurer la broche 13 (PC13) en mode sortie, vitesse maximale 10MHz
    GPIOA->CRH = (GPIOA->CRH & 0x0FFFFFFF) | 0x80000000; // Configurer les broches 14 et 15 (PA14 et PA15) en mode entrée avec Floating input

    while (1) {
        // Vérifier si PA15 est à l'état bas (appui sur un bouton connecté à PA15)
        if (GPIOA->IDR == 0X00008000) {
            // allumer la LED (PC13)
            GPIOC->BSRR = 0x00002000;
            Timefunction(1); // Attendre 5 secondes
	
            // Éteindre la LED (PC13)
            GPIOC->BSRR = 0x20000000;
            Timefunction(3); // Attendre 10 secondes
        }
    }
}
void Timefunction(int temps) {
    // Cette fonction attend simplement un certain nombre de cycles
    // Il est conseillé d'utiliser une temporisation plus précise ou un timer pour des durées longues
    int i,j;
    for(i = 0; i < temps ; i++) 
		{
        for(j=0; j< 2883 ;j++)
				{
				}
    }
	}
