// yes

#pragma once

#include "CoreMinimal.h"
#include <Timecycle.h>
#include "AssetTypeCategories.h"
#include "AssetTypeActions_Base.h"

/**
 * 
 */
class GPC_TOOLS_API AssetActions_Timecycle : public FAssetTypeActions_Base
{
	public:
    AssetActions_Timecycle(EAssetTypeCategories::Type InAssetCategory);

    // IAssetTypeActions interface
    virtual FText GetName() const override;
    virtual FColor GetTypeColor() const override;
    virtual UClass* GetSupportedClass() const override;
    virtual uint32 GetCategories() override;
    // End of IAssetTypeActions interface

private:
    EAssetTypeCategories::Type TimecycleCategory;

};
