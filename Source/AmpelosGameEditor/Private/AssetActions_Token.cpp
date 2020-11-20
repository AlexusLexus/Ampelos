// yes


#include "AssetActions_Token.h"

AssetActions_Token::AssetActions_Token(EAssetTypeCategories::Type InAssetCategory) : TokenCategory(InAssetCategory)
{
}

FText AssetActions_Token::GetName() const
{
	return FText::FromString(TEXT("Token"));
}

FColor AssetActions_Token::GetTypeColor() const
{
	return FColor(0, 153, 153);
}

UClass* AssetActions_Token::GetSupportedClass() const
{
	return UAmpelosTokenType::StaticClass();
}

uint32 AssetActions_Token::GetCategories()
{
	return TokenCategory;
}
