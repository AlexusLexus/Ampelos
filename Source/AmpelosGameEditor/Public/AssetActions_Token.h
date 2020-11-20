// yes

#pragma once

#include "CoreMinimal.h"
#include <Ampelos/AmpelosTokenType.h>
#include "AssetTypeCategories.h"
#include "AssetTypeActions_Base.h"

/**
 * 
 */
class AMPELOSGAMEEDITOR_API AssetActions_Token : public FAssetTypeActions_Base
{
public:
	
	AssetActions_Token(EAssetTypeCategories::Type InAssetCategory);

	// IAssetTypeActions interface
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	// End of IAssetTypeActions interface

private:

	EAssetTypeCategories::Type TokenCategory;

};
