/**
* @file bowling_game.h
* @brief Document contains short description of used structures and functions
* @author Ja sam 
* @date October , 2015
*/
#ifndef _LISTIC_H
#define _LISTIC_H
#include "../../kockice/src/kockice.h"
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct Poeni
{
	uint16_t poeni;
	uint8_t zakljucano;
}BODOVI_U_POLJU;

typedef struct Listic
{
	BODOVI_U_POLJU slobodno[12];
	BODOVI_U_POLJU gore[12];
	BODOVI_U_POLJU gore_dole[12];
	BODOVI_U_POLJU dole[12];
	
}LISTIC;

void KreirajPrazanListic(LISTIC* ls);
/********************************************** pomocne * funkcije *************************************************************************
*/

uint8_t skala(const KOCKICE *ob);
uint8_t full(const KOCKICE *ob);
uint16_t racunaBodove(const KOCKICE* ob, uint8_t red );



uint16_t upisiPoeneUPolje(LISTIC *ls, uint8_t red , uint8_t kolona);

#endif
