#ifndef CK2_PROVINCES_H
#define CK2_PROVINCES_H
#include "Parser.h"
#include "../Characters/Characters.h"
#include "../Characters/Character.h"

namespace CK2
{
class Province;
class Wonders;
class Provinces: commonItems::parser
{
  public:
	Provinces() = default;
	explicit Provinces(std::istream& theStream);
	[[nodiscard]] const auto& getProvinces() const { return provinces; }
	

	[[nodiscard]] void linkPrimarySettlements();
	[[nodiscard]] void linkWonders(const Wonders& wonders);														  // No Leviathan DLC
	const std::set<std::string>& linkMonuments(const Wonders& wonders, const Characters& characters); // Leviathan DLC

  private:
	void registerKeys();

	std::map<int, std::shared_ptr<Province>> provinces;
};
} // namespace CK2

#endif // CK2_PROVINCES_H
