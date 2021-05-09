#ifndef CK2_WONDER_H
#define CK2_WONDER_H
#include "Parser.h"
#include <set>

namespace CK2
{
class Wonder: commonItems::parser
{
  public:
	Wonder() = default;
	explicit Wonder(std::istream& theStream);

	void fillConstructionHistory(std::istream& theStream);

	[[nodiscard]] const auto& getType() const { return type; }
	[[nodiscard]] const auto& getName() const { return name; }
	[[nodiscard]] const auto& getDesc() const { return desc; }
	[[nodiscard]] auto getWonderID() const { return wonderID; }
	[[nodiscard]] auto getStage() const { return stage; }
	[[nodiscard]] auto getProvinceID() const { return provinceID; }
	[[nodiscard]] auto getBuilder() const { return builder; }
	[[nodiscard]] auto getDate() const { return date; }
	[[nodiscard]] auto isActive() const { return active; }
	[[nodiscard]] auto isTransferrable() const { return active && stage == 3; }
	[[nodiscard]] auto getTrueDate() { return trueDate; }
	[[nodiscard]] auto getBuilderCulture() { return builderCulture; }
	[[nodiscard]] auto getBuilderReligion() { return builderReligion; }
	[[nodiscard]] auto getUpgrades() { return upgrades; }
	[[nodiscard]] auto isSpent() const { return spent; }
	void addUpgrade(std::string mod){ upgrades.emplace(mod); }
	void setWonderID(short mod) { wonderID = mod; }
	void setTrueDate(std::string mod) { trueDate = mod; }
	void setTrueDate(int mod);
	void setBuilderCulture(std::string culture) { builderCulture = culture; }
	void setBuilderReligion(std::string religion) { builderReligion = religion; }
	void setSpent() { spent = true; }

  private:
	void registerKeys();

	short wonderID;
	short stage = 0;
	int provinceID = 0;
	long long builder = 0;
	int date = 0;
	bool active = false;
	bool spent = false;
	std::string type;
	std::string name;
	std::string desc;
	std::string trueDate = "0";
	std::string builderCulture;
	std::string builderReligion;

	std::set<std::string> upgrades;
};
} // namespace CK2

#endif // CK2_WONDER_H
