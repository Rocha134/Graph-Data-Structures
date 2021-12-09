// Iker Guerrero Gonzales - A00830026
// Aldo Mauricio Cruz Lozada - A01732372
// Francisco Rocha Juarez -A01730560

#include <iostream>
#include<list>
#include <bits/stdc++.h>

using namespace std;


int answer;
int answertwo;
int r;
int number[1000];
int numbertwo[1000];
int d;
int sequence;
int numberfour[1000];
int numberthree[1000];
int x = 0;
int y = 0;
int Q;
char arrange[]={"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"};
char arrange2[]={"A""B""C""D""E""F""G""H""I""J""K""L""M""N""O""P""Q""R""S""T""U""V""W""X""Y""Z"};


// We create the class with its atributes
class line{
  public:
    list<int> *relist;
    map<int, bool> already;
    int z;

    line(int m){
      relist = new list<int> [m];
      z = m;
    }

    // Here we can save  the written values
    void sum(int dt,int m){
      relist[dt].push_back(m);
    }

    void DFS(int m);
    void BFS(int s);

    //This function print the letters
    void print(){
      bool first = true;
      for(int i = 0; i < z; i++){
        if (i<27){
          for (d = 0;d < i; d++){
          }
          //if (first){
            //cout << "-";
          //}
          cout << arrange[d-1];
          first = false;
        }
        else{
          answertwo = i % 26;
          for (d = 0 ;d < i/26; d++){
          }
          if (first){
            cout << "-";
          }
          cout << arrange[d-1] << arrange2[answertwo-1];
          first = false;
        }

        for(auto count:relist[i]){
          bool first = true;
          if (count < 27){
            for (r = 0; r < count; r++) {
            }
            if (first){
              cout << "-";
            }
            cout << arrange[r-1];
            first = false;
          }
          else{
            answer = count % 26;
            for (r = 0; r < count/26; r++) {
            }
            if (first){
              cout << "-";
            }
            cout << arrange[r-1] << arrange2[answer-1];
            first = false;
          }
        }
        cout << endl;
      }
      cout << endl;
    }
};


//The void function of DFS
void line::DFS(int m){
  already[m] = true;

  if (m < 27){
    for (d = 0; d < m; d++){
    }
    cout << arrange[m-1] << " ";
  }
  else{
    answertwo = m % 26;
    for (d = 0; d < m / 26; d++){
    }
    cout << arrange[d-1] << arrange2[answertwo-1] << " ";
  }

  list<int>::iterator i;

  for (i = relist[m].begin(); i != relist[m].end(); ++i){
    if (!already[*i]){
      DFS(*i);
    }
  }
}


//The BFS print function
void line::BFS(int s)
{
  bool *already = new bool[Q];
  for(int i = 0; i < Q; i++){
      already[i] = false;
  }

  // The creation of the BFS stack
  list<int> sequence;
  already[s] = true;
  sequence.push_back(s);
  list<int>::iterator i;
  while(!sequence.empty())
  {
    //Here the print order is defined
    s = sequence.front();
    if (s < 27){
      for (d = 0; d < s; d++){
      }
      cout << arrange[d-1] << " ";
    }
    else{
      answertwo = s % 26;
      for (d = 0; d < s / 26; d++) {
      }
      cout << arrange[d-1] << arrange2[answertwo-1] << " ";
    }

    sequence.pop_front();

    for (i = relist[s].begin(); i != relist[s].end(); ++i)
    {
      if (!already[*i])
      {
        already[*i] = true;
        sequence.push_back(*i);
      }
    }
  }
}


int main() {
  //Start the call of the matrice
  cin >> sequence;
  line g(sequence + 1);
  int matrice[1000][1000];

  //The binary values trun into inputs and outputs
  for (int i = 0; i < sequence; i++) {
    for (int r = 0; r < sequence; r++) {
      cin >> matrice[i][r];
      if(matrice[i][r] == 1){
        numberfour[y] = i + 1;
        numberthree[x] = r + 1;
        y++;
        x++;
      }
    }
  }

  //The matrix is printed
  cout << endl;
  for (int i = 0; i < sequence; i++) {
    for (int r = 0; r < sequence; r++) {
        cout << matrice[i][r] << " ";
    }
    cout << "\n";
  }

  for(int r = 0; r < y; r++){
    g.sum(numberfour[r] ,numberthree[r]);
  }

  g.print();
  g.BFS(1);
  cout << endl;
  cout << endl;
  g.DFS(1);
  cout<<endl;
}
