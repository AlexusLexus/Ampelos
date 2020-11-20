// yes


#include "AmpelosCharacter.h"
#include "Components/SceneComponent.h"

// Sets default values
AAmpelosCharacter::AAmpelosCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create and attach all character parts components

	SK_Base = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Base"));
	RootComponent = SK_Base;

	SK_Torso = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Torso"));
	SK_Torso->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);
	SK_Head = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Head"));
	SK_Head->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);
	SK_Vest = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Vest"));
	SK_Vest->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);
	SK_Hair = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Hair"));
	SK_Hair->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);
	SK_Hat = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Hat"));
	SK_Hat->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);
	SK_Mask = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Mask"));
	SK_Mask->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);
	SK_Acc_01 = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Acc_01"));
	SK_Acc_01->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);
	SK_Acc_02 = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Acc_02"));
	SK_Acc_02->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);
	SK_Acc_03 = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Acc_03"));
	SK_Acc_03->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);
	SK_Backpack = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sk_Backpack"));
	SK_Backpack->AttachToComponent(SK_Base, FAttachmentTransformRules::KeepRelativeTransform);

	//Foorstep audio
	S_Footsteps = CreateDefaultSubobject<UAudioComponent>(TEXT("Foorsteps Audio"));
	S_Footsteps->AttachToComponent(SK_Torso, FAttachmentTransformRules::KeepRelativeTransform);

	//Voice thingie
	S_Voice = CreateDefaultSubobject<UAudioComponent>(TEXT("Voice"));
	S_Voice->AttachToComponent(SK_Head, FAttachmentTransformRules::KeepRelativeTransform);

	if (HeroType != nullptr)
	{
		if (HeroType->HeroCosmeticOutfitDefinition != nullptr)
		{
			Hero_CID = HeroType->HeroCosmeticOutfitDefinition;
			SetCharacterPartsFromCID();
			ReloadCharacterParts();
		}
	}

}

void AAmpelosCharacter::ReloadCharacterParts()
{

	if (CharacterParts.Body != nullptr)
	{
		SK_Torso->SetSkeletalMesh(CharacterParts.Body->CharacterSkeletalMesh, true);
	}

	if (CharacterParts.Head != nullptr)
	{
		SK_Head->SetSkeletalMesh(CharacterParts.Head->CharacterSkeletalMesh, true);
	}

	if (CharacterParts.Hair != nullptr)
	{
		SK_Hair->SetSkeletalMesh(CharacterParts.Hair->CharacterSkeletalMesh, true);
	}

	if (CharacterParts.Hat != nullptr)
	{
		SK_Hat->SetSkeletalMesh(CharacterParts.Hat->CharacterSkeletalMesh, true);
	}

	if (CharacterParts.Mask != nullptr)
	{
		SK_Mask->SetSkeletalMesh(CharacterParts.Mask->CharacterSkeletalMesh, true);
	}

	if (CharacterParts.Vest != nullptr)
	{
		SK_Vest->SetSkeletalMesh(CharacterParts.Vest->CharacterSkeletalMesh, true);
	}

	if (CharacterParts.Backpack != nullptr)
	{
		SK_Backpack->SetSkeletalMesh(CharacterParts.Backpack->CharacterSkeletalMesh, true);
	}

	if (CharacterParts.Acc_01 != nullptr)
	{
		SK_Acc_01->SetSkeletalMesh(CharacterParts.Acc_01->CharacterSkeletalMesh, true);
	}

	if (CharacterParts.Acc_02 != nullptr)
	{
		SK_Acc_02->SetSkeletalMesh(CharacterParts.Acc_02->CharacterSkeletalMesh, true);
	}

	if (CharacterParts.Acc_03 != nullptr)
	{
		SK_Acc_03->SetSkeletalMesh(CharacterParts.Acc_03->CharacterSkeletalMesh, true);
	}

}

void AAmpelosCharacter::SetAndReloadCIDParts()
{

}

void AAmpelosCharacter::SetCharacterPartsFromCID()
{
	CharacterParts.Head = Hero_CID->CP_Head;
	CharacterParts.Body = Hero_CID->CP_Body;
	CharacterParts.Backpack = Hero_CID->CP_Backpack;
	CharacterParts.Vest = Hero_CID->CP_Vest;
	CharacterParts.Hair = Hero_CID->CP_Hair;
	CharacterParts.Hat = Hero_CID->CP_Hat;
	CharacterParts.Mask = Hero_CID->CP_Mask;
	CharacterParts.Acc_01 = Hero_CID->CP_Acc_01;
	CharacterParts.Acc_02 = Hero_CID->CP_Acc_02;
	CharacterParts.Acc_03 = Hero_CID->CP_Acc_03;
}

// Called when the game starts or when spawned
void AAmpelosCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmpelosCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAmpelosCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

