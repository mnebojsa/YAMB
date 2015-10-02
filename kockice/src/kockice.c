#include <stdio.h>
#include <stdlib.h>
#include "kockice.h"
#include <inttypes.h>


void kreirajKockice(KOCKICE* ob)
{
	uint8_t i;
	for(i=0 ; i < broj_kockica ; i++)
	{
		ob[i]->broj=0;
		ob[i]->zakljucano=0;	
	}
	
	return;
}

static uint8_t slucajan_br( void )
{

	time_t t;
   
   /* Intializes random number generator */
	srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 49 */
  
      return (uint8_t)(rand() % 6 + 1);
}

void baci(KOCKICE* kocke)
{
	uint8_t i;
	
	for(i=0 ; i < broj_kockica; i++)
	{
		kocke[i]->broj=slucajan_br();
	}	

	return;
}