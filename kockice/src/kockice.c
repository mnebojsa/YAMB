#include <stdio.h>
#include <stdlib.h>
#include "kockice.h"
#include <inttypes.h>
<<<<<<< HEAD
#include <time.h>


////    !!!!!!!!!!!!!!!!!!!!!!      ne radi slucajan broj

uint8_t slucajan_br( void )
{
   	static unsigned long zi;
	
	srand( NULL );  
	zi=rand()%6+1;
printf("    unutar funkcije %d\n", zi);								 /* inicijalizuje random generator */	
	return (uint8_t)zi;	 /* vraca nasumican broj u opsegu vrednosti od 1 do 6 */      
=======
#include <unistd.h>


uint8_t slucajan_br( void )
{
	time_t t;
   	 static unsigned int zi;
	


	srand((unsigned) time(&t));  
	zi=rand();		 /* inicijalizuje random generator */
	sleep(1);
	return (uint8_t)(((1103515245* zi + 12345) % 2147483648) % 6 + 1);	 /* vraca nasumican broj u opsegu vrednosti od 1 do 6 */      
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055
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

<<<<<<< HEAD


uint8_t bacaj_jednom(KOCKICE* ob)
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
				
			}else
			{
				ob->kockice[i].broj=ob->kockice[i].broj;
			}	
		}
		return 1;
	}else
	{
		return 0;
	}
}


uint8_t ispis_rezultata_bacanja(const KOCKICE* ob)
{
	uint8_t i;
	for(i = 0 ; i < broj_kockica ; i++)
	{
		printf("\n %d.kockica : %d", i+1, ob->kockice[i].broj);	
	}
	printf("\n");
}

uint8_t zakljucaj(KOCKICE* ob, uint8_t kockica_koju_zakljucavamo)
{
	if(ob->kockice[kockica_koju_zakljucavamo].zakljucano==0)	
	{
		ob->kockice[kockica_koju_zakljucavamo].zakljucano=1;	
	}else
	{
		ob->kockice[kockica_koju_zakljucavamo].zakljucano=0;	
	}
	return 1;
}

void bacaj(KOCKICE* ob)
{
	uint8_t kockica_koju_zakljucavamo;
	uint8_t i;

	for(i = 0 ; i < max_br_bacanja; i++)
	{
		bacaj_jednom(ob);
		ispis_rezultata_bacanja(ob);
		kockica_koju_zakljucavamo=55;    //samo da bude ostvaren uslov za while
		while(kockica_koju_zakljucavamo)
		{
			printf("zakljucaj/otkljucaj kockicu :");
			scanf("%"SCNd8 , &kockica_koju_zakljucavamo);		
			zakljucaj(ob,kockica_koju_zakljucavamo-1);	
		}	
	}
	return;
=======


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
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055
}
