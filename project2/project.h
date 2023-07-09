#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>
//All parts of codes are freely modifiable.
using namespace std;
struct Info{
    string idlist[20], pwlist[20];
    double HW1[20], HW2[20], PJ1[20], PJ2[20];
	int loginfail[20]; // login fail count (default: 0)
};

void bubbleSort(double [], int);  //  Prototype Bubble sort
void swap(int &, int &);          //  Prototype swap
 
class Project
{
	private:
		// you can add more member variable
		string userid;
		Info info;
		int studentnum=11;
		const string adminid = "admin";
		const string adminpw = "unisteee";
        int student, st;              // Position of successful logged-in student array
	public:
		// read input file. Each data is saved in structure Info.
	    void readfile(){
	        ifstream inFile("input.txt");
            string line;
            
            if(inFile.is_open()){
                for(int i=0; i<studentnum; i++){
                    getline(inFile, line)>> info.idlist[i] >> info.pwlist[i] >> info.HW1[i] >> info.HW2[i] >> info.PJ1[i] >> info.PJ2[i];
                }
            }
            inFile.close();
            for(int i=0;i<studentnum;i++){
                info.loginfail[i]=0;
            }
	    }
	    Project(){                  // 초기화
            student = -5;           // 기본 값
            st = -5;
        }
        void setStudent(int s){   // Set student.
            st = s;
        }
        int getStudent() const{   // Get student.
            return st; 
        }

		// command 1
		void login(string id, string pw){
		    // Your Code Here ...
            int success = 0;                 // If success has been counted, you logged in. If not, login fail.
            
            // 관리자로 접근.
            if ( adminid == id){
                if (adminpw == pw){
                    cout << "Login Success" << endl;
                    success++;
                    st = -2;           // -2 관리자로 로그인한 경우.  / -2 : If you logged in administrator.
                }
            }

            for( int i = 0; i < studentnum; i++){
                if ( info.idlist[i] == id){            // If the input id is correspond to id in the idlist, the program will excute. /입력한 아이디와 아이디리스트에 정보가 같다면,
                    if (info.loginfail[i] < 3){   // Excutes the program if the login fail is under 4. / 로그인 실패가 3번이하일때 실행
                       for ( int j = 0; j < studentnum; j++){
                            if ( info.pwlist[j] == pw){
                                student = i;                  // Save which student successfully logged in if both ID and password match. / 어떤 학생 배열 위치의 학생이 로그인 성공했는지 저장.
                                cout << "Login Success." << endl;
                                success++;
                                st = -1;            // -1 비관리자 로그인. / -1: if you logged in non administrator.(student)
                            }
                        } 
                    }
                    if (student == -5){             // 일치하는 경우가 없었다면, ㄱ
                        info.loginfail[i]++;        // If the password does not match, count info.loginfail to the corresponding ID.
                        if (info.loginfail[i] >= 3){  // If the count ouver 3, print out the message "Please contact administrator and reset your password."
                            cout << "Please contact administrator and reset your password." << endl;
                        }
                        // cout << info.loginfail[i] << endl;
                    }
                }
            }
            if (success == 0){   // If you have never successfully logged in, print out failure message.
                cout << "Login Fail" << endl;
            }
		};

		// command 2
		void studentinfo(){            // print out the student information.
		    // Your Code Here ...
            cout << "Name: " << info.idlist[student] << endl;
            cout << "Homework: " << info.HW1[student] << " " << info.HW2[student] << endl;
            cout << "Project: " << info.PJ1[student] << " " << info.PJ2[student] << endl;
		};
		
		// command 3
		void scorerank(){
		    // Your Code Here ...
            int rank_arr[studentnum];         // An array of ranks
            int k;
            cout << "Your rank is..." << endl;

            for (k = 0; k < 4; k++){         // HW1, HW2, PJ1, PJ2
                for (int i = 0; i < studentnum; i++){
                    rank_arr[i] = 1;          // Default Settings
                    // cout << rank_arr[i] << endl;
                }
                switch (k)
                {
                case 0:
                    for (int i = 0; i < studentnum; i++){      // If your value is small than the other values, your rank changes. Repeat the rest of the cases.
                        if (info.HW1[student] < info.HW1[i]){
                            rank_arr[student]++;
                        }
                    }
                    break;
                case 1:
                    for (int i = 0; i < studentnum; i++){
                        if (info.HW2[student] < info.HW2[i]){
                            rank_arr[student]++;
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < studentnum; i++){
                        if (info.PJ1[student] < info.PJ1[i]){
                            rank_arr[student]++;
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < studentnum; i++){
                        if (info.PJ2[student] < info.PJ2[i]){
                            rank_arr[student]++;
                        }
                    }
                    break;          
                }
                
                if(k < 2){
                    cout << "HW" << k+1 << ": " << rank_arr[student] << endl;
                }
                else{
                    cout << "Project" << k-1 <<": " << rank_arr[student] << endl;
                }
            }
		};
		
		// command 4
		void scorestatistic(){
		    // Your Code Here ...
            cout << "Average scores and median scores are..." << endl;
            int k;

            for (k = 0; k < 4; k++){        // HW1, HW2, PJ1, PJ2
                double sum = 0;                 // variable for average. 평균을 위해서
                double array[studentnum];       // variable for median. 중간값을 위해서
                double average, median;
                switch (k)
                {
                case 0:
                    for(int i = 0; i < studentnum; i++){          // Add all value and devide by total number.  And repeat.
                        sum += info.HW1[i];
                    }
                    average = sum/studentnum;
                    for (int i = 0; i < studentnum; i++){
                        array[i] = info.HW1[i];
                    }
                    bubbleSort(array, studentnum);           // Arrange in order of maginitude.
                    if (studentnum % 2 != 0){                // If odd, 홀수이면
                        median = array[studentnum/2];
                    }
                    else{                                   // If even,
                        median = (array[studentnum/2 - 1]+array[studentnum/2])/2;
                    }
                    break;
                case 1:
                    for(int i = 0; i < studentnum; i++){
                        sum += info.HW2[i];
                    }
                    average = sum/studentnum;
                    for (int i = 0; i < studentnum; i++){
                        array[i] = info.HW2[i];
                    }
                    bubbleSort(array, studentnum);
                    if (studentnum % 2 != 0){                // If odd, 홀수이면
                        median = array[studentnum/2];
                    }
                    else{                                    // If even,
                        median = (array[studentnum/2 - 1]+array[studentnum/2])/2;
                    }
                    break;
                case 2:
                    for(int i = 0; i < studentnum; i++){
                        sum += info.PJ1[i];
                    }
                    average = sum/studentnum;
                    for (int i = 0; i < studentnum; i++){
                        array[i] = info.PJ1[i];
                    }
                    bubbleSort(array, studentnum);
                    if (studentnum % 2 != 0){                // 홀수이면
                        median = array[studentnum/2];
                    }
                    else{
                        median = (array[studentnum/2 - 1]+array[studentnum/2])/2;
                    }
                    break;
                case 3:
                    for(int i = 0; i < studentnum; i++){
                        sum += info.PJ2[i];
                    }
                    average = sum/studentnum;
                    for (int i = 0; i < studentnum; i++){
                        array[i] = info.PJ2[i];
                    }
                    bubbleSort(array, studentnum);
                    if (studentnum % 2 != 0){                // 홀수이면
                        median = array[studentnum/2];
                    }
                    else{
                        median = (array[studentnum/2 - 1]+array[studentnum/2])/2;
                    }
                    break;
                }
                if (k < 2){
                    cout << "HW" << k+1 << ": " << average << ", " << median << endl;
                }
                else{
                    cout << "Project" << k-1 << ": " << average << ", " << median << endl;
                }
                
                
            }
		}; 
		
		// command 5
		void alldata(){                         // Show all data by grammar for.
		    // Your Code Here ...
            cout << "All data: " << endl; 
            for (int i = 0; i < studentnum; i++){
                cout << info.idlist[i] << ": " << info.HW1[i]
                     << " " << info.HW2[i] << " " << info.PJ1[i]
                     << " " << info.PJ2[i] << endl;
            }
		};
		
		// command 6
		void modifyinfo(){
		    // Your Code Here ...
            const int SIZE = 80;
		    char cnewPassword[SIZE];    //  newpassword. The type is char.
            string id, type, newPassword;  // Name, Type of assignment, Newpassword.
            int newScore, location;        // The score you want to change / the student's position.
            int checkUpper = 0;     
            int checkLower = 0;
            int checkNum = 0;
            int checkChar = 0;  // Check for password restrictions.(uppercase, lowercase, numbers, characters) 비밀번호 제한 사항이 있는지 확인.
            cout << "Whose information are you going to modify?: ";
            cin >> id;
            cout << "What information are you going to modify?(password, HW1, HW2, PJ1, PJ2): ";
            cin >> type;
            
            for( int i = 0; i < studentnum; i++){  // Check if the ID is the same and if the ID is the same, enter the information in the location.
                if(info.idlist[i] == id){
                    location = i;
                }
            }
            if (type == "HW1" || type == "HW2" || type == "PJ1" || type == "PJ2"){ // type != "password" If you receive something other than a password. 패스워드가 아닌 다른 경우
                cout << "Enter new score: ";
                cin >> newScore;
                if (type == "HW1"){
                    if ( newScore < 0 || newScore > 20){        // If you go beyond the range, you get 0 points.
                        newScore = 0;
                        cout << "Wrong input." << endl;
                    }
                    else{ cout << "Change complete." << endl;}
                }
                else if (type == "HW2"){
                    if ( newScore < 0 || newScore > 30){        // If you go beyond the range, you get 0 points.
                        newScore = 0;
                        cout << "Wrong input." << endl;
                    }
                    else{ cout << "Change complete." << endl;}
                }
                else if (type == "PJ1" || type == "PJ2"){
                    if ( newScore < 0 || newScore > 100){       // If you go beyond the range, you get 0 points.
                        newScore = 0;
                        cout << "Wrong input." << endl;
                    }
                    else{ cout << "Change complete." << endl;}
                }
                if (type == "HW1"){                    // Changing the score according to the assignment type.
                    info.HW1[location] = newScore;
                }
                else if(type == "HW2"){
                    info.HW2[location] = newScore;
                }
                else if (type == "PJ1"){
                    info.PJ1[location] = newScore;
                }
                else if (type == "PJ2"){
                    info.PJ2[location] = newScore;
                }
            }
            else if (type == "password"){             // When a password has been entered.
                cout << "Enter new password: ";
                getline(cin,newPassword);
                cin.getline(cnewPassword, SIZE);
                newPassword = cnewPassword;

                for (int i = 0; i < strlen(cnewPassword); i++){        // Check Uppercase, lowercase, number, characters 확인.
                    char j;
                    for (j = 65; j < 91; j++){   // Uppercase 확인          1
                        if (newPassword[i] == j){
                            checkUpper++;
                            // cout << "1" <<" "<< checkUpper <<endl;
                        }
                    }
                    for (j = 97; j < 123; j++){   // Lowercase 확인          2
                        if (newPassword[i] == j){
                            checkLower++;
                            // cout << "2" <<" "<< checkLower << endl;
                        }
                    }
                    for (j = 48; j < 58; j++){  // Number 확인              3
                        if (newPassword[i] == j){
                            checkNum++;
                            // cout << "3" <<" " << checkNum << endl;
                        }
                    }
                    for (j = 33; j < 48; j++){  // characters 확인          4
                        if (newPassword[i] == j){
                            checkChar++;
                            // cout << "4" <<" " << checkChar << endl;
                        }
                    }
                    for (j = 58; j < 65; j++){   // characters 확인2          5
                        if (newPassword[i] == j){
                            checkChar++;
                            // cout << "5" <<" " << checkChar << endl;
                        }
                    }
                    for (j = 91; j < 97; j++){     // characters 확인3        6
                        if (newPassword[i] == j){
                            checkChar++;
                            // cout << "6" <<" "<< checkChar << endl;
                        }
                    }
                    for (j = 123; j < 127; j++){    // characters 확인4        7
                        if (newPassword[i] == j){
                            checkChar++;
                            // cout << "7" <<" " << checkChar << endl;
                        }
                    }
                }
                // cout << checkUpper << " " << checkLower << " " << checkNum << " " << checkChar << endl;
                if (checkUpper == 0 || checkLower == 0 || checkNum == 0 || checkChar == 0){  // If none of them were counted, they would not be subject to the restriction
                    cout << "Wrong password" << endl;
                }
                else if (checkUpper != 0 && checkLower !=0 && checkNum != 0 && checkChar != 0){ // Change password if conditions are met
                    
                    info.pwlist[location] = newPassword;       // Change the pw. 비밀번호 변경.
                    info.loginfail[location] = 0;              // Initialize the number of login failures corresponding to the ID. 로그인 실패 횟수 초기화
                    cout << "Change complete" << endl; 
                }
            }
		};
		
		// command 7
		void addstudent(){          // Add student.
		    // Your Code Here ...
            string name, pw;
            double hw1, hw2, pj1, pj2;      // Input the information of new student.
            cout << "Student name: ";      
            cin >> name;
            cout << "Password: ";
            cin >> pw;
            cout << "HW1 score: ";
            cin >> hw1;
            cout << "HW2 score: ";
            cin >> hw2;
            cout << "PJ1 score: ";
            cin >> pj1;
            cout << "PJ2 score: ";
            cin >> pj2;
            if (hw1 < 0 || hw1 > 20){         // If it exceeds the score range, it is calculated as 0 points.
                hw1 = 0;
            }
            if (hw2 < 0 || hw2 > 30){
                hw2 = 0;
            }
            if (pj1 < 0 || pj1> 100){
                pj1 = 0;
            }
            if (pj2 < 0 || pj2> 100){
                pj2 = 0;
            }
            
            info.idlist[studentnum] = name;   // Enter information into the array.
            info.pwlist[studentnum] = pw;
            info.HW1[studentnum] = hw1;
            info.HW2[studentnum] = hw2;
            info.PJ1[studentnum] = pj1;
            info.PJ2[studentnum] = pj2;
            info.loginfail[studentnum] = 0;  // 초기화.
            studentnum += 1;         // student number +1
		};
		
		// command 9
		void logout(){
		    // Your Code Here ...
            student = -5;          // Initialization correspond to logout
            cout << "Logout complete" << endl;
		};
		// you can implement additional function
};

void bubbleSort(double arr[], int size){
    int maxElement;
    int index;

    for (maxElement = size-1; maxElement > 0; maxElement--){
        for (index = 0; index < maxElement; index++){
            if (arr[index] > arr[index+1]){            // If the value is bigger than another value, change the location.
                swap(arr[index], arr[index+1]);
            }
        }
    }
}

void swap(int &a, int &b){   // The Function of changing the order.
    int temp = a;
    a = b;
    b = temp;
}

#endif