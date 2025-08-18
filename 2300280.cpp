// C++ Programming Project of George Wanis Ayed 2300280
#include <iostream>
#include <string>


using namespace  std;
int main(){

    string input = ""; getline(cin, input);
    string substring = ""; // It will come come in handy soon
    float equivelent = 0; // This variable string will be filled and inserted at the place of an operation ending with an E
    float reciprocal = 0; // Required for parallel resistance algebric calculations

    // All the flllowing variables are counters or indices
    int lastPorS = 0; int NoofPsandSs = 0;
    int index_of_the_e_after_the_last_p_or_S = 0;
    int number_of_sapces_in_an_operation = 0;

    // the variable naming is self explainatory

    // The Error Handeling for a string containing wrong operations.
    for(int i = 0; i < input.length(); i++){
        if(input[i] == 'E' || input[i] == 'e' ||
           input[i] == 'P' || input[i] == 'p' ||
           input[i] == 'S' || input[i] == 's' ||
           input[i] == '.' || input[i] == ' ' ||
           input[i] == ',' ||
           (input[i] >= 48 && input[i] <= 57)){ // 48 is the ASCI for '0' and 57 is the ASCI for '9'.
               continue;
           }
        else{
                cout << "Wrong Description";
                return 0;
        }
    }

    // The following is the code to be run if no wrong operations to be found
    do{
        NoofPsandSs = 0;
        for(int i = 0; i < input.length(); i++){ // First for loop for finding the last S or P to find the index for the last operator and counting the nambers of operators in the same loop.
            if(input[i] == 'p' || input[i] == 'P' || input[i] == 's' || input[i] == 'S'){
                lastPorS = i;
                NoofPsandSs++;
            }
        }

        for(int i = lastPorS; i < input.length(); i++){ // Second for loop for finding the E after the last S or P
            if(input[i] == 'e' || input[i] == 'E'){
                index_of_the_e_after_the_last_p_or_S = i;
                break;
            }
        }

        if(input[lastPorS] == 'S' || input[lastPorS] == 's'){
            for(int i = lastPorS + 1; i <= index_of_the_e_after_the_last_p_or_S - 1; i++){ //Looping forward starting from the last S.
                if(input[i] != ' ' && input[i] != ','){
                    substring += input[i];
                }
                if(input[i] == ' ' || input[i] == ','){
                    number_of_sapces_in_an_operation++;
                    if(substring != ""){
                        equivelent += stof(substring);
                        substring=""; // reseting the temporary substring for further usage in the next iterations.
                    }
                }
            }
            if(number_of_sapces_in_an_operation < 2){cout << "Incorrect Input"; return 0;} number_of_sapces_in_an_operation = 0; // Checking if there are more than 1 resistance in series
        }

        else if (input[lastPorS] == 'P' || input[lastPorS] == 'p'){
            for(int i = lastPorS + 1; i <= index_of_the_e_after_the_last_p_or_S - 1; i++){ //Looping forward starting from the last P
                if(input[i] != ' ' && input[i] != ','){
                    substring += input[i];
                }
                if(input[i] == ' ' || input[i] == ','){
                    number_of_sapces_in_an_operation++;
                    if(substring != ""){
                        reciprocal += 1/stof(substring);
                        equivelent = 1/reciprocal;
                        substring=""; // reseting the temporary substring for further usage in the next iterations same as with the last S.
                    }
                }
            }
            if(number_of_sapces_in_an_operation < 3){cout << "Incorrect Input"; return 0;} number_of_sapces_in_an_operation = 0; // Checking if there are more than 2 resistance in parallel
        }

        // after reading the operation segment starting from the Last S or P and ending with an E we are gonna replace this operation segment in the following lines.
        input.erase(lastPorS, index_of_the_e_after_the_last_p_or_S - lastPorS + 1); // We remove this operation segment marked by the S or P and the E.
        input.insert(lastPorS ,to_string(equivelent)); // And then we instert the equivilent of the operation segment we earesed in the preceding line.
        NoofPsandSs--; // Because we've removed an operator.
        reciprocal = 0; // resetting for further use.
        equivelent = 0; //resetting for further use.
    }while(NoofPsandSs); // Here We check for the existance of any S's or P's left inside the input string if so then continue looping, erasing and inserting.

    cout << "The total resistance = " <<stod(input);
    return 0;
}
