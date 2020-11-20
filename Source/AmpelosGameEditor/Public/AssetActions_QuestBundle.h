// yes

#pragma once

#include "CoreMinimal.h"
#include <Ampelos/AmpelosQuestBundleDefinition.h>
#include "AssetTypeCategories.h"
#include "AssetTypeActions_Base.h"

/**
 * 
 */
class AMPELOSGAMEEDITOR_API AssetActions_QuestBundle : public FAssetTypeActions_Base
{

public:

	AssetActions_QuestBundle(EAssetTypeCategories::Type InAssetCategory);

	// IAssetTypeActions interface
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	// End of IAssetTypeActions interface

private:

	EAssetTypeCategories::Type QuestBundleCategory;

};
