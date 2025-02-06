#include "RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"

ARotatingPlatform::ARotatingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    // Static Mesh Component ���� �� ��Ʈ ������Ʈ�� ����
    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    // �⺻ ȸ�� �ӵ� (�ʴ� 45��)
    RotationSpeed = 45.0f;
}

void ARotatingPlatform::BeginPlay()
{
    Super::BeginPlay();
}

void ARotatingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // DeltaTime�� RotationSpeed�� ���Ͽ� �� ������ ȸ�� �߰� (���� ��ǥ ����)
    FRotator DeltaRotation(0.f, RotationSpeed * DeltaTime, 0.f);
    AddActorLocalRotation(DeltaRotation);
}
