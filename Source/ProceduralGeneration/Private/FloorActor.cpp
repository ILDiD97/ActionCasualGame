// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorActor.h"

// Sets default values
AFloorActor::AFloorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Collider");
	SetRootComponent(BoxComponent);
	
	floor = CreateDefaultSubobject<UStaticMeshComponent>("Floor");
	floor->SetupAttachment(BoxComponent);
	floor->AddLocalOffset(floorPostion);
	
	nordWall = CreateDefaultSubobject<UStaticMeshComponent>("NordWall");
	nordWall->SetupAttachment(BoxComponent);
	nordWall->AddLocalOffset(nordWallPostion);
	
	sudWall = CreateDefaultSubobject<UStaticMeshComponent>("SudWall");
	sudWall->SetupAttachment(BoxComponent);
	sudWall->AddLocalOffset(sudWallPostion);
	
	ovestWall = CreateDefaultSubobject<UStaticMeshComponent>("OvestWall");
	ovestWall->SetupAttachment(BoxComponent);
	ovestWall->AddLocalOffset(ovestWallPostion);
	
	estWall = CreateDefaultSubobject<UStaticMeshComponent>("EstWall");
	estWall->SetupAttachment(BoxComponent);
	estWall->AddLocalOffset(estWallPostion);

	obstacle = CreateDefaultSubobject<UStaticMeshComponent>("Obstacle");
	obstacle->SetupAttachment(BoxComponent);
	obstacle->AddLocalOffset(obstaclePostion);
	
}

// Called when the game starts or when spawned
void AFloorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloorActor::SetWallsVisibility(Horizontal horizontal, Vertical vertical)
{
	UWorld* world = GetWorld();
	FActorSpawnParameters SpawnParameters;
	AActor* initActor = nullptr;
	colliders.Init(initActor, 2);
	switch (horizontal)
	{
		case Horizontal::Nord:
			sudWall->SetVisibility(false);
			sudWall->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
			SetWallRandomMesh(nordWall);
			if(world)
			{
				colliders[0] = world->SpawnActor(colliderClass, &nordWall->GetComponentTransform(),SpawnParameters);
			}
			break;
		case Horizontal::Sud:
			nordWall->SetVisibility(false);
			nordWall->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
			SetWallRandomMesh(sudWall);
			if(world)
			{
				colliders[0] = world->SpawnActor(colliderClass, &sudWall->GetComponentTransform(),SpawnParameters);
			}
			break;
		default:
			nordWall->SetVisibility(false);
			sudWall->SetVisibility(false);
			break;
	}
	switch (vertical)
	{
		case Vertical::Est:
			ovestWall->SetVisibility(false);
			ovestWall->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
			SetWallRandomMesh(estWall);
			if(world)
			{
				colliders[1] = world->SpawnActor(colliderClass, &estWall->GetComponentTransform(),SpawnParameters);
			}
			break;
		case Vertical::Ovest:
			estWall->SetVisibility(false);
			estWall->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
			SetWallRandomMesh(ovestWall);
			if(world)
			{
				colliders[1] = world->SpawnActor(colliderClass, &ovestWall->GetComponentTransform(),SpawnParameters);
			}
			break;
		default:
			ovestWall->SetVisibility(false);
			estWall->SetVisibility(false);
			break;
	}
	
}

void AFloorActor::SetFloorRandomMesh()
{
	floor->SetStaticMesh(floorMeshes[FMath::RandRange(0, floorMeshes.Num() - 1)]);
}

void AFloorActor::SetWallRandomMesh(UStaticMeshComponent* mesh)
{
	mesh->SetStaticMesh(wallMeshes[FMath::RandRange(0,wallMeshes.Num() - 1)]);
}

void AFloorActor::SetObstacleVisibility()
{
	obstacle->SetStaticMesh(obstacleMesh);
	obstacle->SetCollisionResponseToChannel(ECC_Pawn,ECR_Block);
}

