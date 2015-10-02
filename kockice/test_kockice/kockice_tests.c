#include "../../unity/unity_fixture.h"
#include "../src/kockice.h"


KOCKICE kocke;

TEST_GROUP(bacaj_tests);


TEST_GROUP_RUNNER(bacaj_tests)
{
	RUN_TEST_CASE(bacaj_tests, dobijeni_rezultati_bacanja_su_u_predvidjenim_granicama);
	/*RUN_TEST_CASE(PlayerCanTrowTests, second_roll_in_curent_frame);
	RUN_TEST_CASE(PlayerCanTrowTests, illegal_roll_in_current_frame);
	RUN_TEST_CASE(PlayerCanTrowTests, player_had_not_strike_in_current_frame);
	RUN_TEST_CASE(PlayerCanTrowTests, player_had_strike_in_current_frame);
	*/
}

TEST_SETUP(bacaj_tests)
{
	kreirajKockice(&kocke);
}


TEST_TEAR_DOWN(bacaj_tests)
{
}
/******************************************************************************************TESTOVI_ZA_writeDownTheScore***********************************************************************************/


// 1. test
TEST(bacaj_tests , dobijeni_rezultati_bacanja_su_u_predvidjenim_granicama)
{
	uint8_t i;
	//baci(&kocke);
	for(i=0 ; i < 5; i++)
	{	
		printf("%d\n",slucajan_br() );		
		TEST_ASSERT_EQUAL(1, kocke[i].broj>0);
	}
}


