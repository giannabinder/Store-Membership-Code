#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//function rounds floats to two decimal places
float my_round(float var){
    float value = round(var * 100);
    value /= 100;
    return value;
}

//create exception for if the item they want is not available
class e_out : public exception {
public:
  const char *what() { return "   We are sorry, we are out of that item. Please continue your order.\n"; }
};

//create exception for if they enter a number less than zero
class e_numberPets : public exception {
public:
  const char *what() { return "   Please do not enter a number less than zero or greater than 6."; }
};

//create exception for if they entered the wrong item number
class e_itemNO : public exception {
public:
  const char *what() { return "This number does not corresppond to an item. Please continue your order.\n"; }
};

//create exception for if they entered the wrong quantity number
class e_number : public exception {
public:
  const char *what() { return "   Please enter a number above 0.\n"; }
};

//create exception for if they inputed the wrong command
class e_command : public exception {
public:
  const char *what() { return "Incorrect command entered. Please enter again."; }
};

//create main class for printing Headers
class Headers {
public:
  //create virtual method for printing headers
	virtual void printHeader(){}
};

//create subclass for welcome sign
class Welcome : public Headers {
public:
  void printHeader(){
    //print welcome sign
    cout << "__________________________________________________________________________\n";
    cout << "     ___                                                _,._\n";
    cout << " o__/-  `.  .----.   \\.    W E L C O M E           __.o`   o`\"-.\n";
    cout << " \\__,` | \\-'  /   )`-')  T O   C R E E D ’ S    .-O o `\"-.o   O )_,._ \n";
    cout << "     ) `-`    \\  ((`\"`      C O O K I E        ( o   O  o )--.-\"`O   o\"-.\n";
    cout << " ___/  ,    .'7 / |  C O N F E C T I O N E R Y  '--------'  (   o  O    o)\n";
    cout << "(_,___/...-` (_/_/                                           `----------’\n";
    cout << "__________________________________________________________________________\n\n";
    }
};

//create subclass for menu sign
class Menu : public Headers {
public:
  void printHeader(){
    //print menu sign
    cout << "__________________________________________________________________________\n";
    cout << "        (                                                         )\n ";
    cout << "          )                                              __o__  (\n";
    cout << "     __..---..__                                     ,-./------\\._ )\n";
    cout << " ,-='  /  |  \\  `=-.        O U R  M E N U          (( |========,-’\n";
    cout << ":--..___________..--;                                `-’\\------/\n";
    cout << " \\.,_____________,./                                     `-==-’ \n";
    cout << "__________________________________________________________________________\n\n";
  }
};

//create subclasse for receipt signs
class Receipt : public Headers { 
public:
  void printHeader(){
    //print receipt sign header
    cout << "__________________________________________________________________________\n";
    cout << "                                                                  ___\n";
    cout << "(\\,--------------------------------------------------------------'| |'--o\n";
    cout << " /                                                                \\_/___/\n";
    cout << "|                       Y O U R   R E C E I P T                     /\n";
    cout << " \\__      ____________________________________________________     /\n";
    cout << "    (__)__)                                                  (__)__)\n";
    cout << "__________________________________________________________________________\n\n";
  }

  //print receipt sign subheading
  void printSubHeader(){
    //print the tree
    cout << "__________________________________________________________________________\n";
    cout << "oO  oOo                                                           (‘_\n ";  
    cout << " \\  /                                                           '(  o’>\n"; 
    cout << "oo\\/  ,_,                                                        _) (\n"; 
    cout << " \\/  (O,O)    E N J O Y   Y O U R   T A S T Y   T R E A T S !   /    )\n"; 
    cout << " /   (''')                                                     /_,’ / \n"; 
    cout << "/=====\"-\"========================================================m""m===\n"; 
    cout << "__________________________________________________________________________\n\n";
  }
};

//create subclass for creating a membership header
class Create : public Headers { 
public:
  void printHeader(){
    //print membership header
    cout << "__________________________________________________________________________\n";
    cout << "     ______                                                      ___\n ";  
    cout << "   /      \\                                                   .'o O'-.\n "; 
    cout << "  (  Chef  )                                                / O o_.-`|\n"; 
    cout << "    \\      /      C R E A T E   A   M E M B E R S H I P     /O_.-'  O |\n"; 
    cout << "     |''''|                                                 | o   o .-`\n"; 
    cout << "     |____|                                                 |o_O_.-'\n"; 
    cout << "__________________________________________________________________________\n\n";
  }

  void printSubHeader(){
    //print creating a membership subheader
    cout << "__________________________________________________________________________\n";
    cout << "                                                      T H A N K   Y O U \n";  
    cout << "            __..--''``---....___   _..._    __             F O R\n"; 
    cout << "  // //_.-'    .-/\";  `        ``<._  ``.''_ `. / /   C R E A T I N G\n"; 
    cout << "  //_.-' _..--.'_    \\                    `( ) ) //         A\n"; 
    cout << "  (_..-' // (< _     ;_..__               ; `' /   M E M B E R S H I P\n"; 
    cout << "  / // // //  `-._,_)' // / ``--...____..-' /// /     W I T H   U S !\n"; 
    cout << "__________________________________________________________________________\n\n";
  }
};

//create subclass for editing a memberhsip headers
class Edit : public Headers { 
public:
  void printHeader(){
    //print editing a memberhsip header
    cout << "__________________________________________________________________________\n";
    cout << "(:`--..___...-''``-._             |`._\n";  
    cout << "  ```--...--.      . `-..__      .`/ _\\   \n"; 
    cout << "            `\\     '       ```--`.    />             E D I T\n"; 
    cout << "            : :   :               `:`-'            M E M B E R S H I P\n"; 
    cout << "             `.:.  `.._--...___     ``--...__   \n"; 
    cout << "                ``--..,)       ```----....__,)\n"; 
    cout << "__________________________________________________________________________\n\n";
  }

  void printSubHeader(){
    //print editing a memberhsip subheader
    cout << "__________________________________________________________________________\n";
    cout << "\n";  
    cout << "     |\\_/|                  T H A N K   Y O U                 /\\___/\\" << endl; 
    cout << "     (0_0)                 F O R   K E E P I N G               (o_o)\n"; 
    cout << "    ==(Y)==              U S  U P  T O  D A T E !               (V)\n"; 
    cout << "---(u)---(u)------------------------------------------------oOo--U--oOo---\n"; 
    cout << "____|______|_______|_______|_______|_______|_______|_______|_______|______\n"; 
    cout << "__________________________________________________________________________\n\n";
  }
};

//create subclass for when they exit out the program
class Exit : public Headers { 
public:
  void printHeader(){
    //print editing exit header
    cout << "__________________________________________________________________________\n";
    cout << "       .                       T H A N K   Y O U                  /|\\\n"; 
    cout << "      \":\"                   F O R   V I S I T I N G              / | \\\n"; 
    cout << "    ___:____     |\"\\/\"|          C R E E D ’ S                  /__|__\\\n"; 
    cout << "  ,'        `.    \\  /            C O O K I E         _____________|___\n"; 
    cout << "  |  O        \\___/  |     C O N F E C T I O N E R Y  \\               /\n"; 
    cout << "~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n"; 
    cout << "__________________________________________________________________________\n\n";
  }
};

class menu {
  string order = " ", receipt;
  int num1 = 10, num2 = 10, num3 = 10, num4 = 10, num5 = 10, num6 = 10,
      num7 = 10, num8 = 10, num9 = 10, num10 = 10, num11 = 10, num12 = 10, num13 = 10, num14 = 10, num15 = 10, num16 = 10, num17 = 10, num, item, counter;
  float total;

public:
  void menu1() {
    // print out menu
    cout << "\nFor Hoomans:\n   1. Apple Paw Slice ($3.00)\n   2. Chocolate Lab Cookie ($1.50)\n   3. "
            "Japawnese Cheesecake Slice ($4.00)\n   4. Pupsicle($1.50)\n   5. Muddy Muffin($3.00)\n   6. "
            "Super Smelly Scone($3.00)\n   7. Panting Mango Pudding($2.00)\n   8. Pupxedo Cake "
            "Slice($4.00)   \n   9. Bone Brownie($3.00)\n   10. Energetic Éclair($4.00)\n   11. Creed's "
            "Coffee($1.50)\n   12. Tug-of-War Tea($1.50)\n\nFor Furry Friends:\n   13. Howling Ham($3.00)\n"
            "   14. Fetching Fish($4.00)\n   15. Playful Pup's Cup($2.00)\n   16. Cheese Stick($1.50)\n   17. Wagging Watermelon Wedge($1.50)\n\n";

    cout << "Making your order: \n   Eg. Two Chocolate Lab Cookies and a Muddy Muffin:\n   2x2\n   1x5\n   Order\n__________________________________________________________________________\n\n\nPlease order: \n";
    
    // get order from user until they are done ordering
    while (order != "order" || order != "Order") { //*********************
     cout << "   " ;
      
      //ensure getline() is not ignored
      cin >> ws;
      
      //get order from user
      getline(cin, order);

      if (order == "order" || order == "Order")
        break;
      
      // break down their order
      num = stoi(order.substr(0, order.find_first_of("x")));
      item = stoi(order.erase(0, order.find_first_of("x") + 1));

      //throw an error if the number of item ordered is 0 or less
      try{
        if (num <= 0)
          throw e_number();
        
        // call method to update inventory
        dessert(num, item);
      }

      //catch error
      catch(e_number &error){
        cout << error.what();
      }
    }
  }

  // method takes in the item ordered and amount and calls a method to update
  // the inventory
  void dessert(int num, int item) {

    //use try block to ensure correct item number was entered
    try{
      if (item == 1)
        num1 = numberOfDesserts(num1, num, item);

      else if (item == 2)
        num2 = numberOfDesserts(num2, num, item);
  
      else if (item == 3)
        num3 = numberOfDesserts(num3, num, item);
  
      else if (item == 4)
        num4 = numberOfDesserts(num4, num, item);
  
      else if (item == 5)
        num5 = numberOfDesserts(num5, num, item);
  
      else if (item == 6)
        num6 = numberOfDesserts(num6, num, item);
  
      else if (item == 7)
        num7 = numberOfDesserts(num7, num, item);
  
      else if (item == 8)
        num8 = numberOfDesserts(num8, num, item);
  
      else if (item == 9)
        num9 = numberOfDesserts(num9, num, item);

      else if (item == 10)
        num10 = numberOfDesserts(num10, num, item);
  
      else if (item == 11)
        num11 = numberOfDesserts(num11, num, item);
  
      else if (item == 12)
        num12 = numberOfDesserts(num12, num, item);
        
      else if (item == 13)
        num13 = numberOfDesserts(num13, num, item);
  
      else if (item == 14)
        num14 = numberOfDesserts(num14, num, item);
  
      else if (item == 15)
        num15 = numberOfDesserts(num15, num, item);
  
      else if (item == 16)
        num16 = numberOfDesserts(num16, num, item);
  
      else if (item == 17)
        num17 = numberOfDesserts(num17, num, item);
  
      // if the wrong item order is entered throw an exception
      else
          throw e_itemNO();
    }

    //catch exception
    catch(e_itemNO &error) {
      cout << error.what() << endl << endl;
    }
  }

  // method checks if the inventory is empty and if there is enough of the item
  // for their order
  int numberOfDesserts(int itemNO, int num, int item) {

    // if no more of the item is left, throw an exception
    try {
      if (itemNO == 0)
        throw e_out();
      itemNO -= num;

      // if not enough of the item is availble, throw an excpetion
      if (itemNO < 0) {
        num = itemNO + num;
        itemNO = 0;
        counter += num;
        //update receipt
        receiptUpdate(num, item);
        //update counter
        counter += num;
        throw num;
      }
      //update receipt
      receiptUpdate(num, item);

      //update counter
      counter += num;
    } 

    //catch exception
    catch (e_out &error) {
      cout << error.what();
    }

    //catch exception
    catch (int zeroed) {
      cout << "   We only have " << num << " of this item left. We will give you the remainder. Please continue with your order." << endl;
    }

    // return the inventory number
    return itemNO;
  }

  // method returns counter
  int returnCounter() { return counter; }

  //method updates receipt
  void receiptUpdate(int num, int item){
    
    //decalre variable
    float value;

    //add substring to recepit
    receipt += to_string(num) + " x ";

    //add substrings to receipt depending on what item they ordered and of how many
    if (item == 1){
      value = num * 3;
      receipt += "Apple Paw Slice               $";
    }

    else if (item == 2){
      value = num * 1.5;
      receipt += "Chocolate Lab Cookie          $";
    }
    
    else if (item == 3){
      value = num * 4;
      receipt += "Japawnese Cheesecake Slice    $";
    }

    else if (item == 4){
      value = num * 1.5;
      receipt += "Pupsicle                      $";
    }
    
    else if (item == 5){
      value = num * 3;
      receipt += "Muddy Muffin                  $";
    }

    else if (item == 6){
      value = num * 3;
      receipt += "Super Smelly Scone            $";
    }

    else if (item == 7){
      value = num * 2;
      receipt += "Panting Mango Pudding         $";
    }

    else if (item == 8){
      value = num * 4;
      receipt += "Pupxedo Cake Slice            $";
    }

    else if (item == 9){
      value = num * 3;
      receipt += "Bone Brownie                  $";
    }

    else if (item == 10){
      value = num * 4;
      receipt += "Energetic Éclair              $";
    }

    else if (item == 11){
      value = num * 1.5;
      receipt += "Creed's Coffee                $";
    }

    else if (item == 12){
      value = num * 1.5;
      receipt += "Tug-of-War Tea                $";
    }

    else if (item == 13){
      value = num * 3;
      receipt += "Howling Ham                   $";
    }

    else if (item == 14){
      value = num * 4;
      receipt += "Fetching Fish                 $";
    }

    else if (item == 15){
      value = num * 2;
      receipt += "Playful Pup's Cup             $";
    }

    else if (item == 16){
      value = num * 1.5;
      receipt += "Cheese Stick                  $";
    }

    else if (item == 17){
      value = num * 1.5;
      receipt += "Wagging Watermelon Wedge      $";
    }

    //update counter
    total += value;

    //when converting a float to a string, more digits are added, remove the extra digits so there are only two
    string valueS = to_string(my_round(value));
    int numb = stoi(valueS.substr(0, valueS.find_first_of(",")));
    valueS = valueS.erase(valueS.find_first_of(".") + 3, valueS.length());

    //add substring of price to recipt
    receipt += valueS + "\n";
  }

  //method prints recipt
  void printReceipt(){

    //print the receipt
    cout << receipt << endl;
    
    //print total
    cout << "Total                             $" << total << endl << endl;

    //reset the receipt and counter
    total = 0;
    receipt = "";
    counter = 0;
  }
};

//create member class
class members {
  //declare variables
  int pets = -1, numBought = 0;
  string email, name;

public:
  //method gets information from user
  void create() {

    cout << "Please enter the appropriate information." << endl;
    
    //get name
    cout << "   Name: ";

    //ensure getline() is not ignored
    cin >> ws;
    
    getline(cin, name);

    //get email
    cout << "   Email: ";
    getline(cin, email);

    //create while loop so correct number of pets is inputted
    while (pets < 0){
      
      //get email
      cout << "   Number of pets: ";
      cin >> pets;

      //throw an error if the number of pets is less than 0
      try{
        if (pets < 0 || pets > 6)
          throw e_numberPets();
      }

      //catch error
      catch(e_numberPets &error){
        cout << error.what() << endl;
      }
    }

  }

  //method returns name
  string returnName() { return name; }

  //method returns email 
  string returnEmail() { return email; }

  //method updates member's dessert counter
  void counterUpdate(int counter) {

    //update counter
    numBought += counter;
  }

  void counterPrint(){

    cout << endl;

    //if they have reached ten
    if (numBought >= 10){

      //if they have pet(s), they will get treats for their pets
      if (pets > 0)
        cout << "Congratulations! "<< name <<", you have reached the tenth dessert.\nYou have received " << pets <<  " complimentary Howling Ham Pieces on us!" << endl;

      //if they don't have pets they will receive a coffee
      else
        cout << "Congratulations! "<< name <<", you have reached the tenth dessert.\nYou have received a complimentary Creed's Coffee on us!" << endl;

      //reset member's counter
      numBought -= 10;
    }

    //if they have not reached ten, tell them how many desserts they have left to go
    else{

      //if they have a pet(s), tell them they will receive treats for their pets on their tenth item
      if (pets > 0)
        cout << name << ", you have " << (10 - numBought % 10) << " desserts to go until you receive " << pets <<  " complimentary\nHowling Ham Pieces on us!" << endl;

      //if they dont have pets, tell them they will receive a coffee on their tenth order
      else
        cout << name << ", you have " << (10 - numBought % 10)<< " desserts to go until you receive a complimentary\nCreed's Coffee" << endl;
    }

    cout << endl;
    
  }

  //method allows member to edit their information
  void edit(){
    //declare variables
    int editCommand;
    string cont = "yes";

    //while loop allows user to edit their info until they say they don't want to
    while (cont == "yes" || cont == "Yes"){

      //ask user what they would like to edit and get input from them
      cout << endl << "What would you like to edit\n   1. Name\n   2. Email \n   3. Number of Pets\n   Input: ";
      cin >> editCommand;
 
      try{
        //if they want to edit their name
        if (editCommand == 1){
          cout << "   Please enter your updated name: ";

          //ensure getline() is not ignored
          cin >> ws;
          
          getline(cin, name);
        }
  
        //if they want to edit their email
        else if (editCommand == 2){

          //ensure getline() is not ignored
          cin >> ws;
          
          getline(cin, email);
        }
  
        //if they want to edit the number of pets they have
        else if (editCommand == 3){
          
          //throw an error if the number of pets is less than 0
          try{
            cout << "   Please enter your updated number of pets: ";
            cin >> pets;
            
            if (pets < 0 || pets > 6)
              throw e_numberPets();
          }
  
          //catch error
          catch(e_numberPets &error){
            cout << error.what() << endl << endl;
          }
        }
  
        else{
          throw e_command();
        }
      }

      catch(e_command &error){
        cout << error.what() << endl << endl;
      }

      //declare variable
      int go = 1;

      //wile loop ensure valid input
      while (go == 1){
        
        //ask user if they would like to make another transaction
        cout << "\n[yes/no] Would you like to make another edit? ";
        
        //ensure geline() is not ignored
        cin >> ws;
  
        //get answer from user
        getline(cin, cont);
  
        cout << endl;

        //verify input
        if (cont == "yes" || cont == "Yes" || cont == "no" || cont == "No")
          go = 0;
          
        else
          cout << "Invalid input, please reenter." << endl;
      }
    }

    cout << endl << "Thank you for keeping us up to date!" << endl << endl;
  }
};

int main() {
  // initialize array of objects for member class
  members members[100];

  //create objects for header class
  Welcome welcome_;
  Menu menu_;
  Receipt receipt_;
  Create create_;
  Edit edit_;
  Exit exit_;

  //create object of class menu
  menu Ordering;

  // decalre variables
  int command, counter;
  string name, member, email, cont = "yes";

  //print welcome header
  welcome_.printHeader();

  cout << "*Members get a complimentary Howling Ham for each of their pets on their\n tenth dessert or a complimentary Creed's Coffee!" << endl << endl;

  //create while loop so multiple transactions can be made
  while (cont == "yes" || cont == "Yes"){

    try{
      // ask user what they would like to do
      cout << "__________________________________________________________________________\n";
      cout << "Program Menu:\n   1. Order\n   2. Sign up a Member\n   3. Edit an Existing membership\n";
      cout << "__________________________________________________________________________\n";
      cout <<"\n  Input: ";
      cin >> command;

      cout << endl;
    
      //if they would like to order or edit their membership
      if (command == 1 || command == 3) {
    
        //if they would like to order
        if (command == 1){
          //print menu header
          menu_.printHeader();
          
          //print out menu and get their order
          Ordering.menu1();
          counter = Ordering.returnCounter();
  
          // ask if they are a member
          cout << endl << "[yes/no] Are you a member? ";
          getline(cin, member);
        }
    
        // if they are a member or want to edit their membership
        if (member == "yes" || member == "Yes" || command == 3) {

          //declare variable
          int found = 0;
          
          //create while loop so correct information is entered
          while (found == 0){
            //get their name
            cout << endl << "Please enter the appropriate information with correct capitalization." << endl;
            cout << "   Name: ";
  
            //ensure geline() is not ignored
            cin >> ws;
            
            getline(cin, name);
      
            //get their email
            cout << "   Email: ";
            getline(cin, email);
      
            //find their membership
            for (int u = 0; u < 100; u++) {
              if (members[u].returnName() == name && members[u].returnEmail() == email){
      
                //if they are making and order, call method to update the amount of items they have bought
                if (command == 1){

                  //call method to update member's counter 
                  members[u].counterUpdate(counter);

                  //print receipt header
                  receipt_.printHeader();
  
                  //print recipt
                  Ordering.printReceipt();
  
                  //print out on receipt if they got a complimentray treat
                  members[u].counterPrint();
                  
                  //print receipt subheader
                  receipt_.printSubHeader();
                }
      
                //if they are editing their membership, call method to edit
                else{
                  //print the header
                  edit_.printHeader();

                  //call method to edit
                  members[u].edit();

                  //print out subheader for editing
                  edit_.printSubHeader();
                }
  
                //update variable
                found = 1;
              }
            }

            //if the membership does not exist
            if (found == 0){

              //tell them the membership they entered does not exists
              cout << "\nMembership not found. ";
              
              //declare variable
              string cont2;
              int cont3 = 0;
              while (cont3 == 0){
                //ask user if they would like to try another membership
                cout << "[yes/no] Would you like to try another membership? ";
  
                //to not ignore getline()
                cin >> ws;
  
                getline(cin, cont2);

                //if they would not like to use a membership, get out of both loops
                if (cont2 == "no" || cont == "No"){
                  found = 1;
                  cont3 = 1;
                }

                //if the command is yes, get out of loop to ask them for their info again
                else if (cont2 == "yes" || cont2 == "Yes")
                  cont3 = 1;

                //if the command is not yes or no, ask them again
                else
                  cout << "Incorrect command entered.\n" << endl;
                
              }
            }
          }
        }
          
        //if they are not a member, print out the receipt
        if (member == "no" || member == "No"){
          //print receipt header
          receipt_.printHeader();
        
          //print recipt
          Ordering.printReceipt();

          //print receipt subheader
          receipt_.printSubHeader();
        }

        else{
          //if the command is not yes or no, ask them again
          cout << "Incorrect command entered.\n" << endl;
        }
      }
  
      //if they want to create a membership
      else if (command == 2){
        //store it in the array by finding a free spot
        for (int i = 0; i < 100; i++){
          //create the membership when an empty spot in the array is found
          if (members[i].returnName() == ""){
            //print creating a membership header
            create_.printHeader();
            
            members[i].create();
            
            //print creating a membership subheader
            create_.printSubHeader();
            
            break;
          }
        }
      }
  
      //if incorrect command entered, throw and exception
      else
        throw e_command();

      //declare variable
      int go = 1;
      
      while (go == 1){
        //ask user if they would like to make another transaction
        cout << "\n[yes/no] Would you like to make another transaction? ";
        
        //ensure geline() is not ignored
        cin >> ws;
  
        //get answer from user
        getline(cin, cont);
  
        cout << endl;

        //verify input
        if (cont == "yes" || cont == "Yes" || cont == "no" || cont == "No")
          go = 0;
          
        else
          cout << "Invalid input, please reenter." << endl;
      }
    }
      
    //catch exception
    catch(e_command &error){
      cout << error.what() << endl << endl;
    } 
  }

  //print exit header
  exit_.printHeader();

  // free the array
  for (int i = 0; i < 100; i++)
    delete &members[i];

  return 0;
};