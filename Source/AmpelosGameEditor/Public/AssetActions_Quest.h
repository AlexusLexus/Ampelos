// yes

#pragma once

#include "CoreMinimal.h"
#include <Ampelos/AmpelosQuestItemDefinition.h>
#include "AssetTypeCategories.h"
#include "AssetTypeActions_Base.h"

/**
 * 
 */
class AMPELOSGAMEEDITOR_API AssetActions_Quest : public FAssetTypeActions_Base
{
public:
	
	AssetActions_Quest(EAssetTypeCategories::Type InAssetCategory);

	// IAssetTypeActions interface
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	// End of IAssetTypeActions interface

private:

	EAssetTypeCategories::Type QuestCategory;

};
