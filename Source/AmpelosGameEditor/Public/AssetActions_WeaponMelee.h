// yes

#pragma once

#include "CoreMinimal.h"
#include <Ampelos/AmpelosWeaponMeleeDefinition.h>
#include "AssetTypeCategories.h"
#include "AssetTypeActions_Base.h"

/**
 * 
 */
class AMPELOSGAMEEDITOR_API AssetActions_WeaponMelee : public FAssetTypeActions_Base
{
public:
	
	AssetActions_WeaponMelee(EAssetTypeCategories::Type InAssetCategory);

	// IAssetTypeActions interface
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	// End of IAssetTypeActions interface

private:

	EAssetTypeCategories::Type WeaponMeleeCategory;

};
