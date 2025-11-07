#ifndef POKEDEX_H
#define POKEDEX_H
//Welcome to Soraj's program

#include <string>

class Pokedex {
private:
    std::string* pokemonNames; // why does * save the whole thing??
    int maxSize;
    int currentSize; 

    // these helper methods do not account for the duplicate of a particular string.
    // this means the function calling these must account for that.
    void shiftToLeft(unsigned index); 
    void shiftToRight(unsigned index); 
    // this makes all the letters lowercase to compare names
    std::string toLower(const std::string& str);

public:
    Pokedex(unsigned maxSize);
    ~Pokedex();

    int getMaxSize() const;
    int getCurrentSize() const;
    std::string getPokemonName(unsigned index) const;
    void addPokemon(const std::string& name);
    void removePokemon(unsigned index);
    std::string toString(void);
};

#endif
