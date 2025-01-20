#include "Recipe.h"

Recipe::Recipe(const std::string& name, const std::string& category, const std::vector<std::string>& ingredients)
    : name(name), category(category), ingredients(ingredients), rating(0) {}

void Recipe::setName(const std::string& newName) { name = newName; }
void Recipe::setCategory(const std::string& newCategory) { category = newCategory; }
void Recipe::setIngredients(const std::vector<std::string>& newIngredients) { ingredients = newIngredients; }
void Recipe::setRating(int newRating) { rating = newRating; }
void Recipe::addComment(const std::string& comment) { comments.push_back(comment); }

std::string Recipe::getName() const { return name; }
std::string Recipe::getCategory() const { return category; }
std::vector<std::string> Recipe::getIngredients() const { return ingredients; }
int Recipe::getRating() const { return rating; }
std::vector<std::string> Recipe::getComments() const { return comments; }

void Recipe::print() const {
    std::cout << "Recipe: " << name << "\nCategory: " << category << "\nIngredients:\n";
    for (const auto& ingredient : ingredients) {
        std::cout << "- " << ingredient << "\n";
    }
    std::cout << "Rating: " << rating << "\nComments:\n";
    for (const auto& comment : comments) {
        std::cout << "- " << comment << "\n";
    }
}

