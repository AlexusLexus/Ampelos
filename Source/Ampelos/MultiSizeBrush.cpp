// yes


#include "MultiSizeBrush.h"

UMultiSizeBrush::UMultiSizeBrush()
{
	if (AssetGuid == EmptyGuid) 
	{
		AssetGuid.NewGuid();
	}

}

UTexture2D * UMultiSizeBrush::GetBrush(EMultiSizeBrushTypes BrushType)
{
	if (MultiSizeBrushData.Contains(BrushType))
	{
		return MultiSizeBrushData[BrushType];
	}
	else
	{
		return nullptr;
	}

	return MultiSizeBrushData[BrushType];
}

/*
TArray<UTexture2D*> UMultiSizeBrush::GetArrayOfBrushes()
{
	return MultiSizeBrushData.GenerateValueArray();
}
*/
