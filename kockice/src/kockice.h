/**
* @file bowling_game.h
* @brief Document contains short description of used structures and functions
* @author Ja sam 
* @date October , 2015
*/
#ifndef _KOCKICE_H
#define _KOCKICE_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define broj_kockica 5
#define max_br_bacanja 3

typedef struct
{
	struct Kockica
	{
		uint8_t broj;
		uint8_t zakljucano;
<<<<<<< HEAD

	}kockice[broj_kockica];
	
	uint8_t br_bacanja;
		
}KOCKICE;
=======

	}kockice[broj_kockica];
	
	uint8_t br_bacanja;
		
}KOCKICE;

>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055

//pomocne funkcije
/***************************************************************************************************
*/


uint8_t slucajan_br( void );


//korisnicke funkcije
/***************************************************************************************************
*/

uint8_t inicijalizujKockice(KOCKICE* ob);
<<<<<<< HEAD

uint8_t bacaj_jednom(KOCKICE* ob);

uint8_t ispis_rezultata_bacanja(const KOCKICE* ob);

uint8_t zakljucaj(KOCKICE* ob, uint8_t kockica_koju_zakljucavamo);
=======

uint8_t bacaj(KOCKICE* ob);

uint8_t ispis_rezultata_bacanja(KOCKICE* ob);
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055

void bacaj(KOCKICE* ob);

#endif

