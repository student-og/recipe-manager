#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <vector>
#include <string>

class Recipe {
public:
    Recipe(const std::string& name, const std::string& category, const std::vector<std::string>& ingredients);

    void setName(const std::string& newName);
    void setCategory(const std::string& newCategory);
    void setIngredients(const std::vector<std::string>& newIngredients);
    void setRating(int newRating);
    void addComment(const std::string& comment);

    std::string getName() const;
    std::string getCategory() const;
    std::vector<std::string> getIngredients() const;
    int getRating() const;
    std::vector<std::string> getComments() const;

    void print() const;

private:
    std::string name;
    std::string category;
    std::vector<std::string> ingredients;
    int rating;
    std::vector<std::string> comments;
};

#endif // RECIPE_H

