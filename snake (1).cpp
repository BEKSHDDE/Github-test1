#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;
void print(vector<vector<char> > rectangle){
    for(int i = 0; i < rectangle.size(); i++){
        for(int j = 0; j < rectangle[i].size(); j++){
            cout << rectangle[i][j];
        }
        cout << endl;
    }
}

int main(){
    string dir;
    vector<vector<char> > rectangle(16, vector<char> (41, ' '));
    for(int i = 0; i < 41; i+=2){
        rectangle[0][i] = '*';
    }
    for(int i = 1; i < 16; i++){
        rectangle[i][0] = '*';
        rectangle[i][40] = '*';
    }
    for(int i = 0; i < 41; i+=2){
        rectangle[15][i] = '*';
    }
    int snakex, snakey;
    snakex = 5;
    snakey = 4;
    vector<char> snake(3);
    for(int i = 0; i < 3; i++){
        if(i == 2)
            snake[i] = 'o';
        else
            snake[i] = '*';
    }    
    int tmp = 0;
    for(int i = snakex; i < snakex + 3; i++){
        rectangle[snakey][i] = snake[tmp];
        tmp++;
    }
    print(rectangle);

    for(int i = snakex; i < snakex + 3; i++){
        rectangle[snakey][i] = ' ';
    }
    // print(rectangle);
    cin >> dir;
    if(dir == "right"){
        int ttt = 0;
        while(true){
            snakex++;
            if(snakex == 38){
                snakex = 1;
            }
            int tmp = 0;
            for(int i = snakex; i < snakex + 3; i++){
                rectangle[snakey][i] = snake[tmp];
                tmp++;
            }
            print(rectangle);
            usleep(70000);
            for(int i = snakex; i < snakex + 3; i++){
                rectangle[snakey][i] = ' ';
            }
            ttt++;
        }
    }
    if(dir == "left"){
        
    }
    if(dir == "up"){
        rectangle[snakey- 1][snakex + 2] = 'o';
        rectangle[snakey][snakex+1] = '*';
        rectangle[snakey][snakex] = '*';
        print(rectangle);
        usleep(70000);
        rectangle[snakey-1][snakex + 2] = ' ';
        rectangle[snakey][snakex+1] = ' ';
        rectangle[snakey][snakex] = ' ';
        rectangle[snakey-1][snakex + 2] = 'o';
        rectangle[snakey][snakex+2] = '*';
        rectangle[snakey][snakex+1] = '*';
        print(rectangle);
        usleep(70000);
        rectangle[snakey-1][snakex + 2] = ' ';
        rectangle[snakey][snakex+2] = ' ';
        rectangle[snakey][snakex+1] = ' ';
        rectangle[snakey-2][snakex + 2] = 'o';
        rectangle[snakey - 1][snakex+2] = '*';
        rectangle[snakey][snakex+2] = '*';
        print(rectangle);
        usleep(70000);
        rectangle[snakey-2][snakex + 2] = ' ';
        rectangle[snakey - 1][snakex+2] = ' ';
        rectangle[snakey][snakex+2] = ' ';
        snakex = snakex + 2;
        snakey = snakey - 2;
        int q = 0;
        while( true){
            snakey--;
            if (snakey == 0){
                snakey = 12;
                
            }
            rectangle[snakey][snakex] = 'o';
            rectangle[snakey + 1][snakex] = '*';
            rectangle[snakey + 2][snakex] = '*';
            print(rectangle);
            usleep(70000);
            rectangle[snakey][snakex] = ' ';
            rectangle[snakey + 1][snakex] = ' ';
            rectangle[snakey + 2][snakex] = ' ';
            q++;
        }
    }
    if(dir == "down"){
        
    }

    return 0;
}