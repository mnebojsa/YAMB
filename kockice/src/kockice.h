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


typedef struct Kockice
{
	uint8_t broj;
	uint8_t zakljucano;

}KOCKICE[broj_kockica];

//pomocne funkcije
/***************************************************************************************************
*/


static uint8_t slucajan_br( void );


//korisnicke funkcije
/***************************************************************************************************
*/

void kreirajKockice(KOCKICE* );

void baci(KOCKICE* );



#endif

