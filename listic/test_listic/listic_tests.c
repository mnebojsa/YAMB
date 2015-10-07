#include "../../unity/unity_fixture.h"
#include "../src/listic.h"


LISTIC ls;
KOCKICE ob;


/****************************************** jedno_bacanje * testovi *************************************************************
*/

TEST_GROUP(racunaBodove_tests);


TEST_GROUP_RUNNER(racunaBodove_tests)
{
	RUN_TEST_CASE(racunaBodove_tests , ispravno_racuna_do_6ice);
	RUN_TEST_CASE(racunaBodove_tests , ispravno_racuna_min_i_max_kolonu);
	RUN_TEST_CASE(racunaBodove_tests , ispravno_racuna_skalu);
	RUN_TEST_CASE(racunaBodove_tests , ispravno_racuna_full);
	/*RUN_TEST_CASE(upisi_poene_u_polje_tests , sve_kockice_zakljucane);
	RUN_TEST_CASE(upisi_poene_u_polje_tests , nedozvoljeno_bacanje);
	*/
}

TEST_SETUP(racunaBodove_tests)
{
	KreirajPrazanListic(&ls);
}


TEST_TEAR_DOWN(racunaBodove_tests)
{
}


TEST(racunaBodove_tests , ispravno_racuna_do_6ice)
{		
	uint8_t i;
	uint8_t vrednost_za_koju_racunamo;
	uint8_t ret_vrednost;
	for(vrednost_za_koju_racunamo = 1; vrednost_za_koju_racunamo <= 6; vrednost_za_koju_racunamo++)
	{
		for(i = 0; i < broj_kockica; i++)
		{
			ob.rezultat_bacanja[i] = vrednost_za_koju_racunamo;
		}
		ret_vrednost=racunaBodove(&ob, vrednost_za_koju_racunamo );	
		TEST_ASSERT_EQUAL(5*vrednost_za_koju_racunamo, ret_vrednost);

		for(i = 0; i < broj_kockica; i++)
		{	
			if(i != 3)
			{
				ob.rezultat_bacanja[i] = vrednost_za_koju_racunamo;
			}else
			{	
				if(vrednost_za_koju_racunamo != 5)
				{
					ob.rezultat_bacanja[i] = 5;
				}else
				{
					ob.rezultat_bacanja[i] = 3;
				}
			}
		}
		ret_vrednost=racunaBodove(&ob, vrednost_za_koju_racunamo );	
		TEST_ASSERT_EQUAL(4*vrednost_za_koju_racunamo , ret_vrednost);

		for(i = 0; i < broj_kockica; i++)
		{	
			if(i != 0 && i != 4)
			{
				ob.rezultat_bacanja[i] = vrednost_za_koju_racunamo;
			}else
				if(vrednost_za_koju_racunamo != 5)
				{
					ob.rezultat_bacanja[i] = 5;
				}else
				{
					ob.rezultat_bacanja[i] = 3;
				}
		}
		ret_vrednost=racunaBodove(&ob, vrednost_za_koju_racunamo );	
		TEST_ASSERT_EQUAL(3*vrednost_za_koju_racunamo , ret_vrednost);

		for(i = 0; i < broj_kockica; i++)
		{	
			if(i == 3 || i==4)
			{
				ob.rezultat_bacanja[i] = vrednost_za_koju_racunamo;
			}else
			{
				if(vrednost_za_koju_racunamo != 5)
				{
					ob.rezultat_bacanja[i] = 5;
				}else
				{
					ob.rezultat_bacanja[i] = 3;
				}
			}
		}
		ret_vrednost=racunaBodove(&ob, vrednost_za_koju_racunamo );	
		TEST_ASSERT_EQUAL(2*vrednost_za_koju_racunamo , ret_vrednost);

		for(i = 0; i < broj_kockica; i++)
		{	
			if(i == 3)
			{
				ob.rezultat_bacanja[i] = vrednost_za_koju_racunamo;
			}else
			{
				if(vrednost_za_koju_racunamo != 5)
				{
					ob.rezultat_bacanja[i] = 5;
				}else
				{
					ob.rezultat_bacanja[i] = 3;
				}
			}
		}
		ret_vrednost=racunaBodove(&ob, vrednost_za_koju_racunamo );	
		TEST_ASSERT_EQUAL(vrednost_za_koju_racunamo , ret_vrednost);

		for(i = 0; i < broj_kockica; i++)
		{	
			if(vrednost_za_koju_racunamo != 5)
			{
				ob.rezultat_bacanja[i] = 5;
			}else
			{
				ob.rezultat_bacanja[i] = 3;
			}	
		}
		ret_vrednost=racunaBodove(&ob, vrednost_za_koju_racunamo );	
		TEST_ASSERT_EQUAL(0 , ret_vrednost);
				
	}

}

TEST(racunaBodove_tests , ispravno_racuna_min_i_max_kolonu)
{		
	uint8_t i;
	uint8_t ret_vrednost;
	
		for(i = 0; i < broj_kockica; i++)
		{
			ob.rezultat_bacanja[i] = i+1;
		}
		ret_vrednost=racunaBodove(&ob, 7 );	
		TEST_ASSERT_EQUAL(15, ret_vrednost);

		ret_vrednost=racunaBodove(&ob, 8 );	
		TEST_ASSERT_EQUAL(15, ret_vrednost);
		
}

TEST(racunaBodove_tests , ispravno_racuna_skalu)
{		
	uint8_t i;
	uint8_t ret_vrednost;
	
		for(i = 0; i < broj_kockica; i++)
		{
			ob.rezultat_bacanja[i] = i+1;
		}
		ret_vrednost=racunaBodove(&ob, 9);	
		TEST_ASSERT_EQUAL(30, ret_vrednost);

		for(i = 0; i < broj_kockica; i++)
		{
			ob.rezultat_bacanja[i] = i+2;
		}
		ret_vrednost=racunaBodove(&ob, 9);	
		TEST_ASSERT_EQUAL(40, ret_vrednost);
		
}

TEST(racunaBodove_tests , ispravno_racuna_full)
{		
	uint8_t i;
	uint8_t ret_vrednost;
	
		for(i = 0; i < broj_kockica; i++)
		{
			if(i<2)
			{
				ob.rezultat_bacanja[i] = 2;
			}else
			{
				ob.rezultat_bacanja[i] = 5;
			}
		}
		ret_vrednost=racunaBodove(&ob, 10);	
		TEST_ASSERT_EQUAL(46, ret_vrednost);

		for(i = 0; i < broj_kockica; i++)
		{
			if(i<2)
			{
				ob.rezultat_bacanja[i] = 5;
			}else
			{
				ob.rezultat_bacanja[i] = 2;
			}
		}		ret_vrednost=racunaBodove(&ob, 10);	
		TEST_ASSERT_EQUAL(39, ret_vrednost);
		
}


