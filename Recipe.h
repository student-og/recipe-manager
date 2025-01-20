#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

class Recipe {
public:
    Recipe(const std::string& name, const std::string& category, 
           const std::vector<std::string>& ingredients, int rating, 
           const std::vector<std::string>& comments);

    std::string serialize() const;
    
    // Add the necessary methods
    void setRating(int rating);
    void addComment(const std::string& comment);

private:
    std::string name;
    std::string category;
    std::vector<std::string> ingredients;
    int rating;
    std::vector<std::string> comments;
};

#endif // RECIPE_H
