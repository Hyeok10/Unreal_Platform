#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"

AMovingPlatform::AMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    // Static Mesh Component ���� �� ��Ʈ ������Ʈ�� ����
    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    // �⺻ �̵� �ӵ� �� �̵� ����
    MoveSpeed = 200.f; // �ʴ� 200 ���� �̵�
    MaxRange = 500.f;  // ���� ��ġ���� 500 ���� �̵� ����
    MoveDirection = FVector(1.f, 0.f, 0.f); // �⺻ X�� �̵�

    bMovingForward = true;
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();
    StartLocation = GetActorLocation(); // ���� ��ġ ����
}

void AMovingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ���� ��ġ�� ������
    FVector CurrentLocation = GetActorLocation();

    // �̵� �Ÿ� ���
    float MoveAmount = MoveSpeed * DeltaTime;
    FVector Offset = (bMovingForward ? MoveDirection : -MoveDirection) * MoveAmount;

    // �� ��ġ ���
    FVector NewLocation = CurrentLocation + Offset;

    // ���� ��ġ���� ������� �̵��� �Ÿ� ���
    float DistanceFromStart = FVector::Dist(StartLocation, NewLocation);

    // �̵� ������ �����ؾ� �ϴ��� Ȯ��
    if (DistanceFromStart >= MaxRange)
    {
        bMovingForward = !bMovingForward; // �̵� ���� ����
        NewLocation = CurrentLocation; // ���� ��ġ �����Ͽ� ���� �̵� ����
    }

    // �� ��ġ ����
    SetActorLocation(NewLocation);
}
