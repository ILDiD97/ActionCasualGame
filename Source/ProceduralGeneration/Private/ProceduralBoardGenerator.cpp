// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralBoardGenerator.h"

#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProceduralBoardGenerator::AProceduralBoardGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProceduralBoardGenerator::BeginPlay()
{
	Super::BeginPlay();
	GenerateBoard();
}

// Called every frame
void AProceduralBoardGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProceduralBoardGenerator::GenerateBoard()
{
	int whileLoop = 0;
	const int maxLoop = limitBoardX * limitBoardY;
	iterationCount = maxLoop ;
	UCell* TempCell = NewObject<UCell>(this, UCell::StaticClass());
	board.Init(TempCell,maxLoop);
	
	UWorld* world = GetWorld();
	int XAxis = 0;
	int YAxis = 0;
	
	while (whileLoop < maxLoop)
	{
		UCell* Cell = NewObject<UCell>(this, UCell::StaticClass());

		Cell->boardID = whileLoop;
		Cell->worldLocation.SetLocation(FVector(distanceBetweenCells * XAxis, distanceBetweenCells * YAxis, 0));
		Cell->worldLocation.SetRotation(FRotator(0,0,0).Quaternion());
		Cell->worldLocation.SetScale3D(FVector(1,1,1));
		Cell->neighborsID.Init(whileLoop,4);
		
		if(YAxis > 0)
		{
			board[whileLoop]->neighborsID.Add(whileLoop - 1);
			board[whileLoop - 1]->neighborsID.Add(whileLoop);
		}

		if(XAxis > 0)
		{
			board[whileLoop]->neighborsID.Add(whileLoop - limitBoardY);
			board[whileLoop - limitBoardY]->neighborsID.Add(whileLoop);
		}
		
		board[whileLoop] = Cell;

		FActorSpawnParameters SpawnParameters;
		Cell->floorActor = Cast<AFloorActor>(world->SpawnActor
			(floorClass, &Cell->worldLocation, SpawnParameters));
		
		Horizontal axisY = Horizontal::Void;
		Vertical axisX = Vertical::Void;
		if(whileLoop <= limitBoardY -1)
		{
			axisY = Horizontal::Sud;
		}
		if(whileLoop >= limitBoardY * limitBoardX - limitBoardY)
		{
			axisY = Horizontal::Nord;
		}
		
		
		if(YAxis == limitBoardY - 1)
		{
			YAxis = 0;
			XAxis++;
			axisX = Vertical::Ovest;
		}
		else if(YAxis == 0)
		{
			YAxis++;
			axisX = Vertical::Est;
		}
		else
		{
			YAxis++;
		}
		
		Cell->floorActor->SetWallsVisibility(axisY, axisX);
		Cell->floorActor->SetFloorRandomMesh(); 
		
		whileLoop++;
	}
	
	//GenerateChunks(maxLoop / 9);

	AGameModeBase* GameModeBase = UGameplayStatics::GetGameMode(world);
	if(GameModeBase)
	{
		GameModeBase->StartPlay();
	}
}

void AProceduralBoardGenerator::GenerateChunks(int chunkLimit)
{
	int chunkCount = 0;
	UChunk* tempChunk = NewObject<UChunk>(this, chunkClass[0]);
	chunks.Init(tempChunk, 9);
	
	while (chunkCount < chunkLimit)
	{
		tempChunk = NewObject<UChunk>(this, chunkClass[FMath::RandRange(0, chunkClass.Num()-1)]);

		for(int i = 0; i < 9; i++)
		{
			if(i < 3) tempChunk->cellsChunk[i] = board[chunkCount + i];
			else if( i < 6) tempChunk->cellsChunk[i] = board[chunkCount + 9 + i];
			else tempChunk->cellsChunk[i] = board[chunkCount + 18 + i];
		}
		chunkCount++;
	}
}

void UChunk::GenerateObstacles()
{
}

