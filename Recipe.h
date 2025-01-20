#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

class Recipe {
public:
    Recipe(const std::string& name, const std::string& category, 
           const std::vector<std::string>& ingredients, int rating = 0, 
           const std::vector<std::string>& comments = {});

    std::string serialize() const;
    
    void setRating(int rating);
    void addComment(const std::string& comment);

    // Getter methods for private members
    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    std::vector<std::string> getIngredients() const { return ingredients; }
    int getRating() const { return rating; }
    std::vector<std::string> getComments() const { return comments; }

private:
    std::string name;
    std::string category;
    std::vector<std::string> ingredients;
    int rating;
    std::vector<std::string> comments;
};

#endif // RECIPE_H
