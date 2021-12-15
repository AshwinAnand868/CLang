/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Ashwin Anand
	ID     : 152042206
	Email  : aanand24@myseneca.ca
	Section: IPC144 NDD
*/
#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>

#define maxPathLength 70
#define minPathLength 10
#define multipleOf 5
struct PlayerInfo
{
	int nLives;
	char player;
	int nTreasures;
	int hisOfPosns[maxPathLength];
};

struct GameInfo
{
	int nMoves;
	int dynamicPathLength;
	int bombs[maxPathLength];
	int treasures[maxPathLength];
};

int main(void)
{


	const int maxLives = 10, minLives = 1;
	int firstFlag, roundedMovValidator, start, end, i, bombInputLimiter, Inputa, Inputb, Inputc, Inputd, Inpute,thirdFlag, startLimiter, endLimiter, treasureInputLimiter;
	double movesValidator;
	start = 1;
	end = multipleOf;
	thirdFlag = 1;
	Inputa = 0, Inputb = 1, Inputc = 2, Inputd = 3, Inpute = 4;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n");
	printf("\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	struct PlayerInfo playerInfo = { 0 };
	struct GameInfo gameInfo = { 0,0,{0},{0} };


	printf("Enter a single character to represent the player: ");
	scanf(" %c", &playerInfo.player);

	do
	{

		printf("Set the number of lives: ");
		scanf("%d", &playerInfo.nLives);

		firstFlag = 1;
		if (playerInfo.nLives >= minLives && playerInfo.nLives <= maxLives)
		{
			firstFlag = 0;
		}
		else
		{
			printf("     Must be between 1 and 10!\n");
		}

	} while (firstFlag);

	printf("Player configuration set-up is complete\n\n");

	printf("GAME Configuration\n");
	printf("------------------\n");

	do
	{
		printf("Set the path length (a multiple of %d between %d-%d): ", multipleOf, minPathLength, maxPathLength);
		scanf("%d", &gameInfo.dynamicPathLength);

		firstFlag = 1;
		if (gameInfo.dynamicPathLength >= minPathLength && gameInfo.dynamicPathLength <= maxPathLength && gameInfo.dynamicPathLength % multipleOf == 0)
		{
			firstFlag = 0;
		}
		else
		{
			printf("     Must be a multiple of %d and between %d-%d!!!\n", multipleOf, minPathLength, maxPathLength);
		}
	} while (firstFlag);





	do
	{
		firstFlag = 1;
		movesValidator = 0.75 * gameInfo.dynamicPathLength;

		roundedMovValidator = movesValidator + 0.5;
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gameInfo.nMoves);
		if (gameInfo.nMoves >= playerInfo.nLives && gameInfo.nMoves <= roundedMovValidator)
		{
			firstFlag = 0;
		}
		else
		{
			printf("    Value must be between %d and %d\n", playerInfo.nLives, roundedMovValidator);
		}
	} while (firstFlag);




	bombInputLimiter = gameInfo.dynamicPathLength / multipleOf;
	printf("\n");
	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");




	for (i = 0; i < bombInputLimiter; i++)
	{
	


		if (start == 1 && end == multipleOf)
		{
			printf("   Positions [ %d- %d]: ", start, end);
		}
		else if (start >= startLimiter && end <= endLimiter && thirdFlag)
		{
			printf("   Positions [ %d-%d]: ", start, end);
		}
		else if (start > 10 && thirdFlag == 0)
		{
			printf("   Positions [%d-%d]: ", start, end);
		}
		
		scanf("%d %d %d %d %d", &gameInfo.bombs[Inputa], &gameInfo.bombs[Inputb], &gameInfo.bombs[Inputc], &gameInfo.bombs[Inputd], &gameInfo.bombs[Inpute]);

		start = start + multipleOf;
		startLimiter = start;
		end = end + multipleOf;
		endLimiter = end;
		if (start > 10)
		{
			thirdFlag = 0;

		}
		Inputa += multipleOf;
		Inputb += multipleOf;
		Inputc += multipleOf;
		Inputd += multipleOf;
		Inpute += multipleOf;
	}
	printf("BOMB placement set\n\n");

	treasureInputLimiter = bombInputLimiter;

	start = 1, end = multipleOf, Inputa = 0, Inputb = 1, Inputc = 2, Inputd = 3, Inpute = 4, endLimiter = multipleOf;

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
	thirdFlag = 1;
	for (i = 0; i < treasureInputLimiter; i++)
	{
	
		
		if (start == 1 && end == endLimiter)
		{
			printf("   Positions [ %d- %d]: ", start, end);
		}
		else if (start >= startLimiter && end <= endLimiter && thirdFlag)
		{
			printf("   Positions [ %d-%d]: ", start, end);
		}
		else if (start > 10 && thirdFlag == 0)
		{
			printf("   Positions [%d-%d]: ", start, end);
		}

		scanf("%d %d %d %d %d", &gameInfo.treasures[Inputa], &gameInfo.treasures[Inputb], &gameInfo.treasures[Inputc], &gameInfo.treasures[Inputd], &gameInfo.treasures[Inpute]);


		start = start + multipleOf;
		startLimiter = start;
		end = end + multipleOf;
		endLimiter = end;
		if (start > 10)
		{
			thirdFlag = 0;
			
		}
		Inputa += multipleOf;
		Inputb += multipleOf;
		Inputc += multipleOf;
		Inputd += multipleOf;
		Inpute += multipleOf;
	}
	printf("TREASURE placement set\n\n");

	printf("GAME configuration set-up is complete...\n\n");

	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");

	printf("Player:\n");
	scanf("%*c");
	printf("   Symbol     : %c\n", playerInfo.player);
	printf("   Lives      : %d\n", playerInfo.nLives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", gameInfo.dynamicPathLength);


	for (i = 0; i < gameInfo.dynamicPathLength; i++)
	{
		if (i == 0)
		{
			printf("   Bombs      : ");
		}
		printf("%d", gameInfo.bombs[i]);

	}
	printf("\n");

	for (i = 0; i < gameInfo.dynamicPathLength; i++)
	{
		if (i == 0)
		{
			printf("   Treasure   : ");
		}
		printf("%d", gameInfo.treasures[i]);
	}

	printf("\n\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	return 0;
}
