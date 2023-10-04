//Nagendra Chaudhary
//Assignment 10
//11-07-2021

 #include<iostream>
 #include<string>
 #include<fstream>
 #include<ctime>
 #include<cstdlib>
 using namespace std;
                            // Declaration of the square class
class square{
  private:
    int move;
    string message;
    char symbol;
    int  mystery_box;
  int score;

  public:
    square();
    void print();
    int action();
    string data();
     int step();
     void set(int,char,string);

};
                            // Function Prototypes
void print_board(square[], int, int);
void read_board(square[]);
void check_position(int &);
                           // Global variables
const int board_length =20;

int main(){
  cout<<"Welcome to the GraveYard World"<<endl;
  cout<<"------------------------------------------"<<endl;
  cout<<"Press Enter to continue...."<<endl;
  cin.ignore();

  cout<<"   Player one Will Be the Lost Souls"<<endl;
  cout<<"   Player two will be you"<<endl;
  cout<<" ----------------------------------------"<<endl;
  cout<<" Press Enter to continue...."<<endl;
  cin.ignore();
  cout<<" If you land on : '?' you will go back one space"<<endl;
  cout<<" If you land on : '*' you will go forward  one space"<<endl;
  cout<<" If you land on : '%' you will go forward  two spaces"<<endl;
  cout<<"Press Enter to continue...."<<endl;
  cin.ignore();
  cout<<"Only by gettinig the highest score you will survive this Hell"<<endl;
  cout<<"Press Enter to continue...."<<endl;

  int current_player = 1, roll;
  int player1_score=0;
  int player2_score=0;
  int player1_position = 0, player2_position = 0;
  square the_board[board_length];  // declare an array of squares
  srand(time(NULL));

  read_board(the_board);
  print_board(the_board,player1_position,1);
  print_board(the_board,player2_position,2);
 do{
      cout<<"\n\n\nPlayer "<<current_player<<"type enter to roll.\n";
      cin.ignore();
      roll = 1 + (rand() % 5);
      cout << "Player "<<current_player<<" rolled a "<<roll<<".\n";
      if(current_player == 1)
      {
         player1_position += roll;
         check_position(player1_position);
         int x=the_board[player1_position].action();
         string a=the_board[player1_position].data();

            if(x>=0){
                if(a[4]=='W'){
                player1_score+=x;
            }
            else{
                player1_score-=x;
            }}
            player1_position+=the_board[player1_position].step();
            check_position(player1_position);
      }
     else{
        player2_position += roll;
        check_position(player2_position);
            int y=the_board[player2_position].action();
            string b=the_board[player2_position].data();
            if(y>=0){
                if(b[4]=='W')
                {
                player2_score+=y;
            }
            else
            {
                player2_score-=y;
            }}
            player2_position+=the_board[player2_position].step();
            check_position(player2_position);
        }


    print_board(the_board,player1_position,1);
     print_board(the_board,player2_position,2);
     current_player = (current_player % 2) + 1;

    }while ((player1_position<board_length-1) &&
            (player2_position<board_length-1) );
    current_player=(current_player%2)+1;

    cout<<"\n\nPlayer 1 score "<<player1_score<<" Player 2 score "<<player2_score<<endl;
    if (player1_score>player2_score)
    {
        cout<<"Player 1 Wins!!! "<<endl;
    }
    else if(player2_score>player1_score)
    {
        cout<<"Player 2 Wins!!! "<<endl;
    }
    else
    {
     cout<<" \nPlayer "<<current_player<< " Wins!!!\n";
    }
    cin.ignore();
    return 0;
}
void read_board(square b[]){
     ifstream infile;
     infile.open("game.txt");
     int square_number, square_move,square_value1;
     string square_message;
     char square_symbol;
     while(!infile.eof()){
          infile >> square_number >> square_move >> square_symbol>>square_value1;
         getline(infile,square_message);
         if(square_number < board_length)
               b[square_number].set(square_move,square_symbol,square_message);
   }

}
void print_board(square b[], int player_position, int player_number){
     for(int i = 0; i < board_length; i++){
         if(i != player_position){
             b[i].print();}
        else
             cout << player_number;
    }
   cout<<"Goal\n";
    for(int i=0; i<(board_length-2)/2; i++)
       {
         cout <<  "_|";
        }
    cout << "\n";
}
void check_position(int &p){
    if(p < 0)
         p = 0;
    if(p >= board_length)
         p = board_length-1;
}
                           // Functions of the class square
square::square(){
     symbol = ' ';
     move = 0;
    message = "";
}

int square::action()
{
      int x=message[0]-'0';
       return x;

  }

int square::step(){
      cout<<message<<endl;

       return move;
    }
string square::data(){
      return message;
    }

void square::print()
{
     cout << symbol;
}
void square::set(int m, char s, string a_message){
     move = m;
     symbol = s;
     message = a_message;

}

