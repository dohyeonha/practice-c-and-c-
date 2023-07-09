// 20211352 Do Hyeon Ha(하도현)
#include"project.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstring>

using namespace std;

int main(){
	// read input file
	Project Grade;
	Grade.readfile();
	
	// Your Code Here ...
    string command = "1";        // 1e, dd 와 같은 command들을 받기 위해서 string으로 설정.

    cout << "1. Login" << endl;             // 항목 출력.
    cout << "2. Student info" << endl;
    cout << "3. Score Rank" << endl;
    cout << "4. Score statistic" << endl;
    cout << "9. Logout" << endl;
    cout << "0. Terminate" << endl;
    
    while (command != "0"){                     // If you input 0, the program is terminated.
        cout << "Select the command: ";
        cin >> command;
        string Id;
        string Pw;
        
        if (command == "1"){                  // If you input 1, the program executes the log in.
            // If you have already successfully logged in(administrator and nonadministrator) and entered 1, print out the message "You've already logged in."
            if (Grade.getStudent() == -1 ){
                cout << "You've already logged in." << endl;
            }
            else if (Grade.getStudent() == -2){
                cout << "You've already logged in." << endl;
            }
            //  3번 실패하면 (ID 이름 기준) Please contact administrator and reset your password. 출력후 Login Fail. 출력. ->

            if (Grade.getStudent() != -1 && Grade.getStudent() != -2){     // It should not appear if you are already logged in.
                cout << "Student name: ";
                cin >> Id;
                cout << "Password: ";
                cin >> Pw;
                //  잘 했응면 Login Success. 이후 Select command 다시. ㅇㅇㅇ ->
                //  못했으면 Login Fail. 이후 Select command 다시. ㅇㅇㅇ ->
                Grade.login(Id, Pw);
            }
        
            if (Grade.getStudent() == -2){       // Provide commands that you can use if you are approached as an administrator.
                //  관리자 접근.
                // cout << "You login Administator" << endl;
                cout << "[Admin Command]" << endl;
                cout << "5. All data" << endl;
                cout << "6. Modify info" << endl;
                cout << "7. Add student" << endl;
            }
        }
        else if (command == "2"){      // If you input 2, the program executes the student information.
            //  학생 정보와 모든 스코어 출력
            // If you log in student, the program provides the name and all scores.
            if (Grade.getStudent() == -1){  
                Grade.studentinfo();
            }
            else if(Grade.getStudent() == -2){         // If you login administrator, you don't have any score.
                cout << "You are administrator. Please enter another command." << endl;
            }
            else{
                cout << "Please login first." << endl; // If you are not login, print out the message "please login first".
            }
        }
        else if (command == "3"){   // If you input 3, the program executes the student's score ranks.
            // Your rank is... 이후 출력
            // If you login student, the program provides the score ranks.
            if (Grade.getStudent() == -1){
                Grade.scorerank();
            }
            else if (Grade.getStudent() == -2){    // If you login administrator, you don't have any score rank.
                cout << "You are administrator. Please enter another command." << endl;
            }
            else{
                cout << "Please login first." << endl;  // If you are not login, print out the message "please login first".
            }
        }
        else if (command == "4"){           // If you input 4, the program executes the total average and median.
            // 평균이랑 중간값 출력
            Grade.scorestatistic();
        }
        else if (command == "5"){          // If you input 5 and administrator, the program executes the student's all data.
            if (Grade.getStudent() == -2){
                Grade.alldata();
            }
            else{                         // If you are not login administrator, you can't do anything in command 5.
                cout << "You do not have authority." << endl;
            }
        }
        else if (command == "6"){            // If you input 6 and administrator, you can modify the student's information.
            if (Grade.getStudent() == -2){
                Grade.modifyinfo();
            }
            else{                         // If you are not login administrator, you can't do anything in command 6.
                cout << "You do not have authority." << endl;
            }
        }
        else if (command == "7"){         // If you input 7 and administrator, you can add new student and scores.
            if (Grade.getStudent() == -2){
                Grade.addstudent();
            }
            else{                         // If you are not login administrator, you can't do anything in command 7.
                cout << "You do not have authority." << endl;
            }
        }
        else if (command == "9"){       // If you input 9 and already log in, you can log out.
            int st = -5;
            if (Grade.getStudent() == -1 || Grade.getStudent() == -2){
                Grade.setStudent(st);    // 기본 상태로 초기화
                Grade.logout();
            }
            else{                       // If you are not login, print out the message "You are not login.".
                cout << "You are not login." << endl;
            }
        }
        else if (command == "0"){ cout << "";}  // Command 0 means nothing. For prevention of wrong command message.
        else{                                   // If you entered something not applicable, print out the message "Wrong Command.".
            cout << "Wrong Command." << endl;
        }
    }
    return 0;
}
