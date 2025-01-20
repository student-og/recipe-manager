#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include <string>
#include <vector>

class Recipe {
public:
    Recipe(const std::string& name, const std::string& category, 
           const std::vector<std::string>& ingredients, int rating, 
           const std::vector<std::string>& comments);

    // Other member functions and variables
};

class RecipeManager {
public:
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Recipe> recipes;
};

#endif // RECIPE_MANAGER_H
