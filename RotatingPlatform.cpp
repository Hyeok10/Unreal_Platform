#include "RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"

ARotatingPlatform::ARotatingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    // Static Mesh Component 생성 및 루트 컴포넌트로 설정
    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    // 기본 회전 속도 (초당 45도)
    RotationSpeed = 45.0f;
}

void ARotatingPlatform::BeginPlay()
{
    Super::BeginPlay();
}

void ARotatingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // DeltaTime과 RotationSpeed를 곱하여 매 프레임 회전 추가 (로컬 좌표 기준)
    FRotator DeltaRotation(0.f, RotationSpeed * DeltaTime, 0.f);
    AddActorLocalRotation(DeltaRotation);
}
