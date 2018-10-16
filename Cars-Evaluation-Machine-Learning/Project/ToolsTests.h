#pragma once
#include "Tools.h"
#include <assert.h>
class ToolsTests
{
private:
	Tools tools;
public:
	ToolsTests();
	void tokenizeTests();
	void stringToIntegerTests();
	void integerToStringTests();
	void initialFeatureIndexTests();
	void getFeaturePropertyTests();
	void trueValuesTests();
	void shuffleVectorTests();
};

