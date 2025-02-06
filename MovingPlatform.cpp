#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    // Static Mesh Component 생성 및 루트 컴포넌트로 설정
    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    // 기본 이동 속도 및 이동 범위
    MoveSpeed = 200.f; // 초당 200 유닛 이동
    MaxRange = 500.f;  // 시작 위치에서 500 유닛 이동 가능
    MoveDirection = FVector(1.f, 0.f, 0.f); // 기본 X축 이동
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();
    StartLocation = GetActorLocation(); // 최초 위치 저장
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector CurrentLocation = GetActorLocation();
    float MoveAmount = MoveSpeed * DeltaTime;
    FVector Offset = MoveDirection * MoveAmount;
    FVector NewLocation = CurrentLocation + Offset;

    // 시작 위치에서의 이동 거리 계산
    float DistanceFromStart = FVector::Dist(StartLocation, NewLocation);
    
    if (DistanceFromStart > MaxRange)
    {
        // 초과된 거리 보정
        float Overshoot = DistanceFromStart - MaxRange;
        NewLocation -= MoveDirection * Overshoot;

        // 이동 방향 반전
        MoveDirection *= -1;
    }

    SetActorLocation(NewLocation);
}
