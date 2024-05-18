/*
 * ConsoleView.cpp
 *
 * Created on: 03-Jan-2024
 * Author: Dabbiru Sunil
 */

#include "ConsoleView.h"

/**
 * @brief Constructor for the ConsoleView class.
 *
 * Initializes the ConsoleView with a pointer to the game board.
 *
 * @param board A pointer to the game board.
 */
ConsoleView::ConsoleView(Board *board) :
		board(board)
{

}

/**
 * @brief Prints the game boards (own and opponent) to the console.
 */
void ConsoleView::print()
{
	// Printing Own Ship
	//****************************Own_Ship************************
	int flag = 0;

	// Creating ownBoardPrint map that is to be printed
	std::set<GridPosition> AllShipGrids;
	for (auto ship : board->getOwnGrid().getShips())
	{
		for (auto shipGrids : ship.occupiedArea())
		{
			AllShipGrids.insert(shipGrids);
		}
	}
	std::map<std::pair<int, int>, std::string> ownBoardPrint;
	for (int row = 0; row < board->getOwnGrid().getRows(); row++)
	{
		for (int col = 0; col < board->getOwnGrid().getColumns(); col++)
		{
			ownBoardPrint[std::pair<int, int>(row, col)] = "~ ";
			for (auto shipGrid : AllShipGrids)
			{
				if ((shipGrid.getColumn() == col + 1)
						&& (shipGrid.getRow() == char(row + 65)))
				{
					for (auto eachShot : board->getOwnGrid().getShotAt())
					{
						if (((board->getOwnGrid().takeBlow(eachShot)
								== Shot::HIT)
								|| (board->getOwnGrid().takeBlow(eachShot)
										== Shot::SUNKEN))
								&& (eachShot.getRow() == char(row + 65))
								&& (eachShot.getColumn() == col + 1))
						{
							ownBoardPrint[std::pair<int, int>(row, col)] = "O ";
							flag = 1;
						}
					}
					if (flag == 0)
					{
						ownBoardPrint[std::pair<int, int>(row, col)] = "# ";
					}
					flag = 0;
				}
				for (auto eachShot : board->getOwnGrid().getShotAt())
				{
					if ((board->getOwnGrid().takeBlow(eachShot) == Shot::NONE)
							&& (eachShot.getRow() == char(row + 65))
							&& (eachShot.getColumn() == col + 1))
					{
						ownBoardPrint[std::pair<int, int>(row, col)] = "^ ";
					}
				}
			}
		}
	}

	// Printing ownBoardPrint
	std::cout
			<< "***********************OwnShip********************************"
			<< std::endl;
	if (board->getOwnGrid().getRows() > 9)
	{
		std::cout << "                    ";
		for (int col1 = 0, col2 = 0;
				col1 < board->getOwnGrid().getColumns() - 9; col1++)
		{
			if ((col1 + 1) % 10 == 0)
			{
				col2++;
			}
			std::cout << 1 + col2 << " ";
		}
	}
	std::cout << "\n";
	std::cout << "  ";
	for (int col = 0; col < board->getOwnGrid().getColumns(); col++)
	{
		std::cout << (col + 1) % 10 << " ";
	}
	std::cout << "\n";
	char DisplayRow = 'A';
	for (int row = 0; row < board->getOwnGrid().getRows(); row++)
	{
		std::cout << char((DisplayRow + row)) << " ";
		for (int col = 0; col < board->getOwnGrid().getColumns(); col++)
		{
			std::cout << ownBoardPrint[std::pair<int, int>(row, col)];
		}
		std::cout << std::endl;
	}
	std::cout
			<< "*********************************************************"
			<< std::endl;

	// Printing Opponent Ship
	//****************************Opponent_Ship************************
	// Creating opponentBoardPrint map that is to be printed
	std::map<std::pair<int, int>, std::string> opponentBoardPrint;
	for (int row = 0; row < board->getOpponentGrid().getRows(); row++)
	{
		for (int col = 0; col < board->getOpponentGrid().getColumns(); col++)
		{
			opponentBoardPrint[std::pair<int, int>(row, col)] = "~ ";
			for (auto shotOutput : board->getOpponentGrid().getShotsAt())
			{
				if ((shotOutput.first.getRow() == char(row + 65))
						&& (shotOutput.first.getColumn() == col + 1)
						&& (shotOutput.second == Shot::HIT))
				{
					opponentBoardPrint[std::pair<int, int>(row, col)] = "O ";
				}
				if ((shotOutput.first.getRow() == char(row + 65))
						&& (shotOutput.first.getColumn() == col + 1)
						&& (shotOutput.second == Shot::NONE))
				{
					opponentBoardPrint[std::pair<int, int>(row, col)] = "^ ";
				}
			}
		}
	}

	for (int row = 0; row < board->getOpponentGrid().getRows(); row++)
	{
		for (int col = 0; col < board->getOpponentGrid().getColumns(); col++)
		{
			for (auto sunkShipGrid : board->getOpponentGrid().getSunkenShips())
			{
				for (auto Grid : sunkShipGrid.occupiedArea())
				{
					if ((Grid.getRow() == char(row + 65))
							&& (Grid.getColumn() == col + 1))
					{
						opponentBoardPrint[std::pair<int, int>(row, col)] =
								"# ";
					}
				}
			}
		}
	}

	std::cout
			<< "***********************OpponenetShip***************************"
			<< std::endl;
	if (board->getOpponentGrid().getRows() > 9)
	{
		std::cout << "                    ";
		for (int col1 = 0, col2 = 0;
				col1 < board->getOpponentGrid().getColumns() - 9; col1++)
		{
			if ((col1 + 1) % 10 == 0)
			{
				col2++;
			}
			std::cout << 1 + col2 << " ";
		}
	}
	std::cout << "\n";
	std::cout << "  ";
	for (int col = 0; col < board->getOpponentGrid().getColumns(); col++)
	{
		std::cout << (col + 1) % 10 << " ";
	}
	std::cout << "\n";
	DisplayRow = 'A';
	for (int row = 0; row < board->getOpponentGrid().getRows(); row++)
	{
		std::cout << char((DisplayRow + row)) << " ";
		for (int col = 0; col < board->getOpponentGrid().getColumns(); col++)
		{
			std::cout << opponentBoardPrint[std::pair<int, int>(row, col)];
		}
		std::cout << std::endl;
	}
}
