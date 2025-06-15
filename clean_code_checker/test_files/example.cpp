// This file contains an example C++ source code with intentional bad practices for testing.

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std; // Mauvaise pratique : pollue l’espace de noms global

#define X 10 // Macro non descriptive
#define loop for // Mauvais usage de macro pour remplacer du code

class testclass{ // Nom de classe non en PascalCase, accolade collée
public:
    void DoSTUFF(int ARG1,int arg2){int t=0;for(int i=0;i<10;i++){t+=i;}cout<<"Sum:"<<t<<endl;} // Pas de formatage, noms incohérents, boucle condensée
};

int veryveryveryveryveryveryveryveryLongVariableName = 42; // Nom beaucoup trop long

void unusedFunction(int a, int b){ // Fonction jamais appelée
    // rien ici
}

int main(){
testclass obj;obj.DoSTUFF(1,2); // Appel sur une même ligne sans espaces

int ARR[5]={1,2,3,4,5}; // Nom de variable en majuscule
loop(int i=0;i<5;i++){ // Mauvais usage de la macro
cout<<"Value:"<<ARR[i]<<endl;} // Code compressé, indentation manquante

if(X==10) cout<<"X is 10"<<endl; else cout<<"X is not 10"<<endl; // Pas d’accolades, indentation manquante

int* p = new int[100]; // Allocation dynamique sans delete
// memory leak intentionnel

return 0;
}
