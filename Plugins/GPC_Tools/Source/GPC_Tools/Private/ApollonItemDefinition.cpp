// yes


#include "ApollonItemDefinition.h"

void UApollonItemDefinition::WriteDebugInfo(UApollonItemDefinition* Input)
{
	FString tName = DisplayName.ToString();

	UE_LOG(LogTemp, Warning, TEXT("Debug Info Abount '%s': ID=%s1, Analytics=%s2"), *tName, *ItemID, *AnalysticsName);
}