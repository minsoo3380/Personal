#include <iostream>

enum class PieceType
{
	King = 1,
	Queen,
	Rook = 10,
	Pawn
};

// conversion type
/*
 * enum class PieceType : unsigned long
 * {
 * 	King = 1,
 * 	Queen,
 * 	Rook = 10,
 * 	Pawn
 * }
 */

int main()
{
	PieceType piece = PieceType::King;

	std::cout << "PieceType piece : " << static_cast<int>(piece) << std::endl;

	return 0;
}
