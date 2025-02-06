#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class SP_TASK_6TH_API ARotatingPlatform : public AActor
{
    GENERATED_BODY()

public:
    ARotatingPlatform();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PlatformMesh;

    // 회전 속도 (X, Y, Z축 개별 회전 가능)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    FRotator RotationSpeed;

    // Sin 함수를 사용해 스케일 변화를 적용할지 여부
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
    bool bUseSinScale;

    // Sin 주기
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
    float ScaleFrequency;

    // 스케일 변동 폭
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
    float ScaleAmplitude;

    // 게임 시작 시 저장되는 기본 스케일
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scale|SinWave")
    FVector InitialScale;

private:
    UFUNCTION()
    void ChangeColor();

    FTimerHandle ColorChangeTimerHandle;
    FTimerHandle RepeatingColorChangeTimerHandle;
};
