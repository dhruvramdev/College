#include <iostream>

using namespace::std;

void init(int game[3][3]){
    for(int i=0 ; i<3; i++){
        for(int j=0 ; j<3; j++) {
            game[i][j] = -1 ;
        }
    }
}

void print(int game[3][3]){
    for(int i=0 ; i<3; i++){
        for(int j=0 ; j<3; j++) {
            if(game[i][j] == -1 ){
                cout<<"     " ;
            } else if(game[i][j] == 0 ){
                cout<<"  O  " ;
            } else if(game[i][j] == 1 ){
                cout<<"  X  " ;
            }
            if (j < 2) {
                cout << "|" ;
            }
        }
        if (i < 2) {
            cout << endl << "-----------------" ;
        }
        
        cout << endl ;
        
    }
}


int input(int x , int y , int user, int game[3][3]){
    if(game[x][y] != - 1 ) {
        return 1;
    }
    game[x][y] = (user % 2 ==  0) ? 0 : 1 ;
    return 0;
}

int check(int game[3][3]){
    for(int i=0;i<3;i++){
        if ( (game[i][0] == game[i][2] && game[i][0] == game[i][1] ) && game[i][0] != -1 ){    
            return 0 ;
        }
    }
    
    for(int i=0;i<3;i++){
        if ( (game[0][i] == game[1][i] && game[0][i] == game[2][i] ) && game[0][i] != -1 ){  
            return 0 ;
        }
    }
    
    if ( (game[0][0] == game[1][1] && game[0][0] == game[2][2] ) && game[0][0] != -1 ){ 
        return 0 ;
    }
    
    if ( (game[0][2] == game[1][1] && game[0][2] == game[2][0] ) && game[0][2] != -1 ){ 
        return 0 ;
    }
    
    return -1 ;    
    
    //return 0;
}

int main()
{
    int i=0,j=0;
    int game[3][3];
    int choice ;
    
    int x,y ;    
    int user = 0;
    int gameison = 1 ;
    
    init(game);
    
    while(gameison){
        print(game);
        
        cout << "User " << user%2 + 1 << endl ;
        cout << "Enter Choice : " ;
        cin >> choice ;
        cout << "Choice : " << choice << endl;
        
        x = (choice - 1)  / 3  ;
        y = ( choice % 3 + 2 ) % 3 ;
        
        int temp = input(x,y,user,game);
        if(temp){
            cout<<"Already Filled Choice" << endl; 
            continue;
        }
        
        gameison = check(game);
        
        user++ ;
    }
    
    print(game);
    cout << "User " << user%2 << " Won" << endl ;
    return 0;
}



