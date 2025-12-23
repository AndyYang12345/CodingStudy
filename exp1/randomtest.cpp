#include<iostream>
using namespace std;

int ID[100][18];
int mark[100] = {0};

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin.get(); //吸收换行符或空格
        for(int j = 0; j < 18; j++){
            
            ID[i][j] = cin.get() - '0';   
            switch (j)
            {
            case 0:
                mark[i] += ID[i][j]*7;
                break;
            case 1:
                mark[i] += ID[i][j]*9;
                break;
            case 2:
                mark[i] += ID[i][j]*10;
                break;
            case 3:
                mark[i] += ID[i][j]*5;
                break;
            case 4:
                mark[i] += ID[i][j]*8;
                break;
            case 5:
                mark[i] += ID[i][j]*4;
                break;
            case 6:
                mark[i] += ID[i][j]*2;
                break;
            case 7:
                mark[i] += ID[i][j]*1;
                break;
            case 8:
                mark[i] += ID[i][j]*6;
                break;
            case 9:
                mark[i] += ID[i][j]*3;
                break;
            case 10:
                mark[i] += ID[i][j]*7;
                break;
            case 11:
                mark[i] += ID[i][j]*9;
                break;
            case 12:
                mark[i] += ID[i][j]*10;
                break;
            case 13:
                mark[i] += ID[i][j]*5;
                break;
            case 14:
                mark[i] += ID[i][j]*8;
                break;
            case 15:
                mark[i] += ID[i][j]*4;
                break;
            case 16:
                mark[i] += ID[i][j]*2;
                break;
            default:
                break;
            }
        }
    }
    // for(int i = 0; i < N; i++){
    //     cout << mark[i]%11 << endl;
    // }
    // return 0;
    for(int i = 0; i < N; i++){
        int check;
        if(mark[i]%11 == 0) check = 1;
        else if(mark[i]%11 == 1) check = 0;
        else if(mark[i]%11 == 2) check = 'X';
        else if(mark[i]%11 == 3) check = 9;
        else if(mark[i]%11 == 4) check = 8;
        else if(mark[i]%11 == 5) check = 7;
        else if(mark[i]%11 == 6) check = 6;
        else if(mark[i]%11 == 7) check = 5;
        else if(mark[i]%11 == 8) check = 4;
        else if(mark[i]%11 == 9) check = 3;
        else if(mark[i]%11 == 10) check = 2;

        if(check != ID[i][17]){
            for(int j = 0; j < 18; j++){
                cout << ID[i][j];
            }
        }
        cout<<endl;
    }    return 0;
}