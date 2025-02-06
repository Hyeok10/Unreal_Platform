#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h" // 반드시 필요

UCLASS()
class SP_HW_6TH_API AMovingPlatform : public AActor
{
    GENERATED_BODY() // 반드시 필요

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PlatformMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    float MoveSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    float MaxRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    FVector MoveDirection;

private:
    FVector StartLocation;
};
