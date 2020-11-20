// yes

#pragma once

#include "CoreMinimal.h"
#include "K2Node.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "K2Node_QuestUpdate.generated.h"

class FBlueprintActionDatabaseRegistrar;

/**
 * 
 */
UCLASS()
class AMPELOSK2NODES_API UK2Node_QuestUpdate : public UK2Node
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
		FText QuestUpdate_Name = FText::FromString(TEXT("Quest Update"));

	FText QuestUpdate_Desc = FText::FromString(TEXT("Use this node to drive quest logic."));
	FText QuestUpdate_Category = FText::FromString(TEXT("AMPELOS|Ampelos Quest"));

	//Create our pins
	virtual void AllocateDefaultPins() override;
	//Implement our own node title
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	//Implement our own node tooltip text
	virtual FText GetTooltipText() const override;

	// Implement our own node category
	virtual FText GetMenuCategory() const override;
	//This method works like a bridge and connects our K2Node to the actual Blueprint Library method. This is where the actual logic happens.
	virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;

	//virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;

	//
	virtual FLinearColor GetNodeTitleColor() const override;

	virtual UClass* GetPinClass();
	
};
