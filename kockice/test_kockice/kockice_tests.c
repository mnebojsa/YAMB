#include "../../unity/unity_fixture.h"
#include "../src/kockice.h"


KOCKICE ob;
<<<<<<< HEAD

/****************************************** jedno_bacanje * testovi *************************************************************
*/
=======
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055

TEST_GROUP(bacaj_tests);


TEST_GROUP_RUNNER(bacaj_tests)
{
	RUN_TEST_CASE(bacaj_tests , rezultat_sl_br);
	RUN_TEST_CASE(bacaj_tests , ispravna_inicijalizacija);
	RUN_TEST_CASE(bacaj_tests , ne_baca_zakljucanu_kockicu);
	RUN_TEST_CASE(bacaj_tests , sve_kockice_zakljucane);
<<<<<<< HEAD
	RUN_TEST_CASE(bacaj_tests , nedozvoljeno_bacanje);
	
=======
	RUN_TEST_CASE(bacaj_tests , dozvoljena_3_bacanja);
	RUN_TEST_CASE(bacaj_tests , ispis);
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055
}

TEST_SETUP(bacaj_tests)
{
	inicijalizujKockice(&ob);
}


TEST_TEAR_DOWN(bacaj_tests)
{
}

/****************************************** zakljucaj * testovi *************************************************************
*/

TEST_GROUP(zakljucaj_tests);


TEST_GROUP_RUNNER(zakljucaj_tests)
{
	RUN_TEST_CASE(zakljucaj_tests , dobro_zaljucane_kockice);
	RUN_TEST_CASE(zakljucaj_tests , ispravno_otkljucane_kockice);
	
}

TEST_SETUP(zakljucaj_tests)
{
	inicijalizujKockice(&ob);
}


TEST_TEAR_DOWN(zakljucaj_tests)
{
}



/****************************************** runda_bacanja * testovi *************************************************************
*/

TEST_GROUP(bacanja_runda_tests);


TEST_GROUP_RUNNER(bacanja_runda_tests)
{
	RUN_TEST_CASE(bacanja_runda_tests , dozvoljena_3_bacanja);
	RUN_TEST_CASE(bacanja_runda_tests , bacanje_runda);
}

TEST_SETUP(bacanja_runda_tests)
{
	inicijalizujKockice(&ob);
}


TEST_TEAR_DOWN(bacanja_runda_tests)
{
}


/****************************************** ispis * testovi **********************************************************************
*/

TEST_GROUP(ispis_tests);


TEST_GROUP_RUNNER(ispis_tests)
{
	RUN_TEST_CASE(ispis_tests , ispis);
}

TEST_SETUP(ispis_tests)
{
	inicijalizujKockice(&ob);
}


TEST_TEAR_DOWN(ispis_tests)
{
}


/***************************TESTOVI_ZA_jedno_bacanje**************************************************************************
*/


// 1. test
TEST(bacaj_tests , rezultat_sl_br)
<<<<<<< HEAD
{
	uint8_t i;
	uint8_t pomocna_promenljiva;
	for(i=0 ; i < 10 ; i++)
	{
		pomocna_promenljiva = slucajan_br();
printf("\n br %d ",pomocna_promenljiva);			
		TEST_ASSERT_EQUAL(1, pomocna_promenljiva > 0 && pomocna_promenljiva <= 6);
	}
}

// 2. test
TEST(bacaj_tests , ispravna_inicijalizacija)
{
	uint8_t i;
=======
{
	uint8_t i;
	uint8_t pomocna_promenljiva;
	for(i=0 ; i < 10 ; i++)
	{
		pomocna_promenljiva = slucajan_br();			
		TEST_ASSERT_EQUAL(1, pomocna_promenljiva > 0 && pomocna_promenljiva <= 6);
	}
}

// 2. test
TEST(bacaj_tests , ispravna_inicijalizacija)
{
	uint8_t i;
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055
	for(i=0 ; i < broj_kockica ; i++)
	{
			
		TEST_ASSERT_EQUAL(1 , ob.kockice[i].zakljucano == 0);			
		TEST_ASSERT_EQUAL(1 , ob.kockice[i].broj == 0);
		TEST_ASSERT_EQUAL(1 , ob.br_bacanja == 0);
	}
}

// 3. test
TEST(bacaj_tests , ne_baca_zakljucanu_kockicu)
{		
	uint8_t i;
	
	ob.kockice[2].broj = 5;
	ob.kockice[2].zakljucano = 1;
	
	for(i=0 ; i < 10 ; i++)
	{
<<<<<<< HEAD
		bacaj_jednom(&ob);
=======
		bacaj(&ob);
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055
		TEST_ASSERT_EQUAL(5 , ob.kockice[2].broj);
	}
}

// 4. test
TEST(bacaj_tests , sve_kockice_zakljucane)
{		
	uint8_t i;
	uint8_t j;

	for(i=0 ; i < broj_kockica ; i++)	//inicijalizacija svih kockica na poznatu vrednost,
	{					//pa zakljucavanje
	ob.kockice[i].broj = 5;
	ob.kockice[i].zakljucano = 1;
	}

	for(i=0 ; i < 10 ; i++)			// 10 pokusaja bacanja zakljucanuih kockica - inicijalizovana vrednost 
	{					// ne sme biti promenjena
<<<<<<< HEAD
		bacaj_jednom(&ob);
=======
		bacaj(&ob);
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055
		for(j=0 ; j < broj_kockica ; j++)
		{
			TEST_ASSERT_EQUAL(5 , ob.kockice[j].broj);
		}	
	}
}

// 5. test
<<<<<<< HEAD

TEST(bacaj_tests , nedozvoljeno_bacanje)
{		
	uint8_t i;
	
	for(i=0 ; i < 10 ; i++)
	{	
		if(bacaj_jednom(&ob))
=======
TEST(bacaj_tests , dozvoljena_3_bacanja)
{		
	uint8_t i;
	
	
	for(i=0 ; i < 10 ; i++)
	{	
		if(!bacaj(&ob))
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055
		{
			TEST_ASSERT_EQUAL(1 , ob.br_bacanja <= 3);
		}else
		{
<<<<<<< HEAD
			TEST_ASSERT_EQUAL(0 , ob.br_bacanja <= 3);
			printf("\n nedozvoljeno bacanje kockica \n");		
		}	
	}
}


/***************************TESTOVI_ZA_zakljucaj/otkljucaj **************************************************************************
*/

// 6. test
TEST(zakljucaj_tests , dobro_zaljucane_kockice)
{		
	
	uint8_t i;
	uint8_t kockica_koju_zakljucavamo=3;

	for(i=0 ; i < broj_kockica ; i++)	
	{					
	ob.kockice[i].zakljucano = 0;
	}

	zakljucaj(&ob, kockica_koju_zakljucavamo);

	
	TEST_ASSERT_EQUAL(1 , ob.kockice[kockica_koju_zakljucavamo].zakljucano);

}

// 7. test
TEST(zakljucaj_tests , ispravno_otkljucane_kockice)
{		
	
	uint8_t i;
	uint8_t kockica_koju_otkljucavamo=3;

	for(i=0 ; i < broj_kockica ; i++)	
	{					
	ob.kockice[i].zakljucano =1;
=======
			printf("\n nedozvoljeno bacanje kockica \n");		
		}	
>>>>>>> 69cb6fbc0d09b13d2a641d01fdde49d4b5f73055
	}

	zakljucaj(&ob, kockica_koju_otkljucavamo);

	TEST_ASSERT_EQUAL(0 , ob.kockice[kockica_koju_otkljucavamo].zakljucano);

}

/***************************TESTOVI_ZA_bacanje_runda**************************************************************************
*/

// 8. test
TEST(bacanja_runda_tests , dozvoljena_3_bacanja)
{		
	bacaj(&ob);
	TEST_ASSERT_EQUAL(1 , ob.br_bacanja <= 3);			
}


// 9. test
TEST(bacanja_runda_tests , bacanje_runda)
{		
	
	TEST_ASSERT_EQUAL(0 , 0);
	
}


/***************************TESTOVI_ZA_ispis**************************************************************************
*/

// 10. test*/
TEST(ispis_tests , ispis)
{		
	uint8_t i;
	uint8_t privremeni[broj_kockica];	
	
	bacaj_jednom(&ob);
	for(i=0 ; i < broj_kockica ; i++)
	{
		privremeni[i]=ob.kockice[i].broj;
		printf("\n%d.test %d",i+1,privremeni[i]);
	}	

	ispis_rezultata_bacanja(&ob);
			
	TEST_ASSERT_EQUAL(0 , 0);
			
	
}

// 6. test
TEST(bacaj_tests , ispis)
{		
	uint8_t i;
	
	
	//for(i=0 ; i < 10 ; i++)
	{	
		bacaj(&ob);
for (i=0; i< 5 ; i ++) printf(" . . %d ", ob.kockice[i].broj);
		ispis_rezultata_bacanja(&ob);
	}
		
	TEST_ASSERT_EQUAL(0 , 0);
			
	
}



