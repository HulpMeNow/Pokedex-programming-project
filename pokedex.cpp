#include "pokedex.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>


using namespace std;

Pokedex::Pokedex(unsigned maxSize)
    : maxSize(maxSize), currentSize(0) {
    pokemonNames = new std::string[maxSize];
}

Pokedex::~Pokedex() {
    delete[] pokemonNames;
}

int Pokedex::getMaxSize()const{
    return maxSize;
}

int Pokedex::getCurrentSize()const{
    return currentSize;
}

std::string Pokedex::getPokemonName(unsigned index)const{
    if (index >= currentSize || index < 0) { // or gate
        cout << "Index out of range. Returning \"no pokemon\"." << "\n";
        return "no pokemon";
    }
    return (std::string) pokemonNames[index]; // huh? is this safe? works with the *

}

string Pokedex::toLower(const std::string& str) {
    string lowerString = str;
    for (char& c : lowerString) {
        c = tolower(c);
    }
    return lowerString;
}


void Pokedex::addPokemon(const std::string& name) {
    // Normalize input name to lowercase
    string normalizedName = toLower(name);

    // checking duplicates
    for (int i = 0; i < currentSize; ++i) {
        if (toLower(pokemonNames[i]) == normalizedName) {
            cout << "This Pokémon already exists in the Pokedex. No duplicates allowed." << "\n";
            return;
        }
    }

    //array full
    if (currentSize == maxSize) {
        cout << "Array is full, delete a Pokémon first." << "\n";
        return;
    }

    // ensureing the adding pokemon is in correct order
    if (currentSize == 0) {
        pokemonNames[0] = name;
    } else {
        int position = currentSize;
        for (int i = 0; i < currentSize; ++i) {
            if (toLower(name) < toLower(pokemonNames[i])) {
                position = i;
                break;
            }
        }
        shiftToRight(position);
        pokemonNames[position] = name;
    }
    cout << "Sucessfully added " << name << " to the Pokedex." << endl;
    currentSize++;
}
/* OBSOLETE addpokemon method. fails to check duplicate
void Pokedex::addPokemon(const std::string& name) {
    if (currentSize == maxSize) {
        cout << "Array is full, delete a pokemon first." << "\n";
        return;
    }
    if (currentSize == 0) {
        pokemonNames[0] = name;
    } else {
        int position = currentSize;
        for (int i = 0; i < currentSize; ++i) {
            if (name < pokemonNames[i]) {
                position = i;
                break;
            }
        }
        shiftToRight(position);
        pokemonNames[position] = name;
    }
    currentSize++;
}
*/ 

void Pokedex::removePokemon(unsigned index){
    if (index > currentSize || index < 0) { // or gate
        cout << "Index out of range. Nothing has been done." << "\n";
        return;
    }
    cout << "Succesfully deleted: " << pokemonNames[index] << endl;
    shiftToLeft(index);
    pokemonNames[currentSize - 1] = ""; // can do currentSize--
    
    currentSize--;
}

void Pokedex::shiftToRight(unsigned index){
    if (index > currentSize || index < 0) {
        cout << "Invalid index, no action is taken" << "\n";
        return;
    }

    for (int i = currentSize; i > index; --i) {
        pokemonNames[i] = pokemonNames[i - 1];
    }
}

void Pokedex::shiftToLeft(unsigned index){
    if (index >= currentSize || index < 0) {
        cout << "Invalid index, no action is taken." << "\n";
        return;
    }

    for (int i = index; i < currentSize - 1; ++i) { 
        pokemonNames[i] = pokemonNames[i + 1];
    }
}

string Pokedex::toString(void) {
    string toReturn = "pokemon names: \n";
    if (currentSize == 0) {
        return "Oh! looks like the Pokedex is empty. Try adding a Pokémon to it.";
    }
    for(int i = 0; i < currentSize; i++) {
        toReturn += pokemonNames[i] + "\n";
    }
    return toReturn;
}
