#ifndef RECIPEMANAGER_H
#define RECIPEMANAGER_H

#include <vector>
#include <string>
#include "Recipe.h" // Include the header file where Recipe is defined

class RecipeManager {
public:
    void addRecipe(const Recipe& recipe);
    std::vector<Recipe> searchByIngredient(const std::string& ingredient) const;
    std::vector<Recipe> searchByName(const std::string& name) const;
    std::vector<Recipe> listRecipesByCategory(const std::string& category) const;
    std::vector<Recipe> searchByMultipleIngredients(const std::vector<std::string>& ingredients) const;
    std::vector<Recipe> filterByRating(int rating) const;

private:
    std::vector<Recipe> recipes;
};

#endif // RECIPEMANAGER_H
