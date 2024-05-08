// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloorActor.h"
#include "GameFramework/Actor.h"
#include "ProceduralBoardGenerator.generated.h"


UCLASS()
class PROCEDURALGENERATION_API AProceduralBoardGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralBoardGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Board")
	TSubclassOf<AFloorActor> floorClass;

	UPROPERTY(EditAnywhere, Category = "Board")
	TArray<TSubclassOf<UChunk>> chunkClass;
	
	UPROPERTY(VisibleAnywhere, Category = "Board")
	TArray<UChunk*> chunks;
	
	UPROPERTY(VisibleAnywhere, Category = "Board")
	TArray<UCell*> board;
	
	UPROPERTY(VisibleAnywhere, Category="Board")
	int iterationCount;
	
	UPROPERTY(EditAnywhere, Category = "Board")
	int limitBoardX;

	UPROPERTY(EditAnywhere, Category = "Board")
	int limitBoardY;

	UPROPERTY(EditAnywhere,Category = "CellDistnace")
	int distanceBetweenCells;
	
	UFUNCTION()
	void GenerateBoard();

	UFUNCTION()
	void GenerateChunks(int chunkLimit);

};

UCLASS(Blueprintable)
class UCell : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	AFloorActor* floorActor;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform worldLocation;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<int> neighborsID;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int boardID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool canObstacle;
	
};

UCLASS()
class UChunk : public UObject
{
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere)
	TArray<UCell*> cellsChunk;
	
	UFUNCTION()
	virtual void GenerateObstacles();
};
