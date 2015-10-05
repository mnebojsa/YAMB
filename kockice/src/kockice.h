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

	}kockice[broj_kockica];
	
	uint8_t br_bacanja;
		
}KOCKICE;


//pomocne funkcije
/***************************************************************************************************
*/


uint8_t slucajan_br( void );


//korisnicke funkcije
/***************************************************************************************************
*/

uint8_t inicijalizujKockice(KOCKICE* ob);

uint8_t bacaj(KOCKICE* ob);

uint8_t ispis_rezultata_bacanja(KOCKICE* ob);


#endif

