#include "../../unity/unity_fixture.h"
#include "../src/kockice.h"


KOCKICE ob;

TEST_GROUP(bacaj_tests);


TEST_GROUP_RUNNER(bacaj_tests)
{
	RUN_TEST_CASE(bacaj_tests , rezultat_sl_br);
	RUN_TEST_CASE(bacaj_tests , ispravna_inicijalizacija);
	RUN_TEST_CASE(bacaj_tests , ne_baca_zakljucanu_kockicu);
	RUN_TEST_CASE(bacaj_tests , sve_kockice_zakljucane);
	RUN_TEST_CASE(bacaj_tests , dozvoljena_3_bacanja);
	RUN_TEST_CASE(bacaj_tests , ispis);
}

TEST_SETUP(bacaj_tests)
{
	inicijalizujKockice(&ob);
}


TEST_TEAR_DOWN(bacaj_tests)
{
}
/******************************************************************************************TESTOVI_ZA_writeDownTheScore***********************************************************************************/


// 1. test
TEST(bacaj_tests , rezultat_sl_br)
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
		bacaj(&ob);
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
		bacaj(&ob);
		for(j=0 ; j < broj_kockica ; j++)
		{
			TEST_ASSERT_EQUAL(5 , ob.kockice[j].broj);
		}	
	}
}

// 5. test
TEST(bacaj_tests , dozvoljena_3_bacanja)
{		
	uint8_t i;
	
	
	for(i=0 ; i < 10 ; i++)
	{	
		if(!bacaj(&ob))
		{
			TEST_ASSERT_EQUAL(1 , ob.br_bacanja <= 3);
		}else
		{
			printf("\n nedozvoljeno bacanje kockica \n");		
		}	
	}
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



