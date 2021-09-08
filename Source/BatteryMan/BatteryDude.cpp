// Fill out your copyright notice in the Description page of Project Settings.


#include "BatteryDude.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include <string>
#include "AchievementSubSystem.h"
#include "Math/Vector.h"


// Sets default values
ABatteryDude::ABatteryDude()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 0.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bDead = false; 

	Power = 1000;
	Power_Threshold = 1;
	//LastPosition = FVector(-1640.002441, -700.0, 222.001526); // Spawn position must match the Playerstart, will change to match the map.

}

/*bool ABatteryDude::PositionJumped()
{
	FVector CurrentPosition = GetPosition();
	if (FVector::Dist(CurrentPosition, LastPosition) > 15.0f)
		return true;
	else {
		return false;
	}
} 
*/

/*FVector ABatteryDude::GetPosition()
{
	FVector MyPos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	return MyPos;
}
*/

// Called when the game starts or when spawned
void ABatteryDude::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
	Super::BeginPlay();
	
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ABatteryDude::OnBeginOverlap);

	if (Player_Power_Widget_Class != nullptr) {

		Player_Power_Widget = CreateWidget(GetWorld(), Player_Power_Widget_Class);
		Player_Power_Widget->AddToViewport();

	}

}

// Called every frame
void ABatteryDude::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

/*	if (ResetPosition()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player moved illegally, restarting game")));
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABatteryDude::RestartGame, 3.0f, false);
	}
*/
	/*if (PositionJumped()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Player moved illegally, restarting game")));
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABatteryDude::RestartGame, 3.0f, false);
	}
	LastPosition = GetPosition();
*/
	/*UE_LOG(LogTemp, Warning, TEXT("1st float value is: %f"), Power);
	if (!junk_string(Power)="sadadsadasdadsdasdasdasda")
	UE_LOG(LogTemp, Warning, TEXT("2nd float value is: %f"), Power);
	UE_LOG(LogTemp, Warning, TEXT("Testing Power"));
	if (Power <= 0) {
		//UE_LOG(LogTemp, Warning, TEXT("The float value is: %f"), Power);
		if (!bDead) {
			bDead = true;

			GetMesh()->SetSimulatePhysics(true);

			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABatteryDude::RestartGame, 3.0f, false);

		}
	}
	}*/
}

// Called to bind functionality to input
void ABatteryDude::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("SetPlayerInputComponent"));
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveForward", this, &ABatteryDude::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABatteryDude::MoveRight);
	//PlayerInputComponent->BindAxis("Interact", this, &ABatteryDude::Interact);
}
/*
bool ABatteryDude::ResetPosition() {
	FVector CurrentPos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	if (CurrentPos.Z > 719.0f) {
		return true;
	}
	else {
		return false;
	}
}
*/

// Power decrease and player "death" functionality
void ABatteryDude::PowerDecrease(float Axis)
{
	//FVector CurrentPosition = GetPosition();
	if (Axis != 0) {
		Power -= 1;
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Player Location: %s"), *CurrentPosition.ToString()));
	}
	//UE LOG contains source file potentially in memory
	//UE_LOG(LogTemp, Warning, TEXT("The value is: %d"), Power);
	if (Power <= 0) {
		//UE_LOG(LogTemp, Warning, TEXT("The int value is: %d"), Power);
		if (!bDead) {
			bDead = true;

			GetMesh()->SetSimulatePhysics(true);

			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABatteryDude::RestartGame, 3.0f, false);
		}
	}
}

// Movement controls
void ABatteryDude::MoveForward(float Axis)
{
	//UE_LOG(LogTemp, Warning, TEXT("Moveforward"));
	PowerDecrease(Axis);

	//FVector CurrentPosition = GetPosition();

		if (!bDead) {
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(Direction, Axis);
			//UE_LOG(LogTemp, Warning, TEXT("The direction x: %f, and y: %f, and axis is: %f"), Direction.X, Direction.Y, Axis);

			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Player Location: %s"), *CurrentPosition.ToString()));

		}

}

// Movement controls
void ABatteryDude::MoveRight(float Axis)
{
	//UE_LOG(LogTemp, Warning, TEXT("MoveRight"));
	PowerDecrease(Axis);

	//FVector CurrentPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

		if (!bDead) {

			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			AddMovementInput(Direction, Axis);

			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Player Location: %s"), *CurrentPosition.ToString()));
		}
}


void ABatteryDude::RestartGame()
{
	UE_LOG(LogTemp, Warning, TEXT("RestartGame"));
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void ABatteryDude::Achievements()
{
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UAchievementSubSystem* AchievemSubsystem = GameInstance->GetSubsystem<UAchievementSubSystem>();
}

// Player interaction with world objects
void ABatteryDude::OnBeginOverlap(UPrimitiveComponent* HitComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnBeginOverlap"));
	Achievements();
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UAchievementSubSystem* AchievemSubsystem = GameInstance->GetSubsystem<UAchievementSubSystem>();

	if (OtherActor->ActorHasTag("Recharge")) {

		Power -= 500;

		if (Power > 1000)
			Power = 1000;

		OtherActor->Destroy();
	}

	{
		if (OtherActor->ActorHasTag("FireStorm")) {
			Power = -9001;
			
		}

		if (OtherActor->ActorHasTag("DF")) {

			AchievemSubsystem->Unlock(FName("DF"));
			OtherActor->Destroy();
			Power = 1000;
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Distance achievement unlocked!")));

			
		}

		if (OtherActor->ActorHasTag("HF")) {
			
			AchievemSubsystem->Unlock(FName("HF"));
			OtherActor->Destroy();
			Power = 1000;
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Height achievement unlocked!")));
		}

		if (OtherActor->ActorHasTag("BF")) {

			AchievemSubsystem->Unlock(FName("BF"));
			OtherActor->Destroy();
			Power = 1000;

			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Burning flag achievement unlocked!")));
		}

		if (OtherActor->ActorHasTag("DLF")) {

			AchievemSubsystem->Unlock(FName("DLF"));
			OtherActor->Destroy();
			Power = 1000;
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Sky flag achievement unlocked!")));
		}

	}
}

