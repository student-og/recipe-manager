#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include "Recipe.h"
#include <string>
#include <vector>

class RecipeManager {
public:
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    // Add the necessary methods
    void addRecipe(const Recipe& recipe);
    void deleteRecipe(const std::string& name);
    std::vector<Recipe> searchByIngredient(const std::string& ingredient) const;
    std::vector<Recipe> searchByName(const std::string& name) const;
    std::vector<Recipe> listRecipesByCategory(const std::string& category) const;
    std::vector<Recipe> searchByMultipleIngredients(const std::vector<std::string>& ingredients) const;
    std::vector<Recipe> filterByRating(int rating) const;

private:
    std::vector<Recipe> recipes;
};

#endif // RECIPE_MANAGER_H
