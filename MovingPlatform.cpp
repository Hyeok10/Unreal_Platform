#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    MoveSpeed = 200.f;
    MaxRange = 500.f;
    MoveDirection = FVector(1.f, 0.f, 0.f);
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay(); // Super를 올바르게 사용하도록 보장

    StartLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector CurrentLocation = GetActorLocation();
    float MoveAmount = MoveSpeed * DeltaTime;
    FVector Offset = MoveDirection * MoveAmount;
    FVector NewLocation = CurrentLocation + Offset;

    float DistanceFromStart = FVector::Dist(StartLocation, NewLocation);
    
    if (DistanceFromStart > MaxRange)
    {
        float Overshoot = DistanceFromStart - MaxRange;
        NewLocation -= MoveDirection * Overshoot;
        MoveDirection *= -1;
    }

    SetActorLocation(NewLocation);
}
