#include "Barony.h"
#include "Log.h"
#include "ParserHelpers.h"
#include "CommonRegexes.h"

CK2::Barony::Barony(std::istream& theStream, const std::string& baronyName): name(baronyName)
{
	registerKeys();
	parseStream(theStream);
	clearRegisteredKeywords();
}

void CK2::Barony::registerKeys()
{
	registerKeyword("type", [this](const std::string& unused, std::istream& theStream) {
		const commonItems::singleString typeStr(theStream);
		type = typeStr.getString();
	});
	registerRegex("(ca|ct|tp|no|tb)_[A-Za-z0-9_-]+", [this](const std::string& building, std::istream& theStream) {
		const commonItems::singleString buildingStr(theStream);
		if (buildingStr.getString() == "yes")
			buildings.insert(building);
	});
	registerRegex(commonItems::catchallRegex, commonItems::ignoreItem);
}
