// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "FloorActor.generated.h"

UENUM(Blueprintable)
enum class Horizontal : UINT8
{
	Nord = 0,
	Sud = 1,
	Void = 2
};

UENUM(Blueprintable)
enum class Vertical : UINT8
{
	Ovest = 0,
	Est = 1,
	Void = 2
};

UCLASS()
class PROCEDURALGENERATION_API AFloorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorActor();

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMeshComponent* floor;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	FVector floorPostion;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	TArray<UStaticMesh*> floorMeshes;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMeshComponent* nordWall;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	FVector nordWallPostion;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMeshComponent* sudWall;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	FVector sudWallPostion;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMeshComponent* ovestWall;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	FVector ovestWallPostion;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMeshComponent* estWall;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	FVector estWallPostion;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMeshComponent* obstacle;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	TArray<UStaticMesh*> wallMeshes;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	FVector obstaclePostion;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMesh* obstacleMesh;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	TSubclassOf<AActor> colliderClass;

	UPROPERTY(VisibleAnywhere, Category = "Meshes")
	TArray<AActor*> colliders;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	int distanceBetweenMeshes;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	Horizontal horizontalWay;

	UPROPERTY(VisibleAnywhere)
	Vertical verticalWay;

	UFUNCTION()
	void SetWallsVisibility(Horizontal horizontal, Vertical vertical);

	UFUNCTION()
	void SetFloorRandomMesh();
	
	UFUNCTION()
	void SetWallRandomMesh(UStaticMeshComponent* mesh);
	
	UFUNCTION()
	void SetObstacleVisibility();

};


