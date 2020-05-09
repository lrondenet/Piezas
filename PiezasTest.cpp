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

TEST(PiezasTest, resetboardCheck)
{
	Piezas obj;
	obj.reset();
}

TEST(PiezasTest, drop_piece_check1)
{
	Piezas obj;
	Piece piece1 = obj.dropPiece(0);
	ASSERT_EQ(X, piece1);
}


TEST(PiezasTest, fill_board)
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

TEST(PiezasTest, column_full) {
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.dropPiece(0);
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
	Piece out_of_bounds = obj.pieceAt(3,4);
	ASSERT_EQ(Invalid, out_of_bounds);
}

TEST(PiezasTest, out_of_bounds2)
{
	Piezas obj;
	Piece out_of_bounds = obj.pieceAt(2,4);
	ASSERT_EQ(Invalid, out_of_bounds);
}


TEST(PiezasTest, pieceAt_checkX)
{
	Piezas obj;
	obj.dropPiece(0);
	Piece piece = obj.pieceAt(2,0);
	ASSERT_EQ(X, piece);
}

TEST(PiezasTest, pieceAt_checkO)
{
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(1);
	Piece piece = obj.pieceAt(2,1);
	ASSERT_EQ(O, piece);
}

TEST(PiezasTest, pieceAt_check1)
{
	Piezas obj;
	obj.dropPiece(1);
	Piece piece = obj.pieceAt(2,2);
}

TEST(PiezasTest, pieceAt_check2)
{
	Piezas obj;
	obj.dropPiece(1);
	Piece piece = obj.pieceAt(2,2);
}

TEST(PiezasTest, gameState)
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
	obj.gameState();
}

TEST(PiezasTest, empty_gameState)
{
	Piezas obj;
	obj.gameState();
}


TEST(PiezasTest, gameState_one)
{
	Piezas obj;
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(2);
	obj.dropPiece(3);
	obj.dropPiece(3);
	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);
	obj.gameState();
}

TEST(PiezasTest, gameState_equal)
{
	Piezas obj;
	obj.dropPiece(3);
	obj.dropPiece(2);
	obj.dropPiece(1);
	obj.dropPiece(0);
	obj.dropPiece(0);
	obj.dropPiece(1);
	obj.dropPiece(2);
	obj.dropPiece(3);
	obj.dropPiece(2);
	obj.dropPiece(3);
	obj.dropPiece(1);
	obj.dropPiece(0);
	obj.gameState();

}

// TEST(PiezasTest, gameState_two)
// {
// 	Piezas obj;
// 	obj.dropPiece(0);
// 	obj.dropPiece(0);
// 	obj.dropPiece(1);
// 	obj.dropPiece(0);
// 	obj.dropPiece(0);
// 	obj.dropPiece(1);
// 	obj.dropPiece(2);
// 	obj.dropPiece(3);
// 	obj.dropPiece(2);
// 	obj.dropPiece(3);
// 	obj.dropPiece(1);
// 	obj.dropPiece(30);
// 	obj.gameState();

// }







