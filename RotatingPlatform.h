#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h" 

UCLASS()
class SP_HW_6TH_API ARotatingPlatform : public AActor
{
    GENERATED_BODY() 

public:
    ARotatingPlatform();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PlatformMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    FRotator RotationSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
    bool bUseSinScale;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
    float ScaleFrequency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scale|SinWave")
    float ScaleAmplitude;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scale|SinWave")
    FVector InitialScale;

private:
    UFUNCTION()
    void ChangeColor();

    FTimerHandle ColorChangeTimerHandle;
    FTimerHandle RepeatingColorChangeTimerHandle;
};
