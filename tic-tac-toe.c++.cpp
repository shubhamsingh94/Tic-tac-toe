#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<time.h>

using namespace std;

char a[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int m=0,p1,p2,choice,game=1,level;


int check_tictactoe(char mark);
int fill_tictactoe(char mark);


int main(){
    int i,j,l,k,r,x=1,num,b,target,left,chance,option;
    if(game==1){
        cout << "\n\n\n\n\n\n\t\t\tOpposition:";
        cout << "\n\t\t\t<1> Another Player.";
        cout << "\n\t\t\t<2> Computer.";
        cout << "\n\n\t\t\tEnter your competeter:";
        cin >> choice;
        game++;
        system("cls");
        if(choice==2){
            cout << "\n\n\n\n\n\n\t\t\tLevels:";
            cout << "\n\t\t\t<1> -> Low";
            cout << "\n\t\t\t<2> -> High";
            cout << "\n\n\t\t\tEnter Level: ";
            cin >> level;
            system("cls");
        }
    }

    for(i=0;i<3;i++){                           // Layout formation starts.

        for(j=0;j<25;j++){
            cout << "-";
        }
        cout << "\t";
        for(j=0;j<25;j++){
            cout << "-";
        }

        cout << "\n";
        for(l=0;l<3;l++){
            for(k=0;k<3;k++){
                if(l==1){
                    cout << "|";
                    cout << "   ";
                    cout << a[3*i+k];
                    cout << "   ";
                }else{
                    cout << "|\t";
                }
            }
            cout << "|\t";
            for(k=0;k<3;k++){
                if(l==1){
                    cout << "|";
                    cout << "   ";
                    cout << x;
                    cout << "   ";
                    x++;
                }else{
                    cout << "|\t";
                }
            }
            cout << "|\t";
            cout<< "\n";
        }

    }

        for(j=0;j<25;j++){
            cout << "-";
        }
        cout << "\t";
        for(j=0;j<25;j++){
            cout << "-";
        }                                             //Layout Formation Ends.


    p1 = check_tictactoe('X');                        // Checking whether Player1 completes its three number set.

    p2 = check_tictactoe('O');                        // Checking whether Player2 completes its three number set.


    if(p1==1){
        for(i=0;i<9;i++){
            a[i]=' ';
        }
        if(choice==1){
            cout << "\nPlayer1 WINS!!!\n";              //If player1 completes its set then we print the Result.
        }else{
            cout << "\nYou WIN!!!";
        }
        Sleep(5000);
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\tEnter 1 to Play again.\n\t\t\tEnter 2 key: To QUIT!\n\t\t\tEnter Your Choice:";
        cin >> option;
        if(option==1){
            system("cls");
            for(i=0;i<9;i++){
                a[i]=' ';
            }
            game=1;
            main();
        }else{
            exit(1);
        }

    }
    else if(p2==1){
        for(i=0;i<9;i++){
            a[i]=' ';
        }if(choice==1){                                 //If player2/Computer completes its set then we print the Result.
        cout << "\nPlayer2 WINS!!!\n";}
        else{
            cout << "\nYou LOSE!!!";
        }
        Sleep(5000);
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\tEnter 1 to Play again.\n\t\t\tEnter 2 key: To QUIT!\n\t\t\tEnter Your Choice:";
        cin >> option;
        if(option==1){
            system("cls");
            for(i=0;i<9;i++){
                a[i]=' ';
            }
            game=1;
            main();
        }else{
            exit(1);
        }
    }

        if(choice==1){
        b=m%2+1;

        left = 0;
        for(i=0;i<9;i++){
            if(a[i]==' '){
                left++;
            }
        }

        if(left==0){
            cout << "\nTie-up Match.";
             Sleep(5000);
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\tEnter 1 to Play again.\n\t\t\tEnter 2 key: To QUIT!\n\t\t\tEnter Your Choice:";
        cin >> option;
        if(option==1){
            system("cls");
            for(i=0;i<9;i++){
                a[i]=' ';
            }
            game=1;
            main();
        }else{
            exit(1);
        }
        }

        cout << "\n\nPlayer"<< b << " Enter Your Choice:";

        while(1){
            cin >> num;
            if(a[num-1]==' ' && (num>0 && num<10)){

                if(b==1){
                    a[num-1]='X';
                    break;
                }else{
                    a[num-1]='O';
                    break;
                }
            }else{
                cout << "\nYou entered Invalid Position.\nTry Again!!!\n";
            }
        }
        m++;

    }else{
        left = 0;
        for(i=0;i<9;i++){
            if(a[i]==' '){          //left checks whether all blocks are filled.
                left++;
            }
        }
        if(left==0){
            cout << "\nTie-up Match.";
             Sleep(5000);
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\tEnter 1 to Play again.\n\t\t\tEnter 2 key: To QUIT!\n\t\t\tEnter Your Choice:";
        cin >> option;
        if(option==1){
            system("cls");
            for(i=0;i<9;i++){
                a[i]=' ';
            }
            game=1;
            main();
        }else{
            exit(1);
        }
        }

        cout << "\n\nEnter Your Choice:";
        while(1){
            cin >> num;

            if(a[num-1]==' ' && (num>0 && num<10)){
                a[num-1]='X';
                break;
            }else{
                cout << "\nYou entered Invalid Position.\nTry Again!!!\n";
            }
        }

        if(fill_tictactoe('O')!=-1){
            target = fill_tictactoe('O');       //If YES Joining the 3 crosses.
            a[target]='O';
        }else{
            if(fill_tictactoe('X')!=-1){
                target = fill_tictactoe('X');   //If Yes BLocking the 3 OVAL Shape.
                a[target]='O';
            }else{
                for(i=0;i<9;i++){
                if(a[i]==' '){          //left checks whether all blocks are filled.
                    left++;
                }
            }
                if(left!=0){
                if(level==1){

                    while(1){
                        srand(time(NULL));
                    r = rand()%9;
                        if(a[r]==' '){
                            a[r]='O';
                            break;
                        }
                    }
                }else if(level==2){

                if(a[0]==' ' || a[2]==' ' || a[6]==' ' || a[8]==' ' || a[4]==' '){
                    while(1){
                        srand(time(NULL));
                        r = rand()%5;

                        if(r==0 && a[0]==' '){
                            a[0]='O';
                            break;
                        }else if(r==1 && a[2]==' '){
                            a[2]='O';
                            break;
                        }
                        else if(r==2 && a[6]==' '){
                            a[6]='O';
                            break;
                        }else if(r==3 && a[8]==' '){
                            a[8]='O';
                            break;
                        }else if(r==5 && a[4]==' '){
                            a[4]='O';
                            break;
                        }

                        }
                    }
                    }else{
                        while(1){
                        srand(time(NULL));
                        r = rand()%4;

                        if(r==0 && a[1]==' '){
                            a[1]='O';
                            break;
                        }else if(r==1 && a[3]==' '){
                            a[3]='O';
                            break;
                        }
                        else if(r==2 && a[5]==' '){
                            a[5]='O';
                            break;
                        }else if(r==3 && a[7]==' '){
                            a[7]='O';
                            break;
                        }
                    }
                    }
                    }else if(level==3){
                    if(chance==1){
                        srand(time(NULL));
                        r = rand()%2;
                        if(r==0){
                            a[i]=='O';
                            if(num%2==1){

                            }
                        }
                    }

                }
            }
        }




    }

        system("cls");
        main();
        exit(1);


    return 0;
}



int check_tictactoe(char mark){

    if(a[0]==mark && a[1]==mark && a[2]==mark){
       return 1;
    }
    else if(a[3]==mark && a[4]==mark && a[5]==mark){
        return 1;
    }
    else if(a[6]==mark && a[7]==mark && a[8]==mark){
        return 1;
    }
    else if(a[0]==mark && a[3]==mark && a[6]==mark){
        return 1;
    }
    else if(a[1]==mark && a[4]==mark && a[7]==mark){
        return 1;
    }
    else if(a[2]==mark && a[5]==mark && a[8]==mark){
        return 1;
    }
    else if(a[0]==mark && a[4]==mark && a[8]==mark){
        return 1;
    }
    else if(a[2]==mark && a[4]==mark && a[6]==mark){
        return 1;
    }
    else{
        return 0;
    }

}

int fill_tictactoe(char mark){
    if(a[0]==mark && a[1]==mark && a[2]==' '){
       return 2;
    }else if(a[0]==mark && a[1]==' ' && a[2]==mark){
       return 1;
    }else if(a[0]==' ' && a[1]==mark && a[2]==mark){
       return 0;
    }

    else if(a[3]==mark && a[4]==mark && a[5]==' '){
        return 5;
    }else if(a[3]==mark && a[4]==' ' && a[5]==mark){
        return 4;
    }else if(a[3]==' ' && a[4]==mark && a[5]==mark){
        return 3;
    }

    else if(a[6]==mark && a[7]==mark && a[8]==' '){
        return 8;
    }else if(a[6]==mark && a[7]==' ' && a[8]==mark){
        return 7;
    }else if(a[6]==' ' && a[7]==mark && a[8]==mark){
        return 6;
    }

    else if(a[0]==mark && a[3]==mark && a[6]==' '){
        return 6;
    }else if(a[0]==mark && a[3]==' ' && a[6]==mark){
        return 3;
    }else if(a[0]==' ' && a[3]==mark && a[6]==mark){
        return 0;
    }

    else if(a[1]==' ' && a[4]==mark && a[7]==mark){
        return 1;
    }else if(a[1]==mark && a[4]==' ' && a[7]==mark){
        return 4;
    }else if(a[1]==mark && a[4]==mark && a[7]==' '){
        return 7;
    }

    else if(a[2]==' ' && a[5]==mark && a[8]==mark){
        return 2;
    }else if(a[2]==mark && a[5]==' ' && a[8]==mark){
        return 5;
    }else if(a[2]==mark && a[5]==mark && a[8]==' '){
        return 8;
    }

    else if(a[0]==' ' && a[4]==mark && a[8]==mark){
        return 0;
    }else if(a[0]==mark && a[4]==' ' && a[8]==mark){
        return 4;
    }else if(a[0]==mark && a[4]==mark && a[8]==' '){
        return 8;
    }

    else if(a[2]==' ' && a[4]==mark && a[6]==mark){
        return 2;
    }else if(a[2]==mark && a[4]==' ' && a[6]==mark){
        return 4;
    }else if(a[2]==mark && a[4]==mark && a[6]==' '){
        return 6;
    }

    return -1;

}
