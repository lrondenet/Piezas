/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include <iostream>
using namespace std;
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
	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);
	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);
	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);

}

TEST(PiezasTest, greaterthan_num)
{
	Piezas obj;
	obj.dropPiece(4);
}

TEST(PiezasTest, neg_num)
{
	Piezas obj;
	obj.dropPiece(-1);
}

TEST(PiezasTest, out_of_bounds1)
{
	Piezas obj;
	obj.pieceAt(3,4);
}

TEST(PiezasTest, out_of_bounds2)
{
	Piezas obj;
	obj.pieceAt(-1,-2);
}


TEST(PiezasTest, pieceAt_checkX)
{
	Piezas obj;
	obj.pieceAt(2,0);
}

TEST(PiezasTest, pieceAt_checkO)
{
	Piezas obj;
	obj.pieceAt(2,1);
}





