#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class SP_TASK_6TH_API AMovingPlatform : public AActor
{
    GENERATED_BODY()

public:
    AMovingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // 발판의 메쉬 컴포넌트
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PlatformMesh;

    // 이동 속도
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    float MoveSpeed;

    // 최대 이동 거리
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    float MaxRange;

    // 이동 방향
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    FVector MoveDirection;

private:
    FVector StartLocation; // 시작 위치 저장
};
