#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include "Recipe.h"
#include <string>
#include <vector>

class RecipeManager {
public:
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Recipe> recipes;
};

#endif // RECIPE_MANAGER_H
