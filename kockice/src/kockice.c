#include <stdio.h>
#include <stdlib.h>
#include "kockice.h"
#include <inttypes.h>
#include <unistd.h>


uint8_t slucajan_br( void )
{
	time_t t;
   	 static unsigned int zi;
	


	srand((unsigned) time(&t));  
	zi=rand();		 /* inicijalizuje random generator */
	sleep(1);
	return (uint8_t)(((1103515245* zi + 12345) % 2147483648) % 6 + 1);	 /* vraca nasumican broj u opsegu vrednosti od 1 do 6 */      
}


uint8_t inicijalizujKockice(KOCKICE* ob)
{
	uint8_t i;
	for(i=0 ; i < broj_kockica ; i++)
	{
		ob->kockice[i].broj=0;
		ob->kockice[i].zakljucano=0;	
	}
	ob->br_bacanja=0;
	
	return 0;
}



uint8_t bacaj(KOCKICE* ob)
{
	uint8_t i;
	uint8_t j;
	
	if(++(ob->br_bacanja) <= 3)
	{	
		for(i=0 ; i < broj_kockica; i++)
		{		
			if(!ob->kockice[i].zakljucano)
			{			
				ob->kockice[i].broj=slucajan_br();
				
			}	
		}
	}else
	{
		return 1;
	}
	return 0;
}

uint8_t ispis_rezultata_bacanja(KOCKICE* ob)
{
	uint8_t i;
	for(i = 0 ; i < broj_kockica ; i++)
	{
		printf("\n %d.kockica : %d", i+1, ob->kockice[ob->br_bacanja].broj);	
	}
	printf("\n");
}
