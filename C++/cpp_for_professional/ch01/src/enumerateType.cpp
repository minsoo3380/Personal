#include <iostream>

int main()
{
	// const 
//	const int PieceTypeKing = 0;
//	const int PieceTypeQueen= 1;
//	const int PieceTypeRook= 2;
//	const int PieceTypePawn = 3;
	// 기타
//	int myPiece = PieceTypeKing;

	// using enum
	
	enum PieceType {
		PieceTypeKing		// 0
		, PieceTypeQueen	// 1
		, PieceTypeRook		// 2
		, PieceTypePawn		// 3
	};

	PieceType myPiece;
//	myPiece = 0;	// error

/* initalized enum type
 * enum PieceType { PieceTypeKing = 1, PieceTypeQueen, PieceTypeRook = 11, PieceTypePawn};
 * PieceTypeQueen == 2
 * PieceTYpePawn = 12
 */

	myPiece = PieceTypeRook;
	std::cout << "myPiece = PieceTypeRook : " << myPiece << std::endl;

	return 0;
}


