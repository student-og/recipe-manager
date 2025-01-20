#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include "Recipe.h"
#include <vector>
#include <string>

class RecipeManager {
public:
    void addRecipe(const Recipe& recipe);
    void editRecipe(const std::string& name, const Recipe& newRecipe);
    void deleteRecipe(const std::string& name);
    void searchByIngredient(const std::string& ingredient) const;
    void searchByName(const std::string& name) const;
    void listRecipesByCategory(const std::string& category) const;
    void searchByMultipleIngredients(const std::vector<std::string>& ingredients) const;
    void filterByRating(int rating) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Recipe> recipes;
};

#endif // RECIPE_MANAGER_H

