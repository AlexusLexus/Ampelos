// yes


#include "GameDataText.h"

TMap<FString, FText> UGameDataText::GetTableEntry(FName EntryName)
{
	TMap<FString, FText> TempMap;

	if (TextData.Contains(EntryName))
	{
		return TextData[EntryName].Entry;
	}
	else {
		return TempMap;
	}

	return TextData[EntryName].Entry;

}

FText UGameDataText::GetTableEntryByCulture(FName EntryName, FString CultureName)
{

	if (TextData.Contains(EntryName))
	{
		if (TextData[EntryName].Entry.Contains(CultureName))
		{
			return TextData[EntryName].Entry[CultureName];
		}
		else
		{
			return FText::FromString(TEXT("ERROR! There is no string for provided culture."));
		}
	}
	else
	{
		return FText::FromString(TEXT("ERROR! There is no string for provided Key!"));
	}

	return TextData[EntryName].Entry[CultureName];

}
