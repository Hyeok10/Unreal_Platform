#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class SP_TASK_6TH_API ARotatingPlatform : public AActor
{
    GENERATED_BODY()

public:
    // �⺻ ������
    ARotatingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // ������ �޽� ������Ʈ (�����Ϳ��� Ȯ�� ����)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PlatformMesh;

    // ȸ�� �ӵ� (�ʴ� ȸ�� ����, �����Ϳ��� ���� ����)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    float RotationSpeed;
};
