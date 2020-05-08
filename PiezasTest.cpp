/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, drop_piece_check)
{

	Piezas obj;
	int ret = obj.dropPiece(2);
	cout << ret << endl;

}

TEST(PiezasTest, greaterthan_num)
{

	Piezas obj;
	obj.dropPiece(4);

}

TEST(PiezasTest, neg_num)
{

	Piezas obj;
	obj.dropPiece(4);

}


