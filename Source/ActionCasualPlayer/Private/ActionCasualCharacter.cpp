// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCasualCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "AITypes.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnemyCasualCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
AActionCasualCharacter::AActionCasualCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActionCasualCharacter::BeginPlay()
{
	Super::BeginPlay();
	UWorld* world = GetWorld();
	if(world)
	{
		const FActorSpawnParameters SpawnParameters;
		cameraActor = Cast<AActionCasualCameraActor>(world->SpawnActor(cameraclass, &cameraWorldPos, SpawnParameters));
	}
}

// Called every frame
void AActionCasualCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(!isMoving && timerToShoot >= timeToShoot)
	{
		FindEnemy();
		timerToShoot = 0;
	}
	else
	{
		timerToShoot += DeltaTime;
	}
}

void AActionCasualCharacter::CharMoveBidimensional(FVector2D axis)
{
	FVector movement = FVector(GetActorLocation().X + axis.X * GetWorld()->GetDeltaSeconds() * speed,
		GetActorLocation().Y + axis.Y * GetWorld()->GetDeltaSeconds() * speed, GetActorLocation().Z);
	SetActorLocation(movement);
	AutoDirection(FVector(GetActorLocation().X + axis.X ,
		GetActorLocation().Y + axis.Y , GetActorLocation().Z));
	
	// const FVector forwardVector = GetActorLocation() + GetActorForwardVector();
	// const FVector rightVector = GetActorLocation() + GetActorRightVector();
	// AddMovementInput(forwardVector, axis.X * speed, true);
	// AddMovementInput(rightVector, axis.Y * speed, true);
	
	const float xAxis = FMath::Clamp(GetActorLocation().X,0, 1700);
	const float yAxis = FMath::Clamp(GetActorLocation().Y,0,1400);
	SetActorLocation(FVector(xAxis, yAxis, GetActorLocation().Z));
	cameraActor->SetCameraLocation(FVector2D(GetActorLocation().X, GetActorLocation().Y));
}

void AActionCasualCharacter::GetDamage(int damage)
{
	ICasualCharacterInterface::GetDamage(damage);
}

void AActionCasualCharacter::FindEnemy()
{
	TArray<AActor*> enemies;
	TArray<AActor*> actorToIgnore;
	actorToIgnore.Add(GetOwner());
 	const TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesArray;
	bool findEnemies = UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), 10000,
		ObjectTypesArray, AEnemyCasualCharacter::StaticClass(), actorToIgnore, enemies);
	
	if(findEnemies)
	{
		AutoDirection(enemies[0]->GetActorLocation());
	}
}

void AActionCasualCharacter::AutoDirection(FVector targetLocation)
{
	FVector actualTarget(targetLocation.X, targetLocation.Y, GetActorLocation().Z);
	FRotator direction = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), actualTarget);
	SetActorRotation(direction);
}




