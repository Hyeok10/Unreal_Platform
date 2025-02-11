#include "RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Materials/MaterialInstanceDynamic.h"

ARotatingPlatform::ARotatingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    RotationSpeed = FRotator(0.f, 45.f, 0.f);
    bUseSinScale = false;
    ScaleFrequency = 1.f;
    ScaleAmplitude = 0.2f;
}

void ARotatingPlatform::BeginPlay()
{
    Super::BeginPlay();

    InitialScale = GetActorScale3D();

    GetWorldTimerManager().SetTimer(
        ColorChangeTimerHandle,
        this,
        &ARotatingPlatform::ChangeColor,
        5.f,
        false
    );

    GetWorldTimerManager().SetTimer(
        RepeatingColorChangeTimerHandle,
        this,
        &ARotatingPlatform::ChangeColor,
        3.f,
        true
    );
}

void ARotatingPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AddActorLocalRotation(RotationSpeed * DeltaTime);

    if (bUseSinScale)
    {
        const float Time = GetWorld()->GetTimeSeconds();
        const float SineValue = FMath::Sin(Time * 2.f * PI * ScaleFrequency);
        const float ScaleFactor = 1.f + (ScaleAmplitude * SineValue);
        SetActorScale3D(InitialScale * ScaleFactor);
    }
}

void ARotatingPlatform::ChangeColor()
{
    if (PlatformMesh)
    {
        UMaterialInstanceDynamic* DynMaterial = PlatformMesh->CreateAndSetMaterialInstanceDynamic(0);
        if (DynMaterial)
        {
            const FLinearColor RandomColor = FLinearColor::MakeRandomColor();
            DynMaterial->SetVectorParameterValue(TEXT("Color"), RandomColor);
        }
    }
}
