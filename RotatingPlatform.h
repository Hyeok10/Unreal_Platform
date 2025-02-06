#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class SP_TASK_6TH_API ARotatingPlatform : public AActor
{
    GENERATED_BODY()

public:
    // 기본 생성자
    ARotatingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // 발판의 메쉬 컴포넌트 (에디터에서 확인 가능)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PlatformMesh;

    // 회전 속도 (초당 회전 각도, 에디터에서 조절 가능)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
    float RotationSpeed;
};
