// yes


#include "GameDataFloat.h"

float UGameDataFloat::GetFloatValue(FName ValueName)
{

	if (FloatData.Contains(ValueName)) {
		return FloatData[ValueName];
	}
	else {
		return 0;
	}

	return FloatData[ValueName];

}