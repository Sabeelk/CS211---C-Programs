//Kazi_Sabeel_211_HW3
#include <iostream>
using namespace std;

bool check(string input){
  char checkReference[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                              'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  int checkNumRunners[26] = {0};
  int test;

  //increments the number of runners for each letter
  for(int i = 0; i < input.length(); i++){
    for(int j = 0; j < 26; j++){
      if(input[i] == checkReference[j]){
        checkNumRunners[j]++;
      }
    }
  }

  //grabs a number of runners on the team
  for(int i = 0; i < 25; i++){
    if( checkNumRunners[i] > 0){
      test = checkNumRunners[i];
    }
  }

  //checks to see if all the letters match the test value pulled from above
  //returns true or false based on if all teams have same number of runners
  for(int i = 0; i < 26; i++){
    if(checkNumRunners[i] > 0 && checkNumRunners[i] != test){
      return false;
    }
  }
  return true;
}

void race(string input){
  char reference[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
                        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  int numRunners[26] = {0};     //stores number of runners for each team
  double teamScore[26] = {0};   //stores array of score for each team
  int numTeams = 0;             //stores the number of teams
  int winner = 0;               //stores highest score
  int numRunner = 0;            //stores the number of runners on a single team


  /*iterates through each char of string and increases
    count based on reference array of letters.
    calculates the number of runners for each team.
    also calculates the non averaged score for the team.
  */
  for(int i = 0; i < input.length(); i++){
    for(int j = 0; j < 26; j++){
      if(input[i] == reference[j]){
        numRunners[j]++;
        teamScore[j] += (i+1.0);
      }
    }
  }

  //this loop completes the teamsScore array
  //by finding the avg score from the raw score found above
  //loop also calcuates the number of teams and a value for winner above 0
  for(int i = 0; i < 26; i++){
    teamScore[i] /= numRunners[i];
    if(numRunners[i] > 0){
      numTeams++;
    }
    if(teamScore[i] > 0) {
      winner = i;
    }
  }

  //these loops iterates through score array and finds the winner
  //winner represents an index to be used when printing
  //also assigns the standard number of runners to numRunner
  for(int i = 0; i < 26; i++){
    if(teamScore[i] > 0 && teamScore[i] <= teamScore[winner]) {
      winner = i;
    }
  }

  //here we print all of the output for each race
  cout << "There are " << numTeams << " teams." << endl << endl;
  cout << "Each team has " << numRunner << " runners." << endl << endl;
  cout << "Team:\t\t" << "Score:\t\t" << endl;
  for(int i = 0; i < 26; i++){
    if(numRunners[i] > 0 ){
      cout << reference[i] << "\t\t" << teamScore[i] << endl;
    }
  }
  cout << endl << "The winning team is team " << reference[winner]
        << " with a score of " << teamScore[winner] << endl << endl;
}

int main(){
  string keyboard;

  //begin input and take initial results
  cout << "Enter the Race Results" << endl;
  cin >> keyboard;

  //checks to see if input has same number of runners on each team
  //if input is correct, the race function is called and output is written
  //if user enters done, program terminates
  while(1){
    if(check(keyboard) == false){
      cout << "ERROR: Wrong Number of Runners; Try Again" << endl;
      cin >> keyboard;
    }
    if(check(keyboard) == true){
      race(keyboard);
      cout << "Enter done to exit, or enter a new race: " << endl;
      cin >> keyboard;
    }
    if(keyboard == "done" || keyboard == "Done"){
      cout << endl << "Goodbye" << endl;
      exit(1);
    }
  }

  return 0;
}
