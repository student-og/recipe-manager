#include "Recipe.h"
#include <sstream>

Recipe::Recipe(const std::string& name, const std::string& category, 
               const std::vector<std::string>& ingredients, int rating, 
               const std::vector<std::string>& comments)
    : name(name), category(category), ingredients(ingredients), rating(rating), comments(comments) {}

std::string Recipe::serialize() const {
    std::ostringstream oss;
    oss << name << "\n" << category << "\n";
    for (const auto& ingredient : ingredients) {
        oss << ingredient << "\n";
    }
    oss << "---\n";
    for (const auto& comment : comments) {
        oss << comment << "\n";
    }
    oss << "---\n";
    return oss.str();
}
