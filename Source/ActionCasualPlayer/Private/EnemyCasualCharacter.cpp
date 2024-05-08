// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCasualCharacter.h"

void AEnemyCasualCharacter::CharMoveBidimensional(FVector2D axis)
{
	Super::CharMoveBidimensional(axis);
}

void AEnemyCasualCharacter::GetDamage(int damage)
{
	Super::GetDamage(damage);
	health -= damage;
}
