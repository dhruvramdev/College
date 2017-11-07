#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin;
    char filename[20];
    cout<< "Enter Filename : ";
    gets(filename);
    fin.open(filename);
    int line=0,word=0,chars=0;
    char ch;
    fin.seekg(0,ios::end);
    fin.seekg(0,ios::beg);
    while(fin){
        fin.get(ch);
        if(ch!=' ' && ch!='\n') ++chars;
        if(ch==' '|| ch=='\n') ++word;
        if(ch=='\n')  ++line;
        
    }
    cout<< "Sentences= "<<line<< "\nWords= "<<word<< "\nCharacters= "<<chars<<endl;
    fin.close(); // closing file
    return 0;
}
