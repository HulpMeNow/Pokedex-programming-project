#include "pokedex.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// prototypes
// the next three return Pass or fail to the terminal
bool testAddingPokemon();
bool testRemovingPokemon();
bool testMiscellaneousPokemon();

// these three test methods test all the meethods and show what is happening instead of
// passing or failing
// these have been made by asking chatgpt to make pass fail type tests to check
// my methods. the rest of the code in the files are written by me.
void testAddPokemon();
void testRemovePokemon();
void testMiscellaneous();

// to get user input, also does check to ensure the input is acceptable for the situation
int userIntegerInput();
int userLargeIntegerInput();
string userStringInput();
//int displayOptions();

int main() {
    // uncomment below methods to run tests. These are detailed tests 
    //testAddPokemon();
    //testRemovePokemon();
    //testMiscellaneous();

    // bellow are the pass fail type tests, comment out multiline comment to see.
    /*
    bool allPassed = true;

    if (!testAddingPokemon()) {
        allPassed = false;
    }
    if (!testRemovingPokemon()) {
        allPassed = false;
    }
    if (!testMiscellaneousPokemon()) {
        allPassed = false;
    }

    if (allPassed) {
        cout << "All tests PASSED!" << endl;
    } else {
        cout << "Some tests FAILED. Check the output for details." << endl;
    }

    */

   ///* you can uncomment this at this point and ending to disable the user interface
   // and just have the tests printed.
  cout << "Welcome Trainer to your Pokedex. "<< endl;
    cout << "How large would you like your pokedex to be? (max 1025)." << endl;
    cout << "Entered numbers round down to the nearest whole positive integer. \n" << endl;
  int tempNumber = userLargeIntegerInput();
  Pokedex pokedex = Pokedex(tempNumber);
    while (true) {

        cout << "Please select an option: \n" << endl;
        cout << "1. Add a Pokemon" << endl;
        cout << "2. Remove a Pokemon at given index" << endl;
        cout << "3. List all Pokemon" << endl;
        cout << "4. Find Pokemon at given index" << endl;
        cout << "5. Get Pokdex maximum size" << endl;
        cout << "6. Get Pokdex current size" << endl;
        cout << "7. See options again" << endl;
        cout << "8. Quit \n" << endl;

        int answer = userIntegerInput();

        if (answer == 1) {
            cout << "Enter the pokemon you would like to add: " << endl;
            string tempName = userStringInput();
            pokedex.addPokemon(tempName);
        } else if (answer == 2) {
            cout << "Enter index of pokemon to Delete: " << endl;
          int tempAnswer = userLargeIntegerInput();
            pokedex.removePokemon(tempAnswer);
        } else if (answer == 3) {
            cout << pokedex.toString() << endl;
        } else if (answer == 4) {
            cout << "Enter the index of the pokemon you would like to find: " << endl;
            int answer = userLargeIntegerInput();
            cout << "Pokemon at index: " << answer << "is " << pokedex.getPokemonName(answer) << endl; // get the index here :)
        } else if (answer == 5) {
            cout << "The maximum size of the Pokedex is " << pokedex.getMaxSize() << endl;
        } else if (answer == 6) {
            cout << "The current size of the Pokdex is " << pokedex.getCurrentSize() << endl;
        } else if (answer == 7) {
            cout << "Welcome trainer to your Pokedex. Please select an option:" << endl;
            cout << "1. Add a Pokemon" << endl;
            cout << "2. Remove a Pokemon" << endl;
            cout << "3. List all Pokemon" << endl;
            cout << "4. Find Pokemon at index" << endl;
            cout << "5. Get Pokdex maximum size" << endl;
            cout << "6. Get Pokdex current size" << endl;
            cout << "7. See options again" << endl;
            cout << "8. Quit" << endl;
        } else if (answer == 8) {
            cout << "Thank you for using your Pokedex. Goodbye!" << endl;
            return 0;
        }
        else {
            cout << "Congrats, you have broken something <3 restart now :)" << endl;
            return 0;
        }



    }
    // this is the end of the code for user interface
    //*/ 
    return 0;

}

string userStringInput(){
    string input;
    while (true) {
        cout << "Enter a Pokemon name: " << endl;
        cin >> input;
        for (int i = 0; i < input.length(); i++) {
          if (isdigit(input[i])){
            cout << "Enter a pokemon name. No numbers allowed!." << endl;
            break;
          } else if (isalnum(input[i])) {
            return input;
          } else {
            cout << "Enter a pokemon name. No special characters allowed!." << endl;
            break; // allow this?
          }
    }
  }
}

// getting the user input and checking if it is valid, ie it is an int 1-8
int userIntegerInput(){
    int number; 
    while (true) {
        cout << "Enter a choice (1-8):";
        cin >> number;

        // handling failing cases
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << endl;
        } else if (number < 0 || number >= 9){
            cout << "Input out of range. Please enter a number (int) between 1 and 8." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return number; 
        }
    }
}
int userLargeIntegerInput(){
    int number; 
    while (true) {
        cout << "Enter number: ";
        cin >> number;

        // handling failing cases
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << endl;
        } else if (number < 0 || number > 1025){
            cout << "Input out of range. Please enter a number (int) between 1 and 1025." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return number; 
        }
    }
}
/*
int displayOptions(){
    cout << "Welcome trainer to your Pokedex. Please select an option:" << endl;
    cout << "1. Add a Pokemon" << endl;
    cout << "2. Remove a Pokemon" << endl;
    cout << "3. List all Pokemon" << endl;
    cout << "4. Find Pokemon at index" << endl;
    cout << "5. Quit" << endl;


    return 0;
}*/
bool testAddingPokemon() {
    cout << "Running test: Add Pokemon" << endl;
    Pokedex pokedex(5);

    // Test adding Pokémon
    pokedex.addPokemon("Pikachu");
    pokedex.addPokemon("Zubat");
    pokedex.addPokemon("Raichu");

    string expected = "pokemon names: \nPikachu\nRaichu\nZubat\n"; // Match the format from toString
    if (pokedex.toString() == expected) {
        cout << "Adding Pokémon in alphabetical order: PASSED" << endl;
        return true;
    } else {
        cout << "Adding Pokémon in alphabetical order: FAILED" << endl;
        cout << "Expected:\n" << expected << "Actual:\n" << pokedex.toString() << endl;
        return false;
    }
}

bool testRemovingPokemon() {
    cout << "Running test: Remove Pokemon" << endl;
    Pokedex pokedex(5);

    // Setup initial list
    pokedex.addPokemon("Charmander");
    pokedex.addPokemon("Squirtle");
    pokedex.addPokemon("Eevee");

    // Remove Pokémon at index 1
    pokedex.removePokemon(1);

    string expected = "pokemon names: \nCharmander\nSquirtle\n"; // Match the format
    if (pokedex.toString() == expected) {
        cout << "Removing Pokémon at index 1: PASSED" << endl;
        return true;
    } else {
        cout << "Removing Pokémon at index 1: FAILED" << endl;
        cout << "Expected:\n" << expected << "Actual:\n" << pokedex.toString() << endl;
        return false;
    }
}

bool testMiscellaneousPokemon() {
    cout << "Running test: Miscellaneous" << endl;
    Pokedex pokedex(4);

    // Test adding Pokémon
    pokedex.addPokemon("Pikachu");
    pokedex.addPokemon("Metagross");
    pokedex.addPokemon("Dragonite");

    string expected = "pokemon names: \nDragonite\nMetagross\nPikachu\n"; // Match the format
    if (pokedex.toString() == expected) {
        cout << "Checking Pokémon list: PASSED" << endl;
        return true;
    } else {
        cout << "Checking Pokémon list: FAILED" << endl;
        cout << "Expected:\n" << expected << "Actual:\n" << pokedex.toString() << endl;
        return false;
    }
}

void testAddPokemon() {
    cout << "creating pokedex of size 5" << endl;
    Pokedex pokedex(5);
    cout << "max size is: " << pokedex.getMaxSize() << endl;
    cout << "current size is: " << pokedex.getCurrentSize() << endl;

    cout << "Adding Pikachu" << endl;
    pokedex.addPokemon("Pikachu");
    cout << "current size is: " << pokedex.getCurrentSize() << endl;
    cout << "checking: " << pokedex.toString() << endl;
    cout << "Adding Zubat" << endl;
    pokedex.addPokemon("Zubat");
    cout << "current size is: " << pokedex.getCurrentSize() << endl;
    cout << "checking: " << pokedex.toString() << endl;
    cout << "Adding Charazard" << endl;
    cout << "current size is: " << pokedex.getCurrentSize() << endl;
    pokedex.addPokemon("Charazard");
    cout << "checking: " << pokedex.toString() << endl;

    cout << "testing index bounds" << endl;

    cout << "Adding Gardevoir" << endl;
    pokedex.addPokemon("Garedvoir");
    cout << "current size is: " << pokedex.getCurrentSize() << endl;
    cout << "checking: " << pokedex.toString() << endl;

    cout << "Adding Arceus" << endl;
    pokedex.addPokemon("Arceus");
    cout << "current size is: " << pokedex.getCurrentSize() << endl;
    cout << "checking: " << pokedex.toString() << endl;

    cout << "Adding Nidoran, should not be possible" << endl;
    pokedex.addPokemon("Nidoran");
}

void testRemovePokemon() {
    cout << "making pokedex size 7" << endl;
    Pokedex pokedex(7);
    cout << "max size is: " << pokedex.getMaxSize() << endl;
    cout << "current size is: " << pokedex.getCurrentSize() << endl;

    cout << "adding Charmander, Squirtle, Eevee, Vaporeon and Greninja" << endl;
    pokedex.addPokemon("Charmander");
    pokedex.addPokemon("Squirtle");
    pokedex.addPokemon("Eevee");
    pokedex.addPokemon("Vaporeon");
    pokedex.addPokemon("Greninja");
    cout << "checking: " << endl;
    cout << pokedex.toString() << endl;

    cout << "removing pokemon at index 1" << endl;
    pokedex.removePokemon(1); 
    cout << pokedex.toString() << endl;

    cout << "removing pokemon at index 1283" << endl;
    pokedex.removePokemon(1283);

    cout << "removing pokemon at index 2" << endl;
    pokedex.removePokemon(2);
    cout << pokedex.toString() << endl;

}

void testMiscellaneous () {
    cout << "making pokedex size 4" << endl;
    cout << "Adding Pikachu, Metagross, Dragonite" << endl;
    Pokedex pokedex(4);
    pokedex.addPokemon("Pikachu");
    pokedex.addPokemon("Metagross");
    pokedex.addPokemon("Dragonite");
    cout << "checking: " << pokedex.toString() << endl;
    cout << "getting pokemon at index 2" << endl;
    cout << pokedex.getPokemonName(2) << endl;
    cout << "Getting pokemon at index 99" << endl;
    cout << pokedex.getPokemonName(99) << endl;
}
// sizeof(someArray)/sizeof(int) -1 = array length of int someArray[].
// you are taking the byte size of the array and deviding by the byted to get values?